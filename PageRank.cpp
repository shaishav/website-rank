#include "PageRank.h"
#include <assert.h>

/*
 * PageRank class implementatino
 */

// constructor with a default alpha value
PageRank::
PageRank( float alpha = 0.15 ): m_alpha( alpha )
{
}

PageRank::
~PageRank()
{
}

float PageRank::
alpha( )
{
    return m_alpha;
}

void PageRank::
setAlpha( float factor )
{
    assert( factor > 0.0 && factor < 1.0 );
    m_alpha = factor;
}

PageRank& PageRank::
instance()
{
    static PageRank m_instance;
    return m_instance;
}

void PageRank::
setList( std::vector<std::string>& websites )
{
    m_origList = websites;
}

void PageRank::
compute()
{
    m_compList = m_origList;
}

std::vector<std::string> PageRank::
computedList()
{
    return m_compList;
}
