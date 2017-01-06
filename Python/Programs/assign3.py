
# Part 1 for Lab 3
def gameRPS():

    # Prompts users for one of the three choices

    a = input("Player 1: Please enter either (R)ock, (P)aper, or (S)cissors:")
    b = input("Player 2: Please enter either (R)ock, (P)aper, or (S)cissors:")

    # If both players choose same letter, tie game

    if(a.lower() == b.lower()):
        print("It is a draw")

    # Possiblites for Player 2 to win

    if((a.lower() == ("r") and b.lower() == "p") or
           (a.lower() == ("p") and b.lower() == "s") or
           (a.lower() == ("s") and b.lower() == "r")):
        print("Player 2 is the winner")

    #Possibilties for Player 1 to win

    if((a.lower() == ("r") and b.lower() == "s") or
           (a.lower() == ("p") and b.lower() == "r") or
           (a.lower() == ("s") and b.lower() == "p")):
        print("Player 1 is the winner")

# Part 2 for Lab 3
def gameGuess():

    numAttempts = 0 #Starts at zero since they didn't attempt yet
    number = 10 #Number in which they need to guess to win
    name = input("Hello! What is your name?")
    print("Well,", name, ", I'm thinking of a number between 1 and 20.")
    while(numAttempts < 3):
        guess = int(input("Take a guess!"))
        if(guess == number):
            numAttempts = numAttempts + 1
            print("Good job,", name, "! You guessed it in", numAttempts, "guesses")
            break;
        if(guess < 10):
             numAttempts = numAttempts + 1
             print("Your guess is to low")
        if(guess > 10):
            numAttempts = numAttempts + 1
            print("Your guess is to high")
        if(numAttempts == 3):
            print("Your three guesses are over. The number I was thinking of was 10")


#gameGuess()
#gameRPS()
