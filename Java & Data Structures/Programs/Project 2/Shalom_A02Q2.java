import java.util.Scanner;
import java.lang.Math;
/**
 * The following program reads the lengths of the sides of a triangle
 * and prints out the area. s represents half of the perimeter of the 
 * triangle, and a, b, and c represent the lengths of the three sides.
 */
public class Shalom_A02Q2
{
    public static void main(String args[])
    {
        double s;
        double a;
        double b;
        double c;
        
        Scanner in = new Scanner(System.in);
        
        System.out.println("What is s?");
        s = in.nextDouble();
        
        System.out.println("What is a?");
        a = in.nextDouble();
        
        System.out.println("What is b?");
        b = in.nextDouble();
        
        System.out.println("What is c?");
        c = in.nextDouble();
        
        //formula
        double area = Math.sqrt(s * (s - a) * (s - b) * (s - c));
        
        //rounds to three decimal places. The zero's represent the decmial places. 
        area = Math.round(area * 1000d) / 1000d;
        
        System.out.println("The area is " + area);
    }
}
