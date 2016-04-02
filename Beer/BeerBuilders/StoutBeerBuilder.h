#pragma once

#include "BeerBuilder.h"

namespace Brewery
{
    namespace Beer
    {
        namespace BeerBuilders
        {
            class StoutBeerBuilder : public BeerBuilder
            {
            public:
                StoutBeerBuilder();
                ~StoutBeerBuilder() {}

                void setIngredients() noexcept;
            };
        }
    }
}