import java.util.Scanner;

public class Taylor
{

     public static void main(String[] args)
     {
         Scanner in=new Scanner(System.in);
         int i;
         double a=1;
         double sum=1;
         double x=in.nextDouble();
         for(i=1;i<100;i++)
         {
             a=a*(-x)/i;
             sum+=a;
         }
         System.out.println(sum);

    }
}
