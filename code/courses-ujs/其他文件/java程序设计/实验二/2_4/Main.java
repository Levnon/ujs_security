//package a2_4;
import java.util.*;
import java.lang.*;
public class Main
{
    public static void main(String []args)
    {
        System.out.print("������һ������");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int ord=10;
        while(n/ord>=10) ord=ord*10;
        int quantity=(int)Math.log10((double)ord)+1;
        System.out.println("����ֵΪ"+quantity+"λ��");

        int temp=0;
        int reverse_num=0;
        for(int i=0;i<quantity;i++)
        {
            temp=n%10;
            n=n/10;
            reverse_num=reverse_num+temp*(int)Math.pow((double)10,(double)(quantity-i-1));
        }
        System.out.println("���������"+reverse_num);
    }
}
