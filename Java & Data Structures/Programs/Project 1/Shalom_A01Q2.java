import java.util.Scanner;
/**
 * The following program takes the temp in Fahrenheit and converts it to Kalvin.
 */
public class Shalom_A01Q2
{
    public static void main(String args[])
    {
        //varibles
        double C_F = (5.0 / 9.0);
        double base = 459.67;
        
        Scanner in = new Scanner(System.in); //object from Class Scanner
        
        
        System.out.println("Please enter a temp in fahrenheit"); //prompts user for temp
        int input = in.nextInt(); 
        double tempKelvin = (input + base) * C_F; //formula
        
        
        System.out.println("The temp in Kelvin is:");
        System.out.println(tempKelvin);  //answer
    }
    
}
