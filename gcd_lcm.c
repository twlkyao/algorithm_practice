/* http://baike.baidu.com/view/341375.htm#3*/

#include <stdio.h>

int GCD(int a, int b);
int LCM(int a, int b);

int main()
{
    int num1, num2, gcd, lcm;

    printf("求两个数的最大公约数及最小公倍数 \n\n请输入你想计算的两个数：\n");
    scanf("%d%d", &num1,  &num2);

    gcd = GCD(num1, num2);
    lcm = LCM(num1, num2);

    printf("最大公约数为：%d \n最小公倍数为：%d\n", gcd, lcm);
}

int GCD(int num1, int num2) {
    if ( num1 % num2 == 0)
        return num2;
    else
        return GCD( num2, num1 % num2);
}

int LCM(int a, int b)
{
    int temp_lcm;
    temp_lcm = a * b / GCD(a, b); //最小公倍数等于两数之积除以最大公约数
    return temp_lcm;
}