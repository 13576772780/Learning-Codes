#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>

using namespace std;

const int M = 100000+5;
int ar[M];
char s[10];

int main()
{
	int x,n,m,num,sum=-1;
	memset(ar,0, sizeof(ar));
	scanf("%d\n",&x);
	for(int i=0; i<x; ++i){
		char c[205];
		gets(c);
		int idx=0;
		for(int j=0; j<strlen(c); ++j){
			if(c[j] == ' '){	//ȡÿһ���ո�֮�������
				num=atoi(s);
				idx=0;
				memset(s,0,sizeof(s));  //�����������
				ar[num]++;	//��Ǹ�����
				//printf("num= %d\n",num);
				sum=max(sum,num);	//������¼�����������������������ѭ��
			}
			s[idx++] = c[j];

		}
		num=atoi(s);	//���һ���ո�������
		idx=0;
		memset(s,0,sizeof(s));
		ar[num]++;
		sum=max(sum,num);
	}
	int i;
	for(i=0; i<=M; ++i){
		if(ar[i]!=0) break;
	}
	for(i; i<=sum; ++i ){	//�˴��õ������ݵ������
		if(ar[i] == 0) m = i;
		if(ar[i] == 2) n = i;
	}
	printf("%d %d\n", m, n);
	return 0;
}
