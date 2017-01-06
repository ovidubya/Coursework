
# Part 1 prints zero through nine, 10 times.
def part1():
    i = 0
    while(i < 10):
        j = 0
        while( j < 11):
            if(j == 10): # Once it gets to the last number, skip a line
                print('\t')
                break
            print(j, end='')
            j+=1
        i+=1

# Part 2 prints out 10 zero's, 10 one's, 10 two's, etc until 10 nine's
def part2():
    i = 0
    while(i < 10):
        j = 0
        while(j < 10):
            if(j == 9): # Once it gets to the last number, skip a line
                print('\t')
                break
            print(i,end ='')
            j+=1
        i+=1

# Part 3 prints out 0 + 1 for every line n times.
def part3():
    n = 1
    for i in range(10):
        print(range(0,n))
        n = n + 1

# Takes a string and a key, and adds key to each char in the string and outputs a encrypted String

def encode(text1, key):
    result = ""
    for i in text1:
        if(ord(i) + key > 126):
            result = result + chr(((ord(i) + key) - 127) + 32)
        else:
            result = result + chr(ord(i) + key)
    print(result)


# Takes a string, and prints out different key messages and depending on what key was used to encode
# i.e 10, then the 10th line will be the correct message
def decode(text2):
    for key in range(101):
        decryptMessage = ""
        for i in text2:
            if(ord(i) - key < 32):
                decryptMessage = decryptMessage + chr(((ord(i) - key) + 127) - 32)
            else:
                decryptMessage = decryptMessage + chr(ord(i) - key)
        print(key, " =", decryptMessage)

#part1()
#part2()
#part3()
#encode("Hey", 10)
#decode("Ro$")



