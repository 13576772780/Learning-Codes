#include<iostream>

using namespace std;

int main() {
	int v,n;//v�ڴ�������n��������
	int pi,mi;//pi�������ۣ�mi������Ӧ���
	int sum=0;//�ܼ�ֵ
	
	while(cin>>v,v) {
		cin>>n;
		int t=n;
		int (*arr)[2]=new int[n][2];
		while(t) {
			cin>>pi>>mi;
			arr[t-1][0]=pi;
			arr[t-1][1]=mi;
			t--;
		}
		//�Զ�ά�������� 
		for(int i=0;i<n;i++)
		{
			int max=0;
			int max2=0;
			int num=i;
			for(int j=i;j<n;j++)
			{
				if(arr[j][0]>max)
				{
					max=arr[j][0];
					max2=arr[j][1];
					num=j;
				}
			}
			arr[num][0]=arr[i][0];
			arr[num][1]=arr[i][1];
			arr[i][0]=max;
			arr[i][1]=max2;
		}
		for(int i=0;i<n;i++)
		{
			if(arr[i][1]>=v)
			{
				sum+=arr[i][0]*v;
				break;
			}
			else
			{
				sum+=arr[i][0]*arr[i][1];
				v=v-arr[i][1];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
