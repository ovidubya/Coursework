import java.util.Scanner;
public class Shalom_A01Q1bugged {

    public static final int NUM = 2; // diving by 1 doesnt do anything for us, needs to be 2
    
    public static void main(String[] args) 
    {
        
        Scanner scan = new Scanner(System.in);       
        int input, result;
        
        System.out.print("Enter an integer number: ");
        input = scan.nextInt(); // nextLine is incorrect since its not a string, should nextInt()
    
        result = input % NUM; //Missing a semicolon because this is a Java Statement

        if (result == 0) // Incorrect Idenitifer, needs the double ='s
        {
            System.out.print("Number " + input + " is even."); // shouldnt be odd, needs to be even
            //also no need to print on the next line
        }
        else if (result != 0) 
        {
            System.out.print("Number " + input + " is odd."); // needs to be switched aswell
            // also no need to print on the next line
        }
    }    
}