#include "Barrel.h"

void Brewery::Beer::Barrel::setBeerBuilder(
    _In_ std::shared_ptr<BeerBuilders::BeerBuilder> b) noexcept
{
    beer_builder = b;
}

_Ret_ std::shared_ptr<Brewery::Beer::Beer> Brewery::Beer::Barrel::getBeer() const noexcept
{
    return beer_builder->getBeer();
}

void Brewery::Beer::Barrel::brewBeer(
    _In_ Resources::ResourcesStorage &resources)
{
    beer_builder->createNewBeer();
    beer_builder->setIngredients();
    resources.processResourcesList(beer_builder->getBeer()->getResourcesList());
}