import java.util.Random;
import java.util.Scanner;
/**
 * The following program rolls several 6 sided dices and then adds a number to the result
 */
public class Shalom_A02Q3
{
    public static void main(String args[])
    {
        //objects
        Random rd = new Random();
        Scanner in = new Scanner(System.in);
        //var's
        int diceRolls; // How many dices the user would like to roll
        int count = 0;
        
        System.out.println("How many dice would you like to roll?");
        diceRolls = in.nextInt();
        int diceRollsCopy = diceRolls; //diceRolls changes in the loop so copy is made here for the last print statement
        System.out.println("What should be added to the result?");
        int addedToCount = in.nextInt(); //The number that will be added to the result
       
        while(diceRolls > 0)
        {
            count += rd.nextInt(6) + 1; //nextInt function does not include 6 therefore + 1 it and the value ranges from 1-6
            diceRolls--;
        }
        count += addedToCount;
        System.out.println("The result of rolling " + diceRollsCopy + "D6+" + addedToCount + " is " + count);
    }
    
}
