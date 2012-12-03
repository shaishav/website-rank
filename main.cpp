#include "PageRank.h"
#include <iostream>
#include <string>

int
main( void )
{
    std::cout << PageRank::instance().alpha() << std::endl;
}
