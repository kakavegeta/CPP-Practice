#include <iostream>
#include "DisjSets.hpp"

// Test main; all finds on same output line should be identical
int main( )
{
    int numElements = 128;
    int numInSameSet = 16;

    DisjSets ds{ numElements };
    int set1, set2;

    for( int k = 1; k < numInSameSet; k *= 2 )
    {
        for( int j = 0; j + k < numElements; j += 2 * k )
        {
            set1 = ds.find( j );
            set2 = ds.find( j + k );
            ds.union_sets( set1, set2 );
        }
    }

    for( int i = 0; i < numElements; ++i )
    {
        std::cout << ds.find( i ) << "*";
        if( i % numInSameSet == numInSameSet - 1 )
            std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}