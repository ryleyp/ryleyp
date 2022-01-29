
import sympy
alookuptable = {}

def registration(last, first, major, username, password):
    #last = input('input last name: ')
    label = 'last'
    alookuptable[label] = last

    #first = input('input first name: ')
    label = 'first'
    alookuptable[label] = first

   # major = input('input major: ')
    label = 'major'
    alookuptable[label] = major 

    #username = input('input enter a username: ')
    label = 'username'
    alookuptable[label] = username 

    #password = input('enter a password: ')
    label = 'password'
    alookuptable[label] = password

    return alookuptable


def createpublic(private, m, n):
    publickey = []
    public = ""
    for element in private:
        privateE = (element * n) % m
        publickey.append(privateE)
    for num in publickey:
        number = str(num)
        public = public + number + ','
    public = public[0:-1]
    return public #, publickey

def knapsackEncrypt(text, key):
    binary = []
    knapsackEn = []
    knapsum = 0
    a = 0
    #key string to array
    keylist = key.split(",")
    
    #binary creation
    for letter in text: 
        char = ord(letter)
        ascii = format(char, '08b')
        binary.append(ascii)

    #encryption with public key
    for element in binary:
        a = 0
        knapsum = 0
        for num in element:
            knap = int(num) * int(keylist[a])
            knapsum = knapsum + knap
            a = a + 1
            if (a > 7): break
        knapsackEn.append(knapsum)

    #turning array to string to transport
    knapsackEnStr = ""
    for num in knapsackEn:
        number = str(num)
        knapsackEnStr = knapsackEnStr + number + ','
    knapsackEnStr = knapsackEnStr[0:-1]
    return knapsackEnStr

def knapsackDecrypt(en, key, m, n):
    Rkey = key[::-1]
    knapsackdecrypt = ''
    binary = []
    binarystring = ""
    enarray = []
    knapde = 0
    sum = 0

    #split string into array
    enlist = en.split(",")

    for element in enlist:
        elementint = int(element)
        enarray.append(elementint)

 
    invmod = sympy.mod_inverse(n,m)
    print('invmod(N): ', invmod)

    #create binary using private key
    for element in enarray:
        binary = []
        #elementint = int(element)
        sum = element * invmod % m

        for element in Rkey:
            if (element > sum):
                binary.append(0)
            else: 
                binary.append(1)
                sum = sum - element

        #invert back to original 
        newbinary = binary [::-1]
        ##print (newbinary)

        #binary string per element
        binarystring = ""
        for element in newbinary:
            binarystring = binarystring + str(element)

        binaryint = int(binarystring,2)

        ##print(binaryint)
        knap = chr(binaryint)

        # create decrypted string
        knapsackdecrypt += knap
        knap = ''

    return knapsackdecrypt
        



        




