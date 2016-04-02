#pragma once

#include "BeerBuilder.h"

namespace Brewery
{
    namespace Beer
    {
        namespace BeerBuilders
        {
            class AleBeerBuilder : public BeerBuilder
            {
            public:
                AleBeerBuilder();
                ~AleBeerBuilder() {}

                void setIngredients() noexcept;
            };
        }
    }
}