//package a1_1;
import java.util.Scanner;
public class main
{
    public static void main(String []args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("�������������֣�");
        int x=sc.nextInt();
        int y=sc.nextInt();
        int temp=0;
        System.out.println("����ǰ��x="+x+",y="+y);
        temp=x;
        x=y;
        y=temp;
        System.out.println("������x="+x+",y="+y);
    }
}
