import java.util.Scanner;
/**
 * 三值排序
 * 输入三个整数，请按从小到大的顺序输出它们。
 * 作者：陈昊天
 * 2020/11/5
 */



public class RankNum
{
    public static void main(String[] args)
    {
        int allnum=3;
        Scanner in=new Scanner(System.in);
        int[] num=new int[allnum];
        int i,j;
        for (i=0;i<allnum;i++) num[i]=in.nextInt();
        int temp;
        for(i=0;i<allnum-1;i++)
        for (j=0;j<allnum-1-i;j++)
        if(num[j]>num[j+1])
        {
            temp=num[j];
            num[j]=num[j+1];
            num[j+1]=temp;
        }
        System.out.print(num[0]);
        for (i=1;i<allnum;i++)System.out.print(" "+num[i]);
     }
}
