//********************************************************************
//  TestData.java       Java Foundations
//
//  Demonstrates I/O exceptions and the use of a character file
//  output stream.
//********************************************************************

import java.util.Random;
import java.io.*;
import java.util.Scanner;
public class Shalom_A04Q2
{
   //-----------------------------------------------------------------
   //  Creates a file of test data that consists of ten lines each
   //  containing ten integer values in the range 10 to 99.
   //-----------------------------------------------------------------
   public static void main (String[] args) throws IOException
   {
      final int MAX = 10;

      int value;
      String file = "test.txt";

      Random rand = new Random();
      
      //objects for inputing and outputing data.
      FileWriter fw = new FileWriter (file);
      BufferedWriter bw = new BufferedWriter (fw);
      PrintWriter outFile = new PrintWriter (bw);
      Scanner scan = new Scanner(System.in);
      
      
      String totalText = ""; //used to store their info
      System.out.println("");
      while(true)
      {
          String theirInput = scan.nextLine();
          if(theirInput.equals("DONE")) //quits application
          {
              break;
          }
          totalText += "\n" + " " + theirInput; //each string will be followed by a new line
      }
      outFile.print(totalText); // prints to test.txt
      outFile.close(); //ends
      System.out.println ("Output file has been created: " + file); //confirmation that everything went smoothly. 
   }
}