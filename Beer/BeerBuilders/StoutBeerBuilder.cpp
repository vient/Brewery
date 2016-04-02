#include "StoutBeerBuilder.h"

Brewery::Beer::BeerBuilders::StoutBeerBuilder::StoutBeerBuilder()
{
    setName("Stout");
}

void Brewery::Beer::BeerBuilders::StoutBeerBuilder::setIngredients() noexcept
{
    beer->addIngredient("water", 5);
    beer->addIngredient("starch", 3);
    beer->addIngredient("hops", 3);
    beer->addIngredient("yeast", 27);
    beer->setCost(180);
}