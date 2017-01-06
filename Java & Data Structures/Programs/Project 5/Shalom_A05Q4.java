/**
 * Write a description of the program here.
 * 
 * @author Lewis et al., (your name)
 * @version (program version)
 */

import java.util.Iterator;

public class Shalom_A05Q4
{
    /**
     * Program entry point for stack testing.
     * @param args Argument list.
     */    
    public static void main(String[] args)
    {
        LinkedStack<Integer> stack = new LinkedStack<Integer>();
        
        System.out.println("STACK TESTING");
        
        System.out.println("The stack contains:\n" + stack.toString());
        
        stack.push(3);
        stack.push(7);
        stack.push(4);
        System.out.println(stack.peek());
        stack.pop();        
        stack.push(9);
        stack.push(8);
        System.out.println(stack.peek());        
        System.out.println(stack.pop());
        System.out.println(stack.peek());        
        stack.pushLast(2);
        stack.pushLast(1);
        System.out.println("The size of the stack is: " + stack.size());
        System.out.println("The stack contains:\n" + stack.toString());        
    }
    
    /**
     * Represents a linked implementation of a stack.
     *
     * @author Java Foundations 
     * @version 4.0
     */
    public static class LinkedStack<T> implements StackADT<T>
    {
        private LinearNode<T> top; 
        private int size;
        /**
         * Creates an empty stack.
         */
        public LinkedStack()
        {
            top = null;
            size = 0;
        }
    
        /**
         * Adds the specified element to the top of this stack.
         * @param element element to be pushed on stack
         */
        public void push(T element)
        {
            LinearNode<T> temp = new LinearNode<T>(element);
    
            temp.setNext(top);
            top = temp;
            size++;
        }
    
        /**
         * Removes the element at the top of this stack and returns a
         * reference to it. 
         * @return element from top of stack
         * @throws EmptyCollectionException if the stack is empty
         */
        public T pop() throws EmptyCollectionException
        {
            if (isEmpty())
                throw new EmptyCollectionException("stack");
    
            T result = top.getElement();
            top = top.getNext();
            size--;
     
            return result;
        }
       
        /**
         * Returns a reference to the element at the top of this stack.
         * The element is not removed from the stack.  
         * @return element on top of stack
         * @throws EmptyCollectionException if the stack is empty  
         */
        public T peek() throws EmptyCollectionException
        {
            if(isEmpty())
            {
                throw new EmptyCollectionException("stack");
            }
            T result = top.getElement();
            return result;
        }
    
        /**
         * Returns true if this stack is empty and false otherwise. 
         * @return true if stack is empty
         */
        public boolean isEmpty()
        {
            if(size == 0)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
     
        /**
         * Returns the number of elements in this stack.
         * @return number of elements in the stack
         */
        public int size()
        {
            return size;
        }
        
        /**
         * Not part of the StackADT interface so it can cause underserible behavior. 
         * @param element to be pushed to the last in the stack
         */
        public void pushLast(T element) 
        {
            LinearNode<T> tempLast = new LinearNode(element);
            if(isEmpty())//no differnce than regular push
            {
                tempLast.setNext(top);
                top = tempLast;
                size++;
            }
            else //if not empty
            {
                LinearNode<T> tempTop = top; //refernce to the top
                while(tempTop != null) //to start the loop
                {
                    if(tempTop.getNext() == null) //once you get to the bottom
                    {
                        tempTop.setNext(tempLast); //new bottom
                        tempLast.setNext(null); // point to nothing
                        tempTop = tempTop.getNext(); //could be ommited
                        size++;//add to the size
                    }
                    else //keeping going until its the bottom in the stack
                    {
                        tempTop = tempTop.getNext();
                    }
                }
            }
        }
        
        /**
         * Returns a string representation of this stack. The string has the
         * form of each element printed on its own line, with the top most
         * element displayed first, and the bottom most element displayed last.
         * If the list is empty, returns the word "empty".
         * @return a string representation of the stack
         */
        public String toString()
        {
            String result = "";
            if(isEmpty())
            {
                return "empty";
            }
            else
            {
                LinearNode<T> tempTop = top;
                while(tempTop != null) 
                {
                    result += tempTop.getElement() +"\n";
                    tempTop = tempTop.getNext();
                }
                return result;
            }
        }
    }
}