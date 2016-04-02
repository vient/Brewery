#include "AleBeerBuilder.h"

Brewery::Beer::BeerBuilders::AleBeerBuilder::AleBeerBuilder()
{
    setName("Ale");
}

void Brewery::Beer::BeerBuilders::AleBeerBuilder::setIngredients() noexcept
{
    beer->addIngredient("water", 5);
    beer->addIngredient("starch", 1);
    beer->addIngredient("hops", 2);
    beer->addIngredient("yeast", 34);
    beer->setCost(150);
}