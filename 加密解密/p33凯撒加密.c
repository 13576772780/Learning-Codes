#include<stdio.h>
int main()
{
    char mingwen[100];
    char miwen[100];
    int k=3,i;
    printf("������Сд��ĸ������M����������հ״���\n");
    gets(mingwen);
    for(i=0;mingwen[i]!='\0';i++)
        miwen[i]=(mingwen[i]-'a'+k)%26+'a';
    miwen[i]='\0';
    printf("���ܺ��Ӣ���ǣ�\n%s\n",miwen);
}
