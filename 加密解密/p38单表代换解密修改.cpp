#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char T[26];
    cout<<"����26����ĸ������";
    for(int i=0;i<26;i++)
    {
        cin>>T[i];
    }
    while(true)
    {
        //char T[26]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};

        char mingwen[100];
        char miwen[100];
        int k,i;
        char S;
        //printf("������Сд��ĸ�����ģ���������հ״���\n");
        cout<<"������Сд��ĸ�����ģ���������հ״���\n";
        //gets(miwen);
        cin>>miwen;
        for(i=0; i<strlen(miwen); i++)
        {
           if(miwen[i]<='Z' && miwen[i]>='A')
            {
                miwen[i]=miwen[i]+32;
                //tolower(mingwen[i]);
            }
        }
        i=0;
        while(miwen[i]=='\0')
        {
            S=miwen[i];
            for(k=0;S!=T[k];k++);
            mingwen[i]='a'+k;
            i++;
        }
        /*for(i=0;miwen[i]!='\0';i++)
        {
            S=miwen[i];
            for(k=0;S!=T[k];k++);
            mingwen[i]='a'+k;
        }*/
        mingwen[i]='\0';
        //printf("���ܺ�������ǣ�\n%s\n",mingwen);
        cout<<"���ܺ�������ǣ�"<<mingwen<<endl;

        cout<<"�˳���Y/N"<<endl;
        char flag;
        cin>>flag;
        if(flag=='Y') break;
    }
    cout<<"�����˳���"<<endl;
}
