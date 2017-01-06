import java.util.Scanner;
import java.lang.Math;
/**
 * The following program promts a user for two points and prints out the distance 
 * between the two points. 
 */
public class Shalom_A02Q1
{
    public static void main(String args[])
    {
        double x1;
        double x2;
        double y1;
        double y2;
        Scanner in = new Scanner(System.in);
        
        //prompts user for var's
        System.out.println("What is x1?");
        x1 = in.nextDouble();
        
        System.out.println("What is y1?");
        y1 = in.nextDouble();
        
        System.out.println("What is x2?");
        x2 = in.nextDouble();
        
        System.out.println("What is y2?");
        y2 = in.nextDouble();
        
        //formula
        double result = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
        //prints out result
        System.out.println("The distance is "+ result);
    }
    
}
