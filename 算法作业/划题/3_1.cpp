#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int a[201], b[201];
int n;
int dp[202][10000];//dp[i][j] ��ʾǰi����ҵ��A������j���ӵ�ʱ�� B��������ʱ��
int main(int argc, char* argv[]) {
    cin >> n;
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    int sum=0;
    for(int i=1; i<=n; i++) {
        sum+=a[i];
        for(int j=0; j<=sum; j++) {
            dp[i][j]=dp[i-1][j]+b[i];
            if(j>=a[i]) dp[i][j]=min(dp[i-1][j]+b[i],dp[i-1][j-a[i]]);
        }
    }
    int ans=999999;
    //max(dp[n][i],i) ��ʾ���ǰn����ҵA������i���� B������dp[n][i]��������£�����깤ʱ��
    for(int i=0; i<=sum; i++)ans=min(ans,max(dp[n][i],i));
    cout<<ans<<endl;
    return 0;
}
