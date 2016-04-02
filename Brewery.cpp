#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <memory>
#include <time.h>

#include <Windows.h>

#include "Brewery.h"
#include "Beer\Barrel.h"
#include "Beer\BeerBuilders.h"

// Brewery::Brewery::BancruptcyException
_Ret_z_ const char* Brewery::Brewery::BancruptcyException::what() const noexcept
{
    return "no cash left in bank";
}

// Brewery::Brewery (very informative...)
Brewery::Brewery::Brewery()
{
    resources.addCash(1000);
    beer_types.push_back(std::make_shared<Beer::BeerBuilders::AleBeerBuilder>());
    beer_types.push_back(std::make_shared<Beer::BeerBuilders::PorterBeerBuilder>());
    beer_types.push_back(std::make_shared<Beer::BeerBuilders::StoutBeerBuilder>());
}

void Brewery::Brewery::makeBeer(
    _In_ std::shared_ptr<Beer::BeerBuilders::BeerBuilder> &beerBuilder) throw(Brewery::BancruptcyException)
{
    static Beer::Barrel barrel;                         // Just one barrel for all? Seems legit.
    barrel.setBeerBuilder(beerBuilder);
    try
    {
        barrel.brewBeer(resources);
    }
    catch (Resources::ResourcesStorage::LackOfMoneyException)
    {
        throw bancruptcyException;
    }
    resources.addCash(barrel.getBeer()->getCost());     // sweet money
}

void Brewery::Brewery::interact()
{
    static const std::vector<std::string> cheering_phrases = {
        "Good choice!",
        "I'd take it myself!",
        "Yep, dat one is the best",
        "Nice!",
        "It's my favourite too!",
        "Good taste!",
    };
    auto Cheer = []() -> auto
    {
        static std::mt19937 RD(time(0));
        size_t index = RD() % cheering_phrases.size();
        std::cout << cheering_phrases[index] << std::endl;
    };

    size_t option;
    auto res_it = resources.begin();
    while (true)
    {
        system("cls");
        std::cout <<
            "Choose an option:\n"
            "1 - Buy a beer\n"
            "2 - See resources\n"
            "3 - Buy resources\n"
            "0 - Exit" << std::endl;
        std::cin >> option;
        switch (option)
        {
        case 1:
            std::cout << "Choose a beer:\n";
            for (size_t i = 0; i < beer_types.size(); ++i)
                std::cout << i + 1 << " - " << beer_types[i]->getName() << std::endl;
            std::cin >> option;
            if (option == 0 || option > beer_types.size())
            {
                std::cout << "Try another one!" << std::endl;
                break;
            }
            Cheer();
            try
            {
                makeBeer(beer_types[option - 1]);
            }
            catch (Brewery::BancruptcyException)
            {
                std::cout << "Seems that out small brewery has run out of money :'(\nSee you soon!" << std::endl;
                std::cin.get();
                std::cin.get();
                exit(0);
            }
            Sleep(1000);
            std::cout << "Here it is! Specially 4 u ;)" << std::endl;
            break;
        case 2:
            std::cout << "Cash: " << resources.getCash() << std::endl;
            for (const auto &resource : resources)
            {
                auto &res = resources.getResource(resource.first);
                std::cout << res.getName() << ": " << res.getAmount() << std::endl;
            }
            break;
        case 3:
            std::cout << "Which resource do you want to buy?" << std::endl;
            res_it = resources.begin();
            for (size_t i = 1; i <= resources.size(); ++i, ++res_it)
                std::cout << i << " - " << res_it->first << std::endl;
            std::cin >> option;
            if (option == 0 || option > resources.size())
            {
                std::cout << "Try another one!" << std::endl;
                break;
            }
            res_it = resources.begin();
            for (size_t i = 0; i < option - 1; ++i, ++res_it);
            std::cout << "How much do you want?" << std::endl;
            std::cin >> option;
            try
            {
                resources.buyResource(option, const_cast<Resources::Resource&>(res_it->second));
            }
            catch (Resources::ResourcesStorage::LackOfMoneyException)
            {
                std::cout << "Sorry, you have not that much money" << std::endl;
            }
            std::cout << "Success!" << std::endl;
            break;
        case 0:
            std::cout << "Bye-bye!" << std::endl;
            Sleep(1500);
            exit(0);
        default:
            std::cout << "Unrecognized option. Try again.";
            break;
        }
        std::cin.get();
        std::cin.get();
    }
}