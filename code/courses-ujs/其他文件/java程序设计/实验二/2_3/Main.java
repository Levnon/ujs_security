//package a2_3;
import java.util.*;
public class Main
{
    public static void main(String []args)
    {
        double h=100.0;
        double sum=h;
        for(int i=0;i<10;i++)
        {
            h=h/2;
            sum=sum+2*h;
        }
        System.out.println("������"+sum+"�ף���10�η����߶�Ϊ��"+h+"��");
    }
}
