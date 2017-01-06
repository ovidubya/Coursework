import java.util.Scanner;
/**
 * The following program takes time in hours, minutes and seconds, and prints out the total seconds.
 */
public class Shalom_A01Q3
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in); //creates a object of class Scanner so the user can enter
                                             // input
        
        System.out.println("Enter hours:"); 
        int a = in.nextInt() * 60 * 60; // each hour has 60 minutes and each minutes has 60 seconds
        System.out.println("Enter minutes:");
        int b = in.nextInt() * 60;      //there is 60 seconds in each minute
        System.out.println("Enter seconds:");
        int c = in.nextInt();           //seconds are left the way they are
        System.out.println("The total time in seconds is;");
        System.out.println(a + b + c);
    }
}
