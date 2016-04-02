#pragma once

#include "BeerBuilder.h"

namespace Brewery
{
    namespace Beer
    {
        namespace BeerBuilders
        {
            class PorterBeerBuilder : public BeerBuilder
            {
            public:
                PorterBeerBuilder();
                ~PorterBeerBuilder() {}

                void setIngredients() noexcept;
            };
        }
    }
}