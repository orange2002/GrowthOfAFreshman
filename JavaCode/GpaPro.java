import java.util.Scanner;

/**
 * GPA 计算器 PRO
 * 给定科目数量、每一个科目的学分数及其成绩。求这份成绩单的加权平均成绩和平均绩点。结果保留两位小数。
 * 作者：陈昊天
 * 2020/11/5
 */



public class GpaPro
{

    public static double seekpoint(double yourgrade)
    {
        double yourgp = 0;
        if(yourgrade>=60)yourgp=  1.0;
        if(yourgrade>=64)yourgp=  1.5;
        if(yourgrade>=68)yourgp=  2.0;
        if(yourgrade>=72)yourgp=  2.3;
        if(yourgrade>=75)yourgp=  2.7;
        if(yourgrade>=78)yourgp=  3.0;
        if(yourgrade>=82)yourgp=  3.3;
        if(yourgrade>=85)yourgp=  3.7;
        if(yourgrade>=90)yourgp=  4.0;
        return yourgp;
    }

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();//n is the number of your course
        double credit[]=new double[n];
        double grade[]=new double[n];
        double point[]=new double[n];
        double sumcredit=0;
        double sumgrade=0;
        double sumpoint=0;

        int i;
        for (i=0;i<n;i++)
        {
            credit[i]=in.nextDouble();
            grade[i]=in.nextDouble();
            point[i]=seekpoint(grade[i]);
            sumcredit+=credit[i];
            sumgrade+=credit[i]*grade[i];
            sumpoint+=credit[i]*point[i];
        }
        System.out.printf("%.2f",sumgrade/sumcredit);
        System.out.println();
        System.out.printf("%.2f",sumpoint/sumcredit);

    }
}
