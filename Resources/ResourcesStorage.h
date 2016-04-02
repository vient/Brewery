#pragma once

#include <exception>
#include <map>
#include <sal.h>

#include "Resource.h"
#include "ResourcesList.h"

namespace Brewery
{
    namespace Resources
    {
        // Copying is not allowed
        class ResourcesStorage
        {
            std::map<std::string, Resource> resources;
            size_t cash;

            ResourcesStorage(ResourcesStorage const&) {}
            ResourcesStorage& operator=(ResourcesStorage const&) {}

        public:
            class NonExistingResourceException : public std::exception
            {
                _Ret_z_ virtual const char* what() const noexcept;
            } nonExistingResourceException;

            class LackOfMoneyException : public std::exception
            {
                _Ret_z_ virtual const char* what() const noexcept;
            } lackOfMoneyException;

            ResourcesStorage();
            ~ResourcesStorage() {}

            void addCash(
                _In_ size_t income) noexcept;

            _Ret_ const size_t getCash() const noexcept;

            _Ret_ Resource& getResource(
                _In_z_ const char *name) throw(NonExistingResourceException);

            _Ret_ Resource& getResource(
                _In_ const std::string &name) throw(NonExistingResourceException);

            void buyResource(
                _In_ const size_t amount,
                _In_ Resource &resource) throw(LackOfMoneyException);

            void processResourcesList(
                _In_ const ResourcesList &list) throw(LackOfMoneyException);

            // restrict range-based loops from changing elements
            _Ret_ decltype(resources.cbegin()) begin() const noexcept;
            _Ret_ decltype(resources.cend()) end() const noexcept;

            _Ret_ const size_t size() const noexcept;
        };
    }
}
