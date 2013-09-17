/* http://www.codeproject.com/Articles/69941/Best-Square-Root-Method-Algorithm-Function-Precisi*/

#include<stdio.h>

/* float Q_rsqrt( float number ) */
/* { */
/*     long i; */
/*     float x2, y; */
/*     const float threehalfs = 1.5F; */

/*     x2 = number * 0.5F; */
/*     y  = number; */
/*     i  = * ( long * ) &y;                       // evil floating point bit level hacking（对浮点数的邪恶位级hack） */
/*     i  = 0x5f3759df - ( i >> 1 );               // what the fuck?（这他妈的是怎么回事？） */
/*     y  = * ( float * ) &i; */
/*     y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration （第一次牛顿迭代） */
/*     //      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed（第二次迭代，可以删除） */

/*     return y; */
/* } */

float sqrt1(const float x)
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

void main() {
    float cout, cin = 3;

    cout = sqrt1(cin);

    printf("%f", cout);
}