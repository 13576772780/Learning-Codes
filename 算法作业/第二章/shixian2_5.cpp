#include <iostream>

using namespace std;

int countAll = 0;

// �ַ���ƥ��
bool Findsame(char list[], int k, int m){

    // list[m]�Ƿ�����list[k, m-1]���ֹ�
    for (int i = k; i < m; i++) {
        if (list[m] == list[i]) {
            // ������
            return true;
        }
    }

    return false;
}


// ȫ���У��ݹ�
void Perm(char list[], int k, int m){
    if (k == m) {
        // �������
        for (int i = 0; i <= m; i++) {
            cout << list[i];
        }
        countAll++;// ������+1
        cout << endl;
    }else{

        for (int i = k; i <= m; i++) {
            if (Findsame(list, k, i)) {
                continue;//ȥ���ѳ��ֹ�������
            }

            swap(list[k], list[i]);
            Perm(list, k + 1, m);// �ݹ�
            swap(list[k], list[i]);
        }
    }
}


int main()
{
    int n;
    char list[20];

    cin >> n;
    cin >> list;

    Perm(list, 0, n - 1);
    cout << countAll;


    cout << endl;
    return 0;
}
