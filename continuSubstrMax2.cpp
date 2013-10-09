/*
Description: 求一个字符串中连续出现次数最多的子串.

链接：http://blog.csdn.net/ysu108/article/details/7795479

基本算法描述:
这个题目不是编程珠玑上看到的，但是解法用到的数据结构在编程珠玑上有讲到，先归类到这里。
求一个字符串中连续出现的次数最多的子串。例如字符串“abababc”,最多连续出现的为ab，连续出现三次。要和求一个字符串中的最长重复子串区分开来，还是上面的字符串，那么最长的重复子串为abab。两个题目的解法有些类似，都用到了后缀数组这个数据结构。求一个字符串中连续出现的次数最多的子串，首先生成后缀数组例如上面的字符串为:
abababc
bababc
ababc
babc
abc
bc
c
可以看出第一个后缀数组和第三个后缀数组的起始都为ab，第5个后缀数组也为ab。可以看出规律来，一个字符串s，如果第一次出现在后缀数组i的前面，那么如果它重复出现，下一次出现应该在第i+len(s)个后缀数组的前面。这个规律也不难看出。那么从头到尾按照这个规律搜索下不难得出结果。
 */

#include <iostream>
using namespace std;

int con_sub(char *str, char **ret);

int main()
{
    char str[50];
    char *ret = NULL;
    while (cin >> str) {
        int time = con_sub(str, &ret);
        printf("%s occuers %d times\n", ret, time);
    }
    return 0;
}

int con_sub(char *str, char **ret)
{
    int max_time = 0;//连续出现的最多次数
    int ret_len = 0;//连续出现的字符串的长度
    char *addr = NULL;//连续出现字符串的起始地址
    int len = strlen(str);
    char **a = (char **)malloc(sizeof(char *)*len);

    //生成后缀数组
    for(int i=0; i<len; i++)
        a[i] = &str[i];

    //重复字符串的长度范围为1到(len+1)/2
    for(int i=1; i<=(len+1)/2; i++)
    {
        //当重复的字符串长度为i的时候，如果是连续出现的，那么第j和第j+i个后缀数组前面为重复的字符串
        // for(int j=0; j+i<=len-1; j+=i)
        for(int j=i+1; j<=len-1; ++j)
        {
            int k = j;
            int temp_time = 1;
            while(k+i <= len-1 && strncmp(a[k], a[k+i], i) == 0)
            {
                temp_time++;
                k += i;
            }
            if(temp_time > max_time)
            {
                max_time = temp_time;
                ret_len = i;
                addr = a[k];
            }
        }
    }

    *ret = new char[len+1];
    strncpy(*ret, addr, ret_len);
    return max_time;
}