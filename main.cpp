#include "PageRank.h"
#include <iostream>
#include <string>
#include <vector>

int
main( void )
{
    std::cout << PageRank::instance().alpha() << std::endl;
    PageRank::instance().setAlpha( 0.35 );
    std::cout << PageRank::instance().alpha() << std::endl;

    std::vector<std::string> webList;
    webList.push_back ( "google.com" );
    webList.push_back ( "nba.com" );
    webList.push_back ( "facebook.com" );

    PageRank::instance().setList( webList );
    PageRank::instance().compute();
    std::vector<std::string> newList;
    newList = PageRank::instance().computedList();

    std::vector<std::string>::iterator it;
    
    for( it = newList.begin(); it != newList.end(); ++it ) {
        std::cout << *it << std::endl;
    }

}
