import java.util.Scanner;
/**
 * 等差数列求和 给出等差数列的首项、公差和项数，使用循环语句计算该数列的和。
 * @version 1.0 2020/11/5
 * @author 陈昊天
 */
public class ArithmeticalProgressionSum
{

    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
	    System.out.println("请依次输入等差数列的首项、公差和项数");
	    float a=in.nextFloat();
	    float d=in.nextFloat();
	    int n=in.nextInt();
	    float s=0;
	    for (int i=0;i<n;i++)s+=a+i*d;
		System.out.println(s);
		in.close();
    }
}
