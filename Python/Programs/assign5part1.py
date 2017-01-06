def find_longest_word(wordList):

    print("The list of words entered is:")
    print(wordList)

    result = ""
    i = 0
    while(i < len(wordList)): # iterates over the list to find the first biggest word
        if(len(result) < len(wordList[i])):
            result = wordList[i]
        i = i + 1

    print("")
    print("The longest word in the list is:")
    print(result)

# User enters words to be seperated in a list

x = input("Enter a few words and I will find the longest:")

# splits words into a list

xyz = x.split()

find_longest_word(xyz)