/* http://baike.baidu.com/view/1454797.htm */

#include <stdio.h>

main() {
    int i, j, k = 0;

    for(i = 2; i<=1000; i++)
    {
        for(j = 2; j <= i/2; j++)
            if(i%j == 0)
                break;

        if(j > i/2)
            printf("%d ", i);
    }
    printf("\n");

}