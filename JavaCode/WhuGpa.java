import java.util.Scanner;
/**
 * GPA 计算器
 * 写一个武大绩点计算器。输入一个整数`x`，`x`取值范围为`0`到`100`闭区间，输出对应的绩点。
 * 陈昊天
 *2020/11/5
 */



public class WhuGpa
{
    public static void main(String[] args)
    {

        do {
            int 你的成绩;
            System.out.println("请输入你的成绩（整数）");
            Scanner in = new Scanner(System.in);
            你的成绩 = in.nextInt();
            if (你的成绩 < 0) {
                System.out.println("你不会考了负分吧，不会吧");
                System.out.print("再来一次,");
                continue;
            }
            if (你的成绩 > 100) {
                System.out.println("你不会超过了满分吧，不会吧");
                System.out.print("再来一次，");
                continue;
            }
            System.out.print("经换算，你的绩点是：");
            if (你的成绩 < 60) { System.out.println(0);System.exit(0); }
            if (你的成绩 < 64) { System.out.println(1);System.exit(0); }
            if (你的成绩 < 68) { System.out.println(1.5);System.exit(0); }
            if (你的成绩 < 72) { System.out.println(2);System.exit(0); }
            if (你的成绩 < 75) { System.out.println(2.3);System.exit(0); }
            if (你的成绩 < 78) { System.out.println(2.7);System.exit(0); }
            if (你的成绩 < 82) { System.out.println(3);System.exit(0);}
            if (你的成绩 < 85) { System.out.println(3.3);System.exit(0);}
            if (你的成绩 < 90) { System.out.println(3.7);System.exit(0);}
            else System.out.println(4);System.exit(0);
        }while(1==1);

    }
}
