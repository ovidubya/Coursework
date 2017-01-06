/**
 * This program is called the stars program.
 */
public class Shalom_A02Q6
{
    public static void main(String args[])
    {
        int counter = 1;
        int kCounter = 10;
        while(true)
        {
            if(counter == 11) //5th row, 9 stars
            {
                break;
            }
            
            for (int k = 0; k < kCounter; k++) //Start with maxium space and decrease kCounter at the end
            {
                System.out.print(" ");
            }
            
            for(int j = 1; j <= counter; j++) // adds stars in {1, 3, 5, 7, 9}
            {
                System.out.print("*");
            }
            System.out.println("");
            counter+=2; //adds stars
            kCounter--; // decreases the space
        }
        /*
         * At the end of the above loop, counter is +2 and kCounter is -1, So i just resetted to where it left off so it will print 9 *'s.
         */
        counter-=2;
        kCounter++;
        while(true) 
        {
            if(counter == -1) //10 row, 1 star
            {
                break;
            }
            
            for(int k = 0; k < kCounter; k++) // Starts with minium space and increases to max
            {
                System.out.print(" ");
            }
            
            for(int j = 1; j <= counter; j++) // adds stars in {9, 7, 5, 3, 1}
            {
                System.out.print("*");
            }
            System.out.println("");
            counter-=2; //decreases stars
            kCounter++; //add space
        }
        
    }
}
