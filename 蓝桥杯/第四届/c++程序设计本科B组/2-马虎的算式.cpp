#include<iostream>
using namespace std;

void Calc() //���⺯��
{
	int count=0,m,n,x,y;
	for(int a=1;a<10;a++)
		for(int b=1;b<10;b++)
			for(int c=1;c<10;c++)
				for(int d=1;d<10;d++)
					for(int e=1;e<10;e++)
					{
						//������������
						if (a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e)
						{
							//ab * cde = adb * ce
							m=a*10+b;			 //ab
							n=c*100+d*10+e;		 //cde
							x=a*100+d*10+b;		//adb
							y=c*10+e;			//ce

							if (m*n==x*y)
							{
								count++;
							}
						}
					}
	cout<<"����:"<<count<<"��"<<endl;
}

int main(int argc, char* argv[])
{

	Calc();
	cin.get();
	return 0;
}
