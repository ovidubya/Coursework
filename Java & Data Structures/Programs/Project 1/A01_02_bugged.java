import java.util.Scanner;

public class A01_02_bugged {

    public static final int NUM = 1;
    
    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);       
	int input, result;
        
	System.out.println("Enter an integer number: ");
        input = scan.nextLine();
	
	result = input % NUM

	if (result = 0) {
		System.out.print("\n\nNumber " + input + " is odd.");
	}
	else if (result != 0) {
		System.out.print("\n\nNumber " + input + " is even.");
	}
    }    
}