package ���ű�4B;

import java.util.Scanner;

public class _7����Ʊ�� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		in.nextLine();//���뻻�з�
		int[] num=new int[100001];
		for(int i=0;i<100001;i++)
		{
			num[i]=0;
		}
		int min=100001;
		int max=0;
		for(int i=0;i<n;i++)
		{
			String line=in.nextLine();
			String[] lines=line.split(" ");
			for(int j=0;j<lines.length;j++)
			{
				int a=Integer.parseInt(lines[j]);
				num[a]++;
				if(min>a) min=a;
				if(max<a) max=a;
			}
		}
		for(int i=min;i<=max;i++)
		{
			if(num[i]==0) System.out.println("ȱ�ٵ�"+i);
			if(num[i]==2) System.out.println("�ظ���"+i);
		}

	}

}
