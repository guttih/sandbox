// A simple program that computes the square root of a number
#include <cmath>
// #include <cstdlib>
#include <iostream>
#include <string>
#include "classerConfig.h"
#ifdef USE_MYMATH
  #include "MathFunctions.h"
#endif
#ifdef USE_PEOPLE
#include "Person.cpp"
#endif
// #include "person.h"
// https://gitlab.kitware.com/cmake/cmake/-/blob/master/Help/guide/tutorial/Step1/tutorial.cxx
int main( int argc, char *argv[] )
{

#ifdef USE_PEOPLE
    Person john( 50 );
#else
#endif

    if( argc < 2 )
    {
        std::cout << VERSION_DISPLAY_NAME << " ";
        std::cout << classer_VERSION_MAJOR << "." << classer_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[ 0 ] << " number" << std::endl;

#ifdef USE_PEOPLE
        std::cout << "Person john was declared and he is " << john.getAge() << " years old." << std::endl;
#else
        std::cout << "Not using People" << std::endl;
#endif
#ifdef USE_MYMATH
        std::cout << "using myMath" << std::endl;
#else
        std::cout << "Not using myMath" << std::endl;
#endif
        return 1;
    }

    // convert input to double
    const double inputValue = std::stod( argv[ 1 ] );

    // which square root function should we use?
#ifdef USE_MYMATH
    const double outputValue = mysqrt( inputValue );
#else
    const double outputValue = sqrt( inputValue );
#endif

    std::cout << "The square root of " << inputValue << " is " << outputValue
    << std::endl;
    return 0;


    return 0;
}
