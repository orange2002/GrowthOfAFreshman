
import java.util.Scanner;

public class YangHuiTriangle
{
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        System.out.println("请输入层数");
	    int x=in.nextInt();
        int array[][]=new int[11][11];
        int i,j;
        for(i=1;i<=x;i++)
        {
            array[i][1] = 1;
            array[i][i] = 1;
            for (j = 2; j < i; j++)
                array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
        }
        for(i=1;i<=x;i++)
        {
            for (j = 1; j <= i; j++) {
                if (j == 1) System.out.print(array[i][j]);
                else System.out.print(" " + array[i][j]);
            }
            System.out.println();
        }
    }
}
