#include<iostream>
#include<algorithm>
using namespace std;

int Greedy(int a[],int n,int L){
	sort(a,a+n);
	int temp = 0;
	for(int i = 0;i<n;i++){//���һ��Ԫ��Ϊ�±�n-1��Ԫ��
		temp = temp + a[i];
		if (temp>L) return i;
		if(i==(n-1)) return n;	//����ȱ��������˺ܾã�û���뵽���д����������Ҳ����Ϊreturn i+1 ��������ͳһ�ԡ�
	}

}

int main(){
	int n;
	cin>>n;
	int L;
	cin>>L;
	int *a=new int[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
		}
	cout<<Greedy(a,n,L);
	system("pause");
	return 0;
}
