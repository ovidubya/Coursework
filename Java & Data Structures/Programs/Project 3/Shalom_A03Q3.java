import java.util.Scanner;
/**
 * The program should read in an arbitrary number of integers that are in the range 1 to 10
 * inclusive, stopping when the user enters a 0, and warning the user when
 * the input is less than 0 or greater than 10 (i.e., invalid). At the end, it prints the 
 * histrogram :)
 */
public class Shalom_A03Q3
{
    public static void main(String args[])
    {
        Scanner sn = new Scanner(System.in);
        String[] histogram = new String[11];
        //need to intialize before adding '#' 
        histogram[0] = "";
        histogram[1] = "";
        histogram[2] = "";
        histogram[3] = "";
        histogram[4] = "";
        histogram[5] = "";
        histogram[6] = "";
        histogram[7] = "";
        histogram[8] = "";
        histogram[9] = "";
        histogram[10] = "";
        while(true)
        {
            System.out.print("Enter a value to plot: ");
            int input = sn.nextInt();
            if(input == 0) 
            {
                break;
            }
            //if its greater than 10
            if(input > 10) 
            {
                illegialNumber();
            }
            //if its less than 10
            if(input < 0) 
            {
                illegialNumber();
            }
            //if it hits the right spot than add a hastag
            if(input >= 1 && input <= 10)
            {
                for(int i = 0; i < 1; i++) 
                {
                    histogram[input] += "#";
                }
            }
        }
        
        //the data in the array
        for(int i = 1; i < 11; i++)
        {
            System.out.println(i + " | " + histogram[i]);
        }
    }
    //warns the user not to do it again other, otherwise they will be prosectued by law without further notice
    private static void illegialNumber()
    {
        System.out.println("Illegial number. Please enter a number from 1-10 inclusive.");
    }
    
}
