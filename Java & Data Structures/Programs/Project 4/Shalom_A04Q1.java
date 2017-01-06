import java.util.Scanner;
public class Shalom_A04Q1
{
   public static void main(String args[])
   {
       Scanner scan = new Scanner(System.in);
       int count = 0;
       final int MAX = 5; //can't have more than 5 numbers
       double[] numberArray = new double[5]; //an array to carry the 5 numbers in
       while(true)
       {
           System.out.print("Please enter a number: ");
           String theirStringNumber = scan.nextLine();
           try
           {
               double theirDoubleNumber = Double.parseDouble(theirStringNumber);
               numberArray[count] = theirDoubleNumber;
               count++;
               if(count == MAX) // 5 doesnt exist in the array
               {
                   break;
               }
           }
           catch(NumberFormatException e) //this is the exception when parsing something invalid
           {
               System.out.println("Please enter a valid number.");
               System.out.println("");
           }
       }
       
       double result = 0; //add their numbers in result
       for(int i = 0; i < numberArray.length; i++)
       {
           result += numberArray[i];
       }
       //divide by 5 for average
       System.out.println("The average is " + (result / 5) + ".");
   }
}
