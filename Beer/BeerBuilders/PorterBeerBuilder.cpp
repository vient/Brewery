#include "PorterBeerBuilder.h"

Brewery::Beer::BeerBuilders::PorterBeerBuilder::PorterBeerBuilder()
{
    setName("Porter");
}

void Brewery::Beer::BeerBuilders::PorterBeerBuilder::setIngredients() noexcept
{
    beer->addIngredient("water", 5);
    beer->addIngredient("starch", 2);
    beer->addIngredient("hops", 1);
    beer->addIngredient("yeast", 12);
    beer->setCost(200);
}