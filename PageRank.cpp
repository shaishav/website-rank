#include "PageRank.h"
#include <assert.h>
#include <armadillo>

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
    // let's take a sample connectivity matrix for the time being
    // until there's an implementation for a web crawler in place to generate
    // this thing
    arma::mat connectivityMatrix;
    connectivityMatrix << 1 << 0 << 1 << arma::endr
        << 0 << 1 << 0 << arma::endr
        << 1 << 1 << 1 << arma::endr;

    std::cout << "alpha:\n" << m_alpha << std::endl;
    std::cout << "connectivity matrix:\n" << connectivityMatrix << std::endl;

    arma::mat degMatrix = arma::sum( connectivityMatrix, 0 );
    
    std::cout << "degree matrix:\n" << degMatrix << std::endl;

    // need to calculate matrix P, where P = GD ( G = connectivity matrix, D = diagonal mat )
    int R = std::max( degMatrix.n_rows, degMatrix.n_cols );
    arma::mat e( R, 1 ); 
    e.ones();

    std::cout << "e vector:\n" << e << std::endl;


    arma::mat p_zero = e / R;
    arma::mat p_old = p_zero;
    std::cout << "p_zero matrix:\n" << p_zero << std::endl;
    std::cout << "p_old matrix:\n" << p_old << std::endl;

    arma::mat d_temp = degMatrix;

    for( unsigned int i = 0; i < d_temp.n_elem; ++i ) {
        d_temp( i ) = ( degMatrix( i ) == 0 );
    }

    arma::mat d = d_temp.st();
    std::cout << "d column vector:\n" << d << std::endl;

    for( unsigned int i = 0; i < degMatrix.n_elem; ++i ) {
        if( degMatrix(i) == 0 ) {
            degMatrix(i) = 1;
        }
    }

    // solve for D
    arma::mat D = degMatrix;
    arma::mat D_ones = D;
    D_ones.ones();
    D = D_ones / D;


    // main diagonal
    D = arma::diagmat( D );

    std::cout << "D matrix:\n" << D << std::endl;

    // tolerance level
    float tol = 1.0e-8;

    // calculate matrix P
    arma::mat P = connectivityMatrix * D;


    int numIterations = 0;

    arma::mat p_new;

    while( true ) {
        p_new = m_alpha * ( P * p_old + e * ( ( d.t() * p_old ) / R ) ) + ( 1 - m_alpha ) * e/R;  

        numIterations++;

        if( norm( p_new-p_old, "inf" ) < tol ) {
            break;
        }

        p_old = p_new;
     }

    computed_matrix = p_new;

    std::cout << "computed matrix: " << computed_matrix << std::endl;

    return;
}

std::vector<std::string> PageRank::
computedList()
{
    return m_compList;
}
