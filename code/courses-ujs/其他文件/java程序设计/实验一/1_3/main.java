//package a1_3;

import java.util.Scanner;

public class main
{
    public static void main(String []args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("������һ����λ����");
        int x=sc.nextInt();
        int s=0;
        while(x>0)
        {
            s=s+x%10;
            x=x/10;
        }
        System.out.println("ÿλ�ϵ�����֮��Ϊ��"+s);
    }
}
