#include<stdio.h>
int main()
{
    char miwen[100];
    char mingwen[100];
    int k,i;
    printf("������Сд��ĸ������C����������հ״���\n");
    gets(miwen);
    for(k=1;k<=25;k++)
    {
        for(i=0;miwen[i]!='\0';i++)
            mingwen[i]=(miwen[i]-'a'+26-k)%26+'a';
        mingwen[i]='\0';
        printf("��%d�ֿ��ܵ�����Ϊ��%s\n",k,mingwen);
    }

}
