#include<stdio.h>
int main()
{
    char miwen[100];
    char mingwen[100];
    int k=3,i;
    printf("������Сд��ĸ������C����������հ״���\n");
    gets(miwen);
    for(i=0;miwen[i]!='\0';i++)
        mingwen[i]=(miwen[i]-'a'+26-k)%26+'a';
    mingwen[i]='\0';
    printf("���ܺ�������ǣ�\n%s\n",mingwen);

}
