#include<iostream>
#include<algorithm>
#include<fstream>
#include<iomanip>
using namespace std;

int a[1000];
int ans;
int n;

int main()
{
		ifstream input("input.txt");
		ofstream output("output.txt");
		if(!input.is_open())
		{
			cout<<"can not open the input.txt";
			return 0;
		 }
		input>>n;

		for(int i=1;i<=n;i++)
		{
			input>>a[i];
		}

		sort(a+1,a+1+n);

		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cnt+=a[i];//��i���˿͵ĵȴ�ʱ��
			ans+=cnt;// �ۼ���ͣ�
		}

		output<<setiosflags(ios::fixed)<<setprecision(2) <<(ans*1.0)/n<<endl;//���ƽ���������������λС��

	return 0;
 }
