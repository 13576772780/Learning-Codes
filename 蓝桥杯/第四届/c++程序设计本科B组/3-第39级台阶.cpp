#include<iostream>

using namespace std;

int count=0;
void fun(int stair,int step)
{	//stari���ڱ�ʾʣ���¥�ݵĲ�����������0ʱֹͣ�ݹ�
	//step���߹��Ĳ����������ж��Ƿ���ż�����Ƿ����Ҫ��
	 if(stair<0)return;
	 if(stair==0)	//39��¥��ȫ������
	 {
	 	if(step%2 == 0)count++;
	 	return;
	 }
	 fun(stair-1,step+1);	//��һ������һ��̨��
	 fun(stair-2,step+1);	//��һ����������̨��
}

int main()
{
    fun(39,0);
    cout<<count<<endl;
    return 0;
}
