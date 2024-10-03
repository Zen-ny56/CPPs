#include "Generate.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base* base = NULL; // For testing, this will create an instance of B
    // identify(base);       // Output should be "B"
    identify(*base);      // Output should be "B" using reference

    delete base;
    return 0;
}