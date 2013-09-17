/* http://www.codeproject.com/Articles/69941/Best-Square-Root-Method-Algorithm-Function-Precisi*/

#include<stdio.h>

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

void main() {
    float cout1, cout2, cin = 3;

    cout1 = sqrt1(cin);
    cout2 = sqrt2(cin);

    printf("%f %f \n", cout1, cout2);
}