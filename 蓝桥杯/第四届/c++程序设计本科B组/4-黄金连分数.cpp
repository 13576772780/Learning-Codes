#include<cstdio>
#include<iostream>
using namespace std;
#define LL long long
LL f[55]={0};
int main()
{
	f[1]=1;
	int i;
	for(i=2;i<=51;i++) f[i]=f[i-1]+f[i-2]; //��fib������һ��
	LL y=f[49],x=f[48];
	for(i=0;i<=100;i++) //ģ������Ĺ��̣�����������Ĺ���һ�����ڲݸ�ֽ�ϻ�һ����֪��
	{
		int ans=x/y;
		x=(x%y)*10;
		cout<<ans; //�������
	}
	return 0;
}
