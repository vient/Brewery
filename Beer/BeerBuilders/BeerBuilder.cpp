#include "BeerBuilder.h"

void Brewery::Beer::BeerBuilders::BeerBuilder::setName(
    _In_ const std::string &_name) noexcept
{
    name = _name;
}

_Ret_ const std::string Brewery::Beer::BeerBuilders::BeerBuilder::getName() const noexcept
{
    return name;
}

_Ret_ std::shared_ptr<Brewery::Beer::Beer> Brewery::Beer::BeerBuilders::BeerBuilder::getBeer() const noexcept
{
    return beer;
}

void Brewery::Beer::BeerBuilders::BeerBuilder::createNewBeer()
{
    beer.reset(new Beer);
}
