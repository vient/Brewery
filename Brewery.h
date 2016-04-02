#pragma once

#include <exception>
#include <vector>
#include <sal.h>

#include "Resources\ResourcesStorage.h"
#include "Beer\BeerBuilders\BeerBuilder.h"

namespace Brewery
{
    class Brewery
    {
        class BancruptcyException : public std::exception
        {
            _Ret_z_ virtual const char* what() const noexcept;
        } bancruptcyException;

        std::vector<std::shared_ptr<Beer::BeerBuilders::BeerBuilder>> beer_types;
        size_t cash;
        Resources::ResourcesStorage resources;

        Brewery();
        Brewery(const Brewery&) {}
        Brewery& operator=(const Brewery&) {}

        ~Brewery() {}

    public:
        _Ret_ static Brewery& Instance() noexcept
        {
            static Brewery instance;
            return instance;
        }

        void makeBeer(
            _In_ std::shared_ptr<Beer::BeerBuilders::BeerBuilder> &beerBuilder);

        void interact();
    };
}