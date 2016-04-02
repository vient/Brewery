#pragma once

#include <vector>
#include <sal.h>

#include "..\Resources\ResourcesList.h"

namespace Brewery
{
    namespace Beer
    {
        class Beer
        {
            Resources::ResourcesList ingredients;
            size_t cost;

        public:
            Beer() {}
            ~Beer() {}

            void addIngredient(
                _In_z_ const char *name,
                _In_ size_t count);

            _Ret_ const Resources::ResourcesList& getResourcesList() const noexcept;

            void setCost(
                _In_ const size_t _cost) noexcept;

            _Ret_ const size_t getCost() const noexcept;

            void Brew() {}      // .TODO add recipes in next version
        };
    }
}