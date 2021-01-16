/**
 * 等差数列求和
 * 使用循环语句，计算`1 + 2 + 3 + ... + 99 + 100` 的和
 * 陈昊天
 *2020/11/5
 */

public class ArithmeticalProgression
{

    public static void main(String[] args)
    {
        int i;
        int sum=0;
        for(i=1;i<=100;i++)
        {
            sum+=i;
        }
        System.out.println(sum);
    }
}
