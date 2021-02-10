import java.time.*;

/**
 * print calendar of this month
 * @version 1
 * @author orange
 */
public class ThisMonth {
    public static void main(String[]args) {
        LocalDate todayDate = LocalDate.now();
        int thisYear=todayDate.getYear();
        int thisMonth=todayDate.getMonthValue();
        int thisDay=todayDate.getDayOfMonth();
        DayOfWeek thisDayOfWeek=todayDate.getDayOfWeek();
        int dayValue=thisDayOfWeek.getValue();
        int firstDay=(-thisDay+dayValue)%7;//if day 1 is Tue,the value is 1;
        if (firstDay<0)firstDay+=7;
        int dayNum;
        switch (thisMonth) {
            case 1: case 3:case 5:case 7:case 8:case 10:case 12:
                dayNum=31;break;
            case 4:case 6:case 9:case 11:
                dayNum=30;break;
            case 2:
                if(thisYear%400==0||(thisYear%4==0&&thisYear%100!=0))dayNum=29;
                else dayNum=28;
                break;
            default:dayNum=0;System.out.println("error");break;
        }
        System.out.println("Mon Tue Wed Thu Fri Sat Sun");
        int i=0;
        for(;i<firstDay;i++) System.out.print("    ");
        for(;i<(firstDay+dayNum);i++){
            if(i+1-firstDay<10)System.out.print("  "+(i+1-firstDay)+" ");
            else System.out.print(" "+(i+1-firstDay)+" ");
            if((i+1-firstDay)==thisDay)System.out.print("\b*");
            if(i%7==6)System.out.println(" ");
        }
    }
}