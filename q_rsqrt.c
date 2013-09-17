/* http://www.codeproject.com/Articles/69941/Best-Square-Root-Method-Algorithm-Function-Precisi*/

#include<stdio.h>
#include <stdlib.h>
#include <math.h>

#define ACCURACY 0.0001

// Log base 2 approximation and Newton's Method
float sqrt1(const float x)
{
    union
    {
        int i;
        float x;
    } u;

    u.x = x;
    u.i = (1<<29) + (u.i >> 1) - (1<<22);
    return u.x;
}

// Babylonian Method + some manipulations on IEEE 32 bit floating point representation
float sqrt2(const float x)
{
    union
    {
        int i;
        float x;
    } u;
    u.x = x;
    u.i = (1<<29) + (u.i >> 1) - (1<<22);

    // Two Babylonian Steps (simplified from:)
    // u.x = 0.5f * (u.x + x/u.x);
    // u.x = 0.5f * (u.x + x/u.x);
    u.x =       u.x + x/u.x;
    u.x = 0.25f*u.x + x/u.x;

    return u.x;
}

// Newton's Approximation Method
double sqrt3( unsigned long N )
 {
     double n, p, low, high;
     if( 2 > N )
         return( N );
     low  = 0;
     high = N;
     while( high > low + 1 )
     {
         n = (high + low) / 2;
         p = n * n;
         if( N < p )
             high = n;
         else if( N > p )
             low = n;
         else
             break;
     }
     return( N == p ? n : low );
 }

// Binary Method http://blog.csdn.net/wzy_1988/article/details/11758049
double sqrt4(double n)  
{  
    double low, high, mid, tmp;  
  
    // 获取上下界  
    if (n > 1)   {  
        low = 1;  
        high = n;  
    } else {  
        low = n;  
        high = 1;  
    }  
  
    // 二分法求开方  
    while (low <= high) {  
        mid = (low + high) / 2.000;  
  
        tmp = mid * mid;  
  
if (tmp - n <= ACCURACY && tmp - n >= ACCURACY * -1) {  
            return mid;  
        } else if (tmp > n) {  
            high = mid;  
        } else {  
            low = mid;  
        }  
    }  

    return -1.000;  
}

void main() {
    float cin = 3;
    float cout1, cout2, cout3, cout4;

    cout1 = sqrt1(cin);
    cout2 = sqrt2(cin);
    cout3 = sqrt3(cin);
    cout4 = sqrt4(cin);

    printf("%f %f %f %f\n", cout1, cout2, cout3, cout4);
}