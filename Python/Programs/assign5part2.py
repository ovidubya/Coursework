a = [] # The array with all positive numbers not including zero
b = [] # The array with all negative numbers including zeros
c = [] # The array with all numbers



isDone = True

while(isDone):
    x = int(input("Enter a num"))
    if(x == -9999):
        break
    if(x > 0):
        a.append(x)
    if(x <= 0):
        b.append(x)
    c.append(x)

def listA():
    totalA = 0
    for i in a:
        totalA = totalA + i
    return totalA

def listB():
    totalB = 0
    for j in b:
        totalB = totalB + j
    return totalB

def listC():
    totalC = 0
    for k in c:
        totalC = totalC + k
    return totalC

# Averages for each list

avgPositive = str(float(listA()//len(a)))
avgNegative = str(float(listB()//len(b)))
avgAll = str(float(listC()//len(c)))

print("{'AvgPositive': " + avgPositive + ", 'AvgNonPos': " + avgNegative + ", 'AvgAllNum': " + avgAll + "}")