#include <iostream>
#include<algorithm>
using namespace std;


const int maxn = 1000;
int N, T;
struct Interval{
    int start, end;
}a[maxn];

int cmp(const Interval &a, const Interval &b)
{
    if(a.start < b.start) return 1;
    else if(a.start == b.start && a.end < b.end) return 1;
    else return 0;
}

void solve()
{
    sort(a, a+N, cmp);
    int count = 0;
    int s, e = 1;
    int index = 0;
    int ok = 1;
    while(e < T)
    {
        s = e;//���¸�������
        for(int i=index; i<N; i++)
        {
            if(a[i].start <= s)
            {
                if(a[i].end >= s)
                {
                    e = a[i].end;//ȡ������������Զ���䡣
                }
            }
            else{
                index = i;//��������������Ҫ������
                break;
            }
        }
        if(s >= e)
        {
            ok = 0;
            break;
        }
        else{
            count ++;
        }
    }
    if(ok) cout<<count<<endl;
    else cout<<"-1"<<endl;
}
int main()
{

    cin>>N>>T;
    for(int i=0; i<N; i++)
    {
       // scanf("%d%d",&a[i].start, &a[i].end);
        cin>>a[i].start>>a[i].end;
    }
    solve();
    return 0;
}
