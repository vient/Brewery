#include "ResourcesStorage.h"

// Brewery::Resources::Resources::NonExistingResourceException
_Ret_z_ const char* Brewery::Resources::ResourcesStorage::NonExistingResourceException::what() const noexcept
{
    return "resource doesn't exist";
}

// Brewery::Resources::Resources::LackOfMoneyException
_Ret_z_ const char* Brewery::Resources::ResourcesStorage::LackOfMoneyException::what() const noexcept
{
    return "not enough cash to buy resources";
}

// Brewery::Resources::ResourcesStorage
Brewery::Resources::ResourcesStorage::ResourcesStorage() : cash(0)
{
    auto AddNewResource = [this](const char *type, const size_t cost) -> auto
    {
        auto temp = Resource();
        temp.setName(type);
        temp.setCost(cost);
        resources[std::string(type)] = temp;
    };
    AddNewResource("water", 1);
    AddNewResource("starch", 5);
    AddNewResource("hops", 10);
    AddNewResource("yeast", 2);
}

void Brewery::Resources::ResourcesStorage::addCash(
    _In_ size_t income) noexcept
{
    cash += income;
}

_Ret_ const size_t Brewery::Resources::ResourcesStorage::getCash() const noexcept
{
    return cash;
}

_Ret_ Brewery::Resources::Resource& Brewery::Resources::ResourcesStorage::getResource(
    _In_z_ const char *name) throw(NonExistingResourceException)
{
    try
    {
        return resources.at(std::string(name));
    }
    catch (std::out_of_range)
    {
        throw nonExistingResourceException;
    }
}

_Ret_ Brewery::Resources::Resource& Brewery::Resources::ResourcesStorage::getResource(
    _In_ const std::string &name) throw(NonExistingResourceException)
{
    return getResource(name.c_str());
}

void Brewery::Resources::ResourcesStorage::buyResource(
    _In_ const size_t amount,
    _In_ Brewery::Resources::Resource &resource)
{
    auto needed_cash = amount * resource.getCost();
    if (needed_cash > cash)
        throw lackOfMoneyException;
    cash -= needed_cash;
    resource += amount;
}

void Brewery::Resources::ResourcesStorage::processResourcesList(
    _In_ const ResourcesList &list) throw(LackOfMoneyException)
{
    for (auto &item : list)
    {
        auto& res = getResource(item.first);
        try
        {
            res -= item.second;
        }
        catch (Resource::LackOfResourceException)
        {
            auto to_buy = item.second - res.getAmount();
            buyResource(to_buy, res);
            res -= item.second;
        }
    }
}

_Ret_ decltype(Brewery::Resources::ResourcesStorage::resources.cbegin()) Brewery::Resources::ResourcesStorage::begin() const noexcept
{
    return resources.cbegin();
}

_Ret_ decltype(Brewery::Resources::ResourcesStorage::resources.cend()) Brewery::Resources::ResourcesStorage::end() const noexcept
{
    return resources.cend();
}

_Ret_ const size_t Brewery::Resources::ResourcesStorage::size() const noexcept
{
    return resources.size();
}