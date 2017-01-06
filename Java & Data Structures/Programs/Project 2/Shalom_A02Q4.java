
import java.util.Scanner;
/**
 * The following programs prompts a year from the user and lets them know if it is
 * a leap year or not. A number less than 1582 is an error since that was the year
 * the Gregorian calender was adopted. 
 */
public class Shalom_A02Q4
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
    
        System.out.println("What year should be checked?");
        
        int year = in.nextInt();
        if (year < 1582) 
        {
              System.out.println("Sorry, enter a year greater than 1582");
        }
        else 
        {
            //A year is a leap year if it is divisible by 4, 
            //unless it is also divisible by 100 but not 400
           if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
           {
               System.out.println("This is a leap year.");
           }
           else 
           {
               System.out.println("This is not a leap year");
           }
         }    
        
    }
}
