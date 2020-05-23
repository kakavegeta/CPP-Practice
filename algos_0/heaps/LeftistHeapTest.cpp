#include "LeftistHeap.hpp"
#include <iostream>
using namespace std;

int main( )
{
    int numItems = 100000;
    LeftistHeap<int> h;
    LeftistHeap<int> h1;
    LeftistHeap<int> h2;
    int i = 37;

    cout << "Begin test..." << endl;
    for( i = 37; i != 0; i = ( i + 37 ) % numItems )
        if( i % 2 == 0 )
            h1.insert( i );
        else
            h2.insert( i );
    h2.merge( h1 );
    h = h2;

    for( i = 1; i < numItems; ++i )
    {
        int x;
        h2.delete_min( x );
        if( x != i )
            cout << "Oops! " << i << endl;
    }

    if( !h1.is_empty( ) )
        cout << "Oops! h1 should have been empty!" << endl;

    cout << "End test... no other output is good" << endl;

    return 0;
}