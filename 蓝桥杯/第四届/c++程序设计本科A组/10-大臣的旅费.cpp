#include<stdio.h>
struct point{
	int s,e,v;
};
struct point map[10005];
int vis[10005];
int n,j;
int mx=0;
void dfs(int cur,int dist)
{
	if(dist>mx)
	{mx=dist;j=cur;}
	for(int i=0;i<n-1;i++)
	if(cur==map[i].s&&!vis[map[i].e])
	{
		vis[map[i].e]=1;
		dfs(map[i].e,dist+map[i].v);
		vis[map[i].e]=0;
	}
	else if(cur==map[i].e&&!vis[map[i].s])
	{
		vis[map[i].s]=1;
		dfs(map[i].s,dist+map[i].v);
		vis[map[i].s]=0;
	}


}
//һ������- -
//���Ե�һ������Ϊ��������һ��dfs��
//�ҳ��ӵ�һ������������һ��ֱ����Ȼ������ֱ��������һ���˵�a,
//Ϊ������һ��dfs���ֿ����ҳ�����һ���˵�b������֤��(a,b)��Ϊ����ֱ������������������Զ�ľ��룩
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	scanf("%d%d%d",&map[i].s,&map[i].e,&map[i].v);
	vis[1]=1;
	dfs(1,0);
	vis[1]=0;
	vis[j]=1;
	dfs(j,0);
	vis[j]=0;
	printf("%d",(mx+1)*mx/2+10*mx);
	return 0;
}
