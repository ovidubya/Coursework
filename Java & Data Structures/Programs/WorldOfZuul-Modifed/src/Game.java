/**
 *  This class is the main class of the "World of Zuul" application. 
 *  "World of Zuul" is a very simple, text based adventure game.  Users 
 *  can walk around some scenery. That's all. It should really be extended 
 *  to make it more interesting!
 * 
 *  To play this game, create an instance of this class and call the "play"
 *  method.
 * 
 *  This main class creates and initialises all the others: it creates all
 *  rooms, creates the parser and starts the game.  It also evaluates and
 *  executes the commands that the parser returns.
 * 
 * @author  Michael Kölling and David J. Barnes
 * @version 2011.08.08
 */

public class Game 
{
    private Parser parser;
    private Player player;
    private Professor professor;
    /**
     * Create the game and initialise its internal map.
     */
    public Game() 
    {
        createRooms();
        parser = new Parser();
    }

    /**
     * Create all the rooms and link their exits together.
     */
    private void createRooms()
    {
        Room outside, theater, pub, lab, office, labyrinth;
        
        //creat items
        Item sword, book, armor;
        sword = new Item("sword", "one-hit kill with any enemy it attacks", 7);
        book = new Item("book", "contains codes which allow you to teleport to any room", 4);
        armor = new Item("armor", "invincable to any enemy attacks", 20);
        
        
        
        // create the rooms
        outside = new Room("outside the main entrance of the university");
        theater = new Room("in a lecture theater");
        pub = new Room("in the campus pub");
        lab = new Room("in a computing lab");
        office = new Room("in the computing admin office");
        labyrinth = new Room("in the University Labyrinth");
        
        // add items to the room
        pub.addItem(sword);
        lab.addItem(book);
        theater.addItem(armor);
        
        // initialise room exits
        outside.setExit("east", theater);
        outside.setExit("south", lab);
        outside.setExit("west", pub);
        outside.setExit("north", labyrinth);
        
        theater.setExit("west", outside);

        pub.setExit("east", outside);
        pub.setExit("west", labyrinth);
        
        lab.setExit("north", outside);
        lab.setExit("east", office);

        office.setExit("west", lab);
        
        labyrinth.setExit("east", outside);
        labyrinth.setExit("south", pub);
        
        player = new Player(outside);
        professor = new Professor(pub);
    }

    /**
     *  Main play routine.  Loops until end of play.
     */
    public void play() 
    {            
        printWelcome();

        // Enter the main command loop.  Here we repeatedly read commands and
        // execute them until the game is over.
                
        boolean finished = false;
        while (! finished) {
            Command command = parser.getCommand();
            finished = processCommand(command);
        }
        System.out.println("Thank you for playing.  Good bye.");
    }

    /**
     * Print out the opening message for the player.
     */
    private void printWelcome()
    {
        System.out.println();
        System.out.println("Welcome to the World of Zuul!");
        System.out.println("World of Zuul is a new, incredibly boring adventure game.");
        System.out.println("Type 'help' if you need help.");
        System.out.println();
        System.out.println(player.getRoom().getLongDescription());
    }

    /**
     * Given a command, process (that is: execute) the command.
     * @param command The command to be processed.
     * @return true If the command ends the game, false otherwise.
     */
    private boolean processCommand(Command command) 
    {
        boolean wantToQuit = false;

        if(command.isUnknown()) {
            System.out.println("I don't know what you mean...");
            return false;
        }

        String commandWord = command.getCommandWord();
        if (commandWord.equals("help")) {
            printHelp();
            professor.act();
        }
        else if (commandWord.equals("go")) {
            goRoom(command);
            professor.act();
        }
        else if (commandWord.equals("quit")) {
            wantToQuit = quit(command);
            professor.act();
        }
        
        else if (commandWord.equals("look")) {
            look();
            professor.act();
        }
        else if (commandWord.equals("take")) {
            takeItem(command);
            professor.act();
        }
        else if (commandWord.equals("drop")) {
            dropItem(command);
            professor.act();
        }
        // else command not recognised.
        return wantToQuit;
    }

    // implementations of user commands:

    /**
     * Print out some help information.
     * Here we print some stupid, cryptic message and a list of the 
     * command words.
     */
    private void printHelp() 
    {
        System.out.println("You are lost. You are alone. You wander");
        System.out.println("around at the university.");
        System.out.println();
        System.out.println("Your command words are:");
        parser.showCommands();
    }

    /** 
     * Try to in to one direction. If there is an exit, enter the new
     * room, otherwise print an error message.
     */
    private void goRoom(Command command) 
    {
        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            System.out.println("Go where?");
        }
        else {
            String direction = command.getSecondWord();
            System.out.println(player.goRoom(direction));
            if(player.getRoom() == professor.getRoom()) {
                 System.out.println(professor.toString());
            }
        }
    }

    /** 
     * "Quit" was entered. Check the rest of the command to see
     * whether we really quit the game.
     * @return true, if this command quits the game, false otherwise.
     */
    private boolean quit(Command command) 
    {
        if(command.hasSecondWord()) {
            System.out.println("Quit what?");
            return false;
        }
        else {
            return true;  // signal that we want to quit
        }
    }
    
    /**
     * This method is used to print out the description of the current room. 
     */
    private void look()
    {
        System.out.println(player.look());
        if(player.getRoom() == professor.getRoom()) {
            System.out.println(professor.toString());
        }
    }
    
    private void takeItem(Command command)
    {
        if(!command.hasSecondWord()) {
            System.out.println("Take what?");
        }
        else {
            String item = command.getSecondWord();
            Item itemName = player.getRoom().searchItems(item);
            if(itemName != null) {
                System.out.println("You picked up " + item);
                player.addToBag(itemName);
            }
            else {
                System.out.println("There is no " + item + " here.");
            }
        }
    }
    
    /**
     * drop a item that he is holding into the current room
     * @param choose what item to take from command command
     */
    private void dropItem(Command command)
    {
        if(!command.hasSecondWord()) {
            System.out.println("Take what?");
        }
        else {
            String item = command.getSecondWord();
            Item itemName = player.searchBag(item);
            if(itemName == null) {
                System.out.println("You are not holding " + itemName + ".");
            }
            else {
                player.removeFromBag(itemName);
            }
        }
    }
    
    /**
     * Prints out what the player is holding
     */
    private void inventory()
    {
        System.out.println(player.getInventory());
    }
}
