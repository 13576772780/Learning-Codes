#include<stdio.h>
int main()
{
    unsigned char str[]="�����й���\0";
    int i;
    for(i=0;i<sizeof(str);i++)
        printf("%03u  ",str[i]);
    return 0;
}
