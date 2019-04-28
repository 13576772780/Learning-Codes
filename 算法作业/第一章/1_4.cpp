#include<malloc.h>
#include<iostream>
#include<fstream>
#define INF 1<<20


using namespace std;
/*������a�ĵ�col�н����б任*/
void transfer_row(int array[],int n)
{
    int i=0;
    for(i=0; i<n; i++)
        array[i]^=1;
}


/*��������a��i��j��*/
void swap_columns(int **a,int m,int n,int i,int j)
{
    int k=0;
    while(k<m)
    {
        int tmp=a[k][i];
        a[k][i]=a[k][j];
        a[k][j]=tmp;
        k++;
    }
}
/*�ȽϾ���a�ĵ�col_a�к;���b�ĵ�col_b�Ƿ����*/
int compare_column(int **a,int **b,int m,int n,int col_a,int col_b)
{
    int k=0;
    for(k=0; k<m; k++)
    {
        if(a[k][col_a]!=b[k][col_b])
            return 0;
    }
    return 1;
}


void copy_array(int** dest,int **src,int m,int n )
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            dest[i][j]=src[i][j];
}


/**Ѱ�ҽ�ԭʼ����a�任��Ŀ�����b�����ٱ任������������ܽ�a�任��b����ô����-1*/
int find(int **a,int **b,int m,int n)
{
    /**flag��¼һ�α任���Ƿ��ܹ��ﵽĿ�����*/
    int flag=0;
    /**bestΪ���ٽ�����������ʼֵΪ�����*/
    int best=INF;
    /**count��¼һ�α任��������Ҫ���н����Ĵ���*/
    int count=0;
    int **tmp=(int **)malloc(sizeof(int *)*m);
    int i=0;
    for(i=0; i<m; i++)
        tmp[i]=(int *)malloc(sizeof(int)*n);
    copy_array(tmp,a,m,n);


    /**���б任Ϊ��׼��һ�ν���ʼ����a��ÿһ�����һ�н���*/
    for(i=0; i<n; i++)
    {
        swap_columns(a,m,n,i,0);
        if(i!=0)
            count++;

        /**�б任�󣬽�a���µĵ�һ�к�Ŀ�����b�ĵ�һ�бȽϣ�
        ��a�е�һ����ĳ��Ԫ����b�е�һ����Ӧ�е�Ԫ�ز���ȣ���a�и��н��б任
        ��ɴ˹��̺�a�ĵ�һ��Ԫ�غ�b�ĵ�һ��Ԫ����ȫ��ͬ�������б任�����оͲ����ٽ����б任��
        */
        for(int j=0; j<m; j++)
        {
            if(a[j][0]!=b[j][0])
            {
                transfer_row(a[j],n);
                count++;
            }
        }


        /**��a��һ��Ѱ����Ӧ��ĳЩ��ʹ����Щ��һ�κ�b�еĵ�2����n����ȣ�
        ������ҳɹ�����˵�����ֱ任���ԴﵽĿ��״̬��Ȼ�󽫴��ֱ任�����ѵı任�����͵�ǰ���б任����best�Ƚ�
        ���С��best����best���´��ֱ任�Ļ��ѵı任����
        */
        for(int j=1; j<n; j++)
        {
            flag=0;
            for(int k=j; k<n; k++)
            {
                if(compare_column(a,b,m,n,k,j))
                {
                    if(k!=j)
                    {
                        count++;
                        swap_columns(a,m,n,k,j);
                    }
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                break;

        }
        if(flag==1&&best>count)
            best=count;
        count=0;
        copy_array(a,tmp,m,n);

    }
    if(best<INF)
        return best;
    else return -1;
}


int main()
{
    ifstream in("input.txt");
    ofstream output("output.txt");
    int num;
    in>>num;
    for(int i=0; i<num; i++)
    {


        int m,n;
        in >>m>>n;
        int **a=(int **)malloc(sizeof(int*)*m);
        int **b=(int **)malloc(sizeof(int*)*m);
        for(int i=0; i<m; i++)
        {
            a[i]=(int *)malloc(sizeof(int)*n);
            b[i]=(int *)malloc(sizeof(int)*n);
        }

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                in>>a[i][j];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                in>>b[i][j];

        int res=find(a,b,m,n);
        cout<<res<<endl;

        output<<res<<"\n";
    }
}
