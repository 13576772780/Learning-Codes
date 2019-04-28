/*
���ַ�ʵ��
1����a[0:n-1]��һ�����ź��������.
���д���������㷨��ʹ�õ�����Ԫ��x����������ʱ,
����С��x�����Ԫ�ص�λ��I�ʹ���x�����Ԫ��λ��j.
������Ԫ����������ʱ��I��j��ͬ����Ϊx�������е�λ��.
2������n����ͬ�������ź��������t[0:n-1]��,
������һ���±�I,0<=i<n��ʹ��t[i]=i,
���һ����Ч���㷨�ҵ�����±�.
Ҫ���㷨���������µļ���ʱ��ΪO(logn).
*/
#include<iostream>
using namespace std;
/*
����:1\���ֲ��ҸĽ���
����:�ĺ����a[],��Сn,������x,���ز���i,j
����:��:�ҵ�
*/
bool BinarySearch(int *a,int n,int x,int& i,int& j){
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(x==a[mid]){
            i=j=mid;
            return true;
        }
        if(x>a[mid])
            left=mid+1;
        else
            right=mid-1;
    }
    i=right;
    j=left;
    return false;
}
/*
����:2\��Ч����
����:����,��С,����ֵ
����:�±�,��û�з���-1
*/
int SearchTag(int *a,int n,int x){
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(x==a[mid]) return mid;
        if(x>a[mid])
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}
int main(){
    int n,i,j,a[1000],x;
    while(cin>>n){//���������С
        for(i=0;i<n;i++)cin>>a[i];//��������,��Ҫ��С����
        cin>>x;//�����������
        BinarySearch(a,n,x,i,j);//����
        cout<<"�ú���1�ҵ���i,jΪ: "<<'('<<i<<','<<j<<')'<<'\n';//�����Ӧ��i,j
        cout<<"�ú���2�ҵ����±�Ϊ: "<<SearchTag(a,n,x)<<"\n\n";//���2�ҵ����±�
    }
    return 0;
}
