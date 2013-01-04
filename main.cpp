#include "PageRank.h"
#include <iostream>
#include <string>
#include <vector>

int
main( void )
{
// keeping track of the list of websites
    std::vector<std::string> webList;
    webList.push_back ( "websiteOne.com" );
    webList.push_back ( "websiteTwo.com" );
    webList.push_back ( "websiteThree.com" );

    // pass the list to singleton, it doesn't make a new copy
    PageRank::instance().setList( webList );

    // perform the necessary computation to determine the rank
    // currently, this list is not used; a placeholder connectivity
    // matrix is used until a way to generate the matrix based on
    // the list is implemented
    PageRank::instance().compute();

    // access the computed list
    // not really the best implementation, but fine for now
    std::vector<std::string> newList;
    newList = PageRank::instance().computedList();

    // print the list
    std::vector<std::string>::iterator it;
    
    for( it = newList.begin(); it != newList.end(); ++it ) {
        std::cout << *it << std::endl;
    }

}
