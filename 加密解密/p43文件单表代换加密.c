#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp3,*fp2;
    char ch,s;
    char T[27]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
    int K,i;
    fp2=fopen("mingwen2.txt","r");
    if(fp2==NULL)
    {
        printf("mingwen2.txt��ʧ��\n");
        //exit(0);
    }
    fp3=fopen("miwen3.txt","w");
    if(fp3==NULL)
    {
        printf("miwen3.txt��ʧ�ܣ�\n");
    }
    ch=fgetc(fp2);
    printf("��ʼ����mingwen2.txt�ļ����ַ�%c",ch);
    do
    {
        K=ch-'a';
        s=T[K];
        fputc(s,fp3);
        ch=fgetc(fp2);
        printf("%c",ch);
    }while(ch!=EOF);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
