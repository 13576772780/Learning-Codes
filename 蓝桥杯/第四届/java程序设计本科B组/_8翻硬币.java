package ���ű�4B;

import java.util.Scanner;

public class _8��Ӳ�� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String s1=s.next();//�����һ������
		String s2=s.next();//�����һ������
		int count=0;//���·����Ĵ���
		char [] a=new char [s1.length()];//�����һ������
		char [] b=new char [s1.length()];//�����һ������
		for(int i=0;i<s1.length()-1;i++){
			a[i]=s1.charAt(i);
			b[i]=s2.charAt(i);
		}
		for(int i=0;i<s1.length()-1;i++){
			if(a[i]!=b[i]){
				if(a[i+1]=='*'){
					a[i+1]= 'o';
				}
				else a[i+1]='*';
				count++;
			}
		}
		System.out.println(count);
	}

}
