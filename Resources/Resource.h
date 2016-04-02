#pragma once

#include <exception>
#include <string>
#include <sal.h>

namespace Brewery
{
    namespace Resources
    {
        class Resource
        {
            std::string name;
            size_t amount;
            size_t cost;

        public:
            class LackOfResourceException : public std::exception
            {
                std::string errMessage;

            public:
                _Ret_z_ virtual const char* what() const noexcept;

                void setType(
                    _In_z_ const char *_type) noexcept;
            } lackOfResourceException;

            Resource() : amount(0) {}

            _Ret_ const std::string& getName() const noexcept;

            void setName(
                _In_z_ const char *type) noexcept;

            _Ret_ size_t getCost() const noexcept;

            void setCost(
                _In_ const size_t _cost) noexcept;

            _Ret_ size_t getAmount() const noexcept;

            template<typename T>
            auto operator+=(
                _In_ T num) noexcept
            {
                amount += num;
                return *this;
            }

            template<typename T>
            auto operator-=(
                _In_ T num)
            {
                if (amount < static_cast<size_t>(num))
                    throw lackOfResourceException;
                amount -= num;
                return *this;
            }
        };
    }
}