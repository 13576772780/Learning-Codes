#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int a[50005];
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<n; i++)//ö����˵�
    {
        int l,r;
        l=INF;
        r=-INF;
        for(int j=i; j<n; j++)//ö���Ҷ˵�
        {
            l=min(l,a[j]);//���������С��
            r=max(r,a[j]);
            if(r-l==j-i)
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
