#include<stdio.h>
int main()
{
    int n;
    int i;
    printf("������һ�������ж����Ƿ�Ϊ������");
    scanf("%d",&n);
    if(n==0||n==1)
    {
        printf("the is not prime number\n");
    }
    else
    {
        for(i=2;i<n;i++)
        {
            if(n%i==0)
            {
                break;
            }
        }
        if(i<n)
        {
            printf("this is not prime number!\n");
        }
        else
        {
            printf("this is prime number~\n");
        }
    }
    return 0;
}
