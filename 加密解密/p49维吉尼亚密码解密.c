#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,len,k;
    char key[10];
    char mingwen[100];
    char miwen[100];
    printf("������Сд���ܹؼ��֣�\n");
    gets(key);
    len=strlen(key);
    printf("������Сд���ģ�\n");
    gets(miwen);
    for(i=0;miwen[i]!='\0';i++)
    {
        j=i%len;
        k=key[j]-'a';
        mingwen[i]=(miwen[i]-'a'+26-k)%26+'a';
    }
    mingwen[i]='\0';
    printf("���ܺ�������ǣ�\n%s\n",mingwen);
    return 0;
}
