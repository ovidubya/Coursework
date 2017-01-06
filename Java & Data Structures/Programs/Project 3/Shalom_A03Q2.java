/**
 * A class to simulate rolling many dice and finding the ratio of snake eyes.
 * 
 * @author Lewis et al., CST200 team.
 */

public class Shalom_A03Q2
{
    //Note: you should not need to change the Die class.
    public static class Die
    {
        
        private final int MAX = 6;
        
        private int faceValue;
        
        public Die()
        {
            faceValue = 1;
        }
        
        public int roll()
        {
            faceValue = (int)(Math.random() * MAX) + 1;
            
            return faceValue;
        }
        
        public void setFaceValue(int value)
        {
            if(value > 0 && value <= MAX)
                faceValue = value;
        }
        
        public int getFaceValue()
        {
            return faceValue;
        }
        
        public String toString()
        {
            String result = Integer.toString(faceValue);
            
            return result;
        }
    }    
    
    public static class PairOfDice
    {      
        private Die firstDie;
        private Die secondDie;
        private final int MAX = 6;
        public PairOfDice()
        {
            firstDie = new Die();
            secondDie = new Die();
        }
        //sets the value of the first die
        public void setFirstDie(int value)
        {
            firstDie.setFaceValue(value);
        }
        //sets the value of the second die
        public void setSecondDie(int value)
        {
            secondDie.setFaceValue(value);
        }
        //gets the value of the first die
        public int getFirstDie()
        {
            return firstDie.getFaceValue();
        }
        //gets the value of the second die
        public int getSecondDie()
        {
            return secondDie.getFaceValue();
        }
        //rolls the dice at the same time
        public void rollDice()
        {
            firstDie.roll();
            secondDie.roll();
        }
        //returns the sum of the dice
        public int getDiceSum()
        {
            return getFirstDie() + getSecondDie();
        }
    }

    public static void main(String[] args) {
        final int ROLLS = 500;
        int count = 0;
        PairOfDice dicePair = new PairOfDice(); //object from class PairOfDice
        for(int roll = 1; roll <= ROLLS; roll++)
        {
            dicePair.rollDice(); //rolls both dice then checks to see if
                                // they both are equal to 1 (snake eyes)
            if(dicePair.getFirstDie() == 1 && dicePair.getSecondDie() == 1)
            {
                count++;
            }
        }
        
        System.out.println("Number of rolls: " + ROLLS);
        System.out.println("Number of snake eyes: " + count);
        System.out.println("Ratio: " + (double)count / ROLLS);
    }
    
}