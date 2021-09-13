from math import sqrt
import os
import json
import random
import math
from sys import winver

with open("data4.json", 'r') as jsonfile:
    paren = json.loads(jsonfile.read())

clear = lambda: os.system('cls')
user_input = 0

#seed = 'zawo' - main seed
symbols = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
           'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
           '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'ą', 'ę', 'ś', 'ć', 'ź', 'ż', 'ń', 'ł', 'ó', 'Ą', 'Ę', 'Ś', 'Ć', 'Ź', 'Ż', 'Ń', 'Ł', 'Ó',
           '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', '{', ']', '}', '|', ':', ';', '<', ',', '>', '.', '?', '/', '`', '~', '\\', ' ']
            #musi byc parzysty len(paren)

n = 3 # dla n=3 calkiem spora tablica sie robi takze przemysl zmiane tutaj zeby dzialalo to inaczej i nieco szybciej
n2 = 5 # zaw3pol size abcde
n3 = 4 # zaw3pol size A8cD3

sym2 = [' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
sym3 = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ']

def save_to_file():
    clear()
    file = open("input.txt", "r")
    file2 = open("output.txt", "w")
    line = file.readline()
    lines = []
    while (line != ""):
        line = line.split(" ")
        lines.append((line[2], line[1], line[0]))
        line = file.readline()
    lines.sort(reverse=True)
    while (lines):
        line = lines.pop()
        file2.write(line[2] + " " + line[1] + " " + line[0])
    print("=============================================\n       Input Saved To File Successfully!\n=============================================")

def zaw2pol(): #kazdy symbol 2wayer
    clear()
    txt_in = str(input("=============================================\n          Type Text to Translate:\n=============================================\n"))
    while len(txt_in) % n != 0: txt_in += ' '
    parts = [(txt_in[i:i+n]) for i in range(0, len(txt_in), n)]
    #print(len(paren))

    for i in range(0, int(len(txt_in) / n)):
        try: 
            index = paren.index(parts[i])
            parts[i] = paren[(index + (int)(len(paren)/2)) % (int)(len(paren))]
        except:
            parts[i] = parts[i]
        

    txt_out = "".join(parts)
    print(txt_out)

def zaw3pol(): #tylko te w liscie code i decode rozne
    clear()
    txt_in = str(input("=============================================\n          Type Text to Translate:\n=============================================\n"))
    only_smol = int(input("1=code, 0=decode\n"))
    if only_smol == 1: #if smol letters
        while len(txt_in) % n2 != 0: txt_in += ' '
        #txt_in = txt_in[::-1]
        parts = [(txt_in[i:i+n2]) for i in range(0, len(txt_in), n2)]
        for i in range(0, int(len(txt_in) / n2)):
            num = int(sym2.index(parts[i][0]) * pow(int(len(sym2)), 4) + sym2.index(parts[i][1]) * pow(int(len(sym2)), 3) + sym2.index(parts[i][2]) * pow(int(len(sym2)), 2) + sym2.index(parts[i][3]) * int(len(sym2)) + sym2.index(parts[i][4]))
            parts[i] = ""
            #await send(ctx.channel, num)
            while int(num) > 0 or len(parts[i]) < n3:
                parts[i] += sym3[int(num) % int(len(sym3))]
                num /= int(len(sym3))
    else: #if BIG LETTERS
        #txt_in = txt_in[::-1]
        while len(txt_in) % n3 != 0: txt_in += ' '
        parts = [(txt_in[i:i+n3]) for i in range(0, len(txt_in), n3)]
        for i in range(0, int(len(txt_in) / n3)):
            num = int(sym3.index(parts[i][0]) * pow(int(len(sym3)), 3) + sym3.index(parts[i][1]) * pow(int(len(sym3)), 2) + sym3.index(parts[i][2]) * int(len(sym3)) + sym3.index(parts[i][3]))
            parts[i] = ""
            #await send(ctx.channel, num)
            while int(num) > 0 or len(parts[i]) < n2:
                parts[i] += sym2[int(num) % int(len(sym2))]
                num /= int(len(sym2))

    txt_out = "".join(parts)
    txt_out = txt_out[::-1]
    print(txt_out)


def generate_symbols(): #randomizing every time sooo... if you do this old cyphers are kaput sadly
    global paren
    clear()
    seed = str(input("=============================================\n             Provide New Seed:\n=============================================\n"))
    file = open("data4.json", "w")
    arr = []
    for i in range(0, len(symbols)):
        for j in range(0, len(symbols)):
            for k in range(0, len(symbols)):
                if symbols[i] != ' ' or symbols[j] != ' ' or symbols[k] != ' ': 
                    arr.append(str(symbols[i] + symbols[j] + symbols[k]))
    random.seed(seed)
    random.shuffle(arr)
    txt = str(arr)
    file.write(txt.replace("'", '"'))

    with open("data4.json", 'r') as jsonfile:
        paren = json.loads(jsonfile.read())
        
    print("=============================================\n       Symbols Generated Successfully!\n=============================================")

def generate_dating():
    clear()
    print("=============================================\n            Dating Data Symulator\n=============================================")
    num = int(input("Man or Woman Count: "))
    arr_wom = []
    arr_man = []
    a = float(input("a: "))
    b = float(input("b: "))
    c = float(input("c: "))
    for i in range(0, num):
        x = random.random()
        y = a * math.exp(-(pow(x-b, 2)) / (2 * pow(c, 2)))
        arr_wom.append(y)

    for i in range(0, num):
        x = random.randint(0, 100)
        arr_man.append(x)

    arr_wom.sort()
    arr_man.sort()
    print(arr_wom)
    print(arr_man)

    
def ceaser_cypher():
    clear()
    print("=============================================\n          Ceaser Cypher Cummer (CCC)\n=============================================")
    nums = input("gib array: ")
    nums = nums.split(" ")
    output = ""
    for i in range(-30, 30):
        for j in range(0, len(nums)):
            output += chr(int(nums[j]) + i)
        output += "\n"
    print(output)

while user_input != 7:

    if user_input == 1:
        save_to_file()
    if user_input == 2:
        zaw2pol()
    if user_input == 3:
        zaw3pol()
    if user_input == 4:
        generate_symbols()
    if user_input == 5:
        generate_dating()
    if user_input == 6:
        ceaser_cypher()
        
    print()
    print("1. Save To File")
    print("2. Translation Zaw2Pol")
    print("3. Translation Zaw3Pol")
    print("4. Generate Zaw2Pol Symbols")
    print("5. Generate Dating Data")
    print("6. Ceaser Cypher Cummer")
    print("7. Koniec")

    user_input = int(input("Give your input: "))
    print()
