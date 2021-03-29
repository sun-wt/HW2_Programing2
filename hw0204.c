#include <stdio.h>
#include <stdint.h>
#include "bignum.h"


void print( const sBigNum num );
int32_t set( sBigNum *pNum, char *str );
int32_t compare( const sBigNum num01 , const sBigNum num02 );
int32_t digits( const sBigNum num );
void add( sBigNum *pResult ,const sBigNum num01 ,const sBigNum num02 );
void subtract( sBigNum *pResult , const sBigNum num01 , const sBigNum num02 );
void multiply( sBigNum *pResult , const sBigNum num01 , const sBigNum num02 );
void divide( sBigNum *pQuotient , sBigNum *pRemainder , const sBigNum num01 , const sBigNum num02 );
int32_t power( sBigNum *pResult , int32_t n, int32_t k );
int32_t combine( sBigNum *pResult , int32_t n, int32_t k );


int main()
{
    sBigNum a,b;
    set(&a,"50");
    set(&b,"5");
    print(a);
    print(b);
    /*if( compare( a, b ) == 1 )
    {
        printf( "Comparison Pass.\n" );
    }
    else
    {
        printf( "Comparison Fail.\n" );
    }
    
    if( digits( a ) == 3 )
    {
        printf( "Digits Pass.\n" );
    }
    else
    {
        printf( "Digits Fail.\n" );
    }*/
    sBigNum ans, q, r;
    add( &ans, a, b );
    //print(ans);
    subtract( &ans, a, b );
    //print(ans);
    multiply( &ans, a, b );
    //print(ans);
    power( &ans, 2, 3 );
    print(ans);
    divide( &q , &r , a , b);
    //print(q);
    //print(r);
    combine(&ans,20,10);
    return 0;
}

