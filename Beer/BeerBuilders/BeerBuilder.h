#pragma once

#include <string>
#include <memory>

#include "..\Beer.h"

namespace Brewery
{
    namespace Beer
    {
        namespace BeerBuilders
        {
            class BeerBuilder
            {
                std::string name;

            protected:
                std::shared_ptr<Beer> beer;

                void setName(
                    _In_ const std::string &_name) noexcept;

            public:
                BeerBuilder() {}
                BeerBuilder(const char *name) : name(name) {}
                virtual ~BeerBuilder() {}

                _Ret_ const std::string getName() const noexcept;

                _Ret_ std::shared_ptr<Beer> getBeer() const noexcept;

                void createNewBeer();

                virtual void setIngredients() = 0;
            };
        }
    }
}