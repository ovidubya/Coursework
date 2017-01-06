import java.util.Random;
import java.util.Scanner;

public class Shalom_A02Q5
{
    public static void main(String args[]) 
    {
        Random rd = new Random();
        Scanner sn = new Scanner(System.in);
        
        boolean gameOn = true;
        int winningNumber = rd.nextInt(100) + 1; // random number from (1-100)
        int count = 0; // how many guesses a user made
        while(gameOn) 
        {
            System.out.println("What number do you guess?");
            int guess = sn.nextInt();
            
            if(guess == 0) //quits game
            {
                System.out.println("Quitting game.");
                System.out.print("Would you like to play again? Y Or N");
                sn.nextLine();
                String theirAnswer = sn.nextLine();
                
                
                if(theirAnswer.toLowerCase().equals("n"))
                {
                    break;
                }
                if(theirAnswer.toLowerCase().equals("y"))
                {
                    count = 0;
                    System.out.println("");
                    System.out.println("Picking a different number...");
                    winningNumber = rd.nextInt(100) + 1; // changes the winning number
                    System.out.println("What number do you guess?");
                    guess = sn.nextInt();
                }
            }
           
            if(guess == winningNumber) 
            {
                count++;
                System.out.println("That's correct!");
                System.out.println("You made " + count + " guesses.");
                System.out.println("Would you like to play again? Y Or N");
                sn.nextLine();
                String their2ndAnswer = sn.nextLine();
                
                
                if(their2ndAnswer.toLowerCase().equals("n"))
                {
                    break;
                }
                
                if(their2ndAnswer.toLowerCase().equals("y"))
                {
                    count = 0;
                    System.out.println("Picking a different number...");
                    winningNumber = rd.nextInt(100) + 1;
                    System.out.println("What number do you guess?");
                    guess = sn.nextInt();
                }
            }
            
            if(guess < winningNumber) 
            {
                count++;
                System.out.println("That's too low");
            }
            
            if(guess > winningNumber) 
            {
                count++;
                System.out.println("That's too high");
            }
            
        }
        System.out.println("Thank you for playing!");
    }
    
}
