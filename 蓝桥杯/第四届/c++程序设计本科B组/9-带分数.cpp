#include <stdio.h>
#include <string.h>

//˼·������ö�ٷ�
char flag[10];    //���ڱ��"#123456789"�Ƿ��Ѿ���ѡ
char backup[10];  //������ʱ��������

//���"#123456789"ÿ�������Ƿ�ֻ��һ��
int check(int n)
{
	do
  	{
  		++flag[n%10];  //ͳ�����֣���n = 123;��++flag[3],++flag[2],++flag[1]
  	}while(n /= 10);
  	if(flag[0] != 0) //�������0
    	return 1;      //���س�ͻ
  	for(int i = 1; i < 10; i++)
    	if(flag[i] > 1)//�������ĳ�����ݲ�ֻ��1��
      		return 1;    //���س�ͻ
  	return 0;        //������ȷ
}

//����Ƿ�ÿ�����ݶ��Ѿ�����
int checkAll(void)
{
	for(int i = 1; i < 10; i++)
    	if(flag[i] != 1)
      		return 1;//��ȫ������
  	return 0;    //ȫ������
}

int main(void)
{
	int i = 0;
    int num = 0;        //��������
    int count = 0;      //ͳ�Ƹ���
    scanf("%d", &num);
    int left = 0, up = 0, down = 0;   //������
    for(left = 1; left < num; ++left) //�ȴӴ���������߿�ʼ����
    {
  		for (i = 0; i < 10; ++i)        //���������ȫ����ʼ��Ϊ0
	  	flag[i] = 0;
    	if(check(left))                 //���������ݺ�����
      		continue;//������
		for (i = 0; i < 10; ++i)        //����flag���ݣ���������forѭ������
			backup[i] = flag[i];
   		for(down = 1; down < 100000; ++down) //�����Ӵ���������
		{
      		for (i = 0; i < 10; ++i)      //����flag
				flag[i] = backup[i];
      		up = (num - left) * down;     //�����upֵ
      		if(check(down) || check(up))  //������ݺ�����
        		continue;//������
      		if(!checkAll())
	  		{
        	//	printf("%d = %d + %d / %d\n", num, left, up, down);
        		++count; //����+1
      		}
    	}
  	}
  	printf("%d\n", count);//��ӡ�ܹ�����
        return 0;
}
