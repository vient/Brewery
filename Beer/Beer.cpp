#include "Beer.h"

void Brewery::Beer::Beer::addIngredient(
    _In_z_ const char *name,
    _In_ size_t count)
{
    ingredients.emplace_back(std::string(name), count);
}

_Ret_ const Brewery::Resources::ResourcesList& Brewery::Beer::Beer::getResourcesList() const noexcept
{
    return ingredients;
}

void Brewery::Beer::Beer::setCost(
    _In_ const size_t _cost) noexcept
{
    cost = _cost;
}

_Ret_ const size_t Brewery::Beer::Beer::getCost() const noexcept
{
    return cost;
}