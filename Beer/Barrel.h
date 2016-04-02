#pragma once

#include <memory>

#include "Beer.h"
#include "BeerBuilders\BeerBuilder.h"
#include "..\Resources\ResourcesStorage.h"

namespace Brewery
{
    namespace Beer
    {
        class Barrel
        {
            std::shared_ptr<BeerBuilders::BeerBuilder> beer_builder;

        public:
            Barrel() : beer_builder(nullptr) {}
            ~Barrel() {}

            void setBeerBuilder(
                _In_ std::shared_ptr<BeerBuilders::BeerBuilder> b) noexcept;

            _Ret_ std::shared_ptr<Beer> getBeer() const noexcept;

            void brewBeer(
                _In_ Resources::ResourcesStorage &resources);
        };
    }
}