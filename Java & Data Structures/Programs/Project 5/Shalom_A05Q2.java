import java.util.Arrays;
/**
 * Write a description of the program here.
 * 
 * @author Lewis et al., (your name)
 * @version (program version)
 */

public class Shalom_A05Q2
{
    /**
     * Program entry point for drop-out stack testing.
     * @param args Argument list.
     */    
    public static void main(String[] args)
    {
        ArrayDropOutStack<Integer> stack = new ArrayDropOutStack<Integer>(4);
        
        System.out.println("DROP-OUT STACK TESTING");
        
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);       
        stack.push(5);               
        
        System.out.println("The size of the stack is: " + stack.size());        
        if(!stack.isEmpty())            
            System.out.println("The stack contains:\n" + stack.toString());
        
        stack.pop();        
        stack.push(7);
        stack.push(8);      
        
        System.out.println("The size of the stack is: " + stack.size());                
        if(!stack.isEmpty())            
            System.out.println("The stack contains:\n" + stack.toString());
    }
    
    public static class ArrayDropOutStack<T> implements StackADT<T>
    {   
        private final static int DEFAULT_CAPACITY = 100;
    
        private int top;  
        private T[] stack;
        private int size; // size of the array
        /**
         * Creates an empty stack using the default capacity.
         */
        public ArrayDropOutStack()
        {
            this(DEFAULT_CAPACITY);
            size = 0; //nothing in the array yet
        }
        
        /**
         * Creates an empty stack using the specified capacity.
         * @param initialCapacity the initial size of the array 
         */
        @SuppressWarnings("unchecked") //see p505.
        public ArrayDropOutStack(int initialCapacity)
        {
            top = 0;
            stack = (T[])(new Object[initialCapacity]);
        }
        
        /**
         * Adds the specified element to the top of this stack, if full, then moves all the
         * elements byt + 1 and puts element through the paramater at the end.
         * @param element generic element to be pushed onto stack
         */
        public void push(T element)
        {
            if (size() == stack.length) //if stack is full
            {
                for(int i = 0; i < stack.length-1; i++) // move everything by 1
                {
                    stack[i] = stack[i+1];
                }
                stack[top-1] = element; // put the element at the end
            }
            else //push it to the top
            {
                stack[top] = element; 
                top++;
                size++;
            }
        }
    
        /**
         * Removes the element at the top of this stack and returns a
         * reference to it. 
         * @return element removed from top of stack
         * @throws EmptyCollectionException if stack is empty 
         */
        public T pop() throws EmptyCollectionException
        {
            if (isEmpty())
                throw new EmptyCollectionException("stack");
    
            top--;
            T result = stack[top];
            stack[top] = null; 
            size--;
            return result;
        }
       
        /**
         * Returns a reference to the element at the top of this stack.
         * The element is not removed from the stack. 
         * @return element on top of stack
         * @throws EmptyCollectionException if stack is empty
         */
        public T peek() throws EmptyCollectionException
        {
            if (isEmpty())
                throw new EmptyCollectionException("stack");
    
            return stack[top-1];
        }
    
        /**
         * Returns true if this stack is empty and false otherwise. 
         * @return true if this stack is empty
         */
        public boolean isEmpty()
        {
            if(size == 0) //nothing in the array
            {
                return true;
            }
            else //has 1 or more items. 
            {
                return false;
            }
        }
     
        /**
         * Returns the number of elements in this stack.
         * @return size the number of elements in the stack
         */
        public int size()
        {
            return size;
        }

        /**
         * Returns a string representation of this stack. The string has the
         * form of each element printed on its own line, with the top most
         * element displayed first, and the bottom most element displayed last.
         * If the list is empty, returns the word "empty".
         * @return output a string representation of the stack
         */
        public String toString()
        {
           if(isEmpty()) //no items in the stack
           {
               return "Empty";
           }
           String output = "";
           for(int i = size-1; i >= 0; i--) // starts at the top of stack and decrements by 1
           {
               if(stack[i] != null) // there is no date to be outputed
               {
                   //after putting the elements from the top, start a new line
                   output += stack[i] + "\n";
               }
           }
           //result
           return output;
        }
   }
      
    }