#include "Resource.h"

// Brewery::Resources::Resource::LackOfResourceException
_Ret_z_ const char* Brewery::Resources::Resource::LackOfResourceException::what() const noexcept
{
    return errMessage.c_str();
}

void Brewery::Resources::Resource::LackOfResourceException::setType(
    _In_z_ const char *_type) noexcept
{
    errMessage = std::string("not enough resource: ") + std::string(_type);
}

// Brewery::Resources::Resource
_Ret_ const std::string& Brewery::Resources::Resource::getName() const noexcept
{
    return name;
}

void Brewery::Resources::Resource::setName(
    _In_z_ const char *type) noexcept
{
    name = std::string(type);
    lackOfResourceException.setType(type);
}

_Ret_ size_t Brewery::Resources::Resource::getCost() const noexcept
{
    return cost;
}

void Brewery::Resources::Resource::setCost(
    _In_ const size_t _cost) noexcept
{
    cost = _cost;
}

_Ret_ size_t Brewery::Resources::Resource::getAmount() const noexcept
{
    return amount;
}