#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 50;
int num[MAX];  //�������
int flag[MAX];  //�Ƿ��Ѿ��ù�
int oper[MAX];  //1--'+', 2--'-', 3--'*', 4--'/'
int n, m;
int p[MAX];  //��ʱ����
int bestp[MAX];  //��������
int bestop[MAX]; //���Ų�����
char op[] = {' ', '+', '-', '*', '/'};
int k;  //��������𽥼���

bool found()
{
    int result = p[1];
    for(int i=1; i<=k; i++)  //����ʽ�ӵĽ��
    {
        switch(oper[i])
        {
        case 1:
            result += p[i+1];
            break;
        case 2:
            result -= p[i+1];
            break;
        case 3:
            result *= p[i+1];
            break;
        case 4:
            result /= p[i+1];
            break;
        }
    }

    return result == m;
}

bool backtrack(int dep)
{
    if(dep > k+1)  //����𽥼���
    {
        if(found())
        {
            copy(p, p+n+1, bestp);
            copy(oper, oper+n+1, bestop);
            return true;
        }
        else
            return false;
    }

    for(int j=1; j<=n; j++) //��ѡ������
    {
        if(flag[j] > 0)
            continue;
        p[dep] = num[j];
        flag[j] = 1;
        for(int i=1; i<=4; i++) //��ѡ�Ĳ�����
        {
            oper[dep] = i;
            if(backtrack(dep+1))
                return true;
            oper[dep] = 0;
        }
        flag[j] = 0;
        p[dep] = 0;
    }
    return false;
}

int main()
{
    ifstream fin("�����ȼ�����.txt");
    cout << "��������������";
    fin >> n;   cout << n << endl;
    cout << "����Ŀ������";
    fin >> m;   cout << m << endl;
    cout << "�����������\n";
    for(int i=1; i<=n; i++)
    {
        fin >> num[i];
        cout << num[i] << " ";
    }
    memset(flag, 0, sizeof(flag));
    memset(p, 0, sizeof(p));

    for(k=0; k<n; k++)
        if(backtrack(0))
        {
            cout << "\n���������ȼ��������Ϊ��" << k << endl;
            cout << "���������ȼ�������ʽΪ��" << endl;
            for(i=1; i<=k; i++)
                cout << bestp[i] << op[bestop[i]];
            cout << bestp[k+1];
            break;
        }
    cout << endl;
    cout << endl;
    fin.close();
    return 0;
}


