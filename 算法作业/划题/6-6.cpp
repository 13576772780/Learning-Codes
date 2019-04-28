#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int vis[3][50], P[15];//�������� �I���J�ڴ��������򶼲����лʺ�
int n, sum;

void  DFS(int row);

int main()
{
    for(n = 1; n <= 10; n++)//�ȴ��Ȼ�ᳬʱ��
    {
        memset(vis,0,sizeof(vis));
        sum = 0;
        DFS(1);
        P[n] = sum;
    }
    while(scanf("%d",&n), n)
    {
        printf("%d\n",P[n]);
    }
    return 0;
}

void  DFS(int row)
{
    int i;
    if(row == n + 1)//�Ѿ���n����
    {
        sum ++;
        return ;
    }
    for(i = 1; i <= n; i++)
    {
        if(vis[0][row-i+n] == 0 && vis[1][i] == 0 && vis[2][row+i] == 0)
        {//������ݵ�ͬѧҪ�úÿ���ѧϰѧϰ
            vis[0][row-i+n] = vis[1][i] = vis[2][row+i] = 1;//��ֵ
            DFS(row + 1);//����
            vis[0][row-i+n] = vis[1][i] = vis[2][row+i] = 0;//����
        }
    }
}
