#include <iostream>
#include <sal.h>

// stupid throw()... Nobody really need them
#pragma warning( disable : 4290 )

#include "Brewery.h"

_Success_(return == EXIT_SUCCESS)
int main(
    _In_ int argc, 
    _In_ char **argv, 
    _In_ char **envp)
{
    auto& brewery = Brewery::Brewery::Instance();
    try
    {
        brewery.interact();
    }
    catch (const std::exception& exc)
    {
        std::cerr << exc.what();
    }
    return EXIT_SUCCESS;
}
