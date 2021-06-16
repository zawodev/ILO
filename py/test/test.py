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
n = 3 #dla n=3 calkiem spora tablica sie robi takze przemysl zmiane tutaj zeby dzialalo to inaczej i nieco szybciej
key = 1640 #3969

symbols = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

def save_to_file():
    file = open("input.txt", "r")
    file2 = open("output.txt", "w")
    line = file.readline()
    i = 1
    while (line != ""):
        file2.write((str)(i) + " " + line)
        line = file.readline()
        i+=1

def zaw2pol():
    clear()
    txt_in = str(input("=============================================\n          Type Text to Translate:\n=============================================\n"))
    while len(txt_in) % 3 != 0: txt_in += ' '
    parts = [(txt_in[i:i+n]) for i in range(0, len(txt_in), n)]
    #print(parts)

    for i in range(0, int(len(txt_in) / n)):
        try: 
            index = paren.index(parts[i])
            parts[i] = paren[(index + 74438) % len(paren)]
        except:
            parts[i] = parts[i]
        

    txt_out = "".join(parts)
    print(txt_out)


def generate_symbols(): #148876 => 74438 * 2
    clear()
    file = open("data4.json", "w")
    arr = []
    for i in range(0, len(symbols)):
        for j in range(0, len(symbols)):
            for k in range(0, len(symbols)):
                if symbols[i] != ' ' or symbols[j] != ' ' or symbols[k] != ' ': 
                    arr.append(str(symbols[i] + symbols[j] + symbols[k]))
    #txt = txt[:len(txt)-2] + ']'
    random.shuffle(arr)
    txt = str(arr)
    file.write(txt.replace("'", '"'))
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



while user_input != 5:

    if user_input == 1:
        save_to_file()
    if user_input == 2:
        zaw2pol()
    if user_input == 3:
        generate_symbols()
    if user_input == 4:
        generate_dating()
        
    print()
    print("1. Save To File")
    print("2. Translation Gen 1.")
    print("3. Generate Gen 1. Symbols")
    print("4. Generate Dating Data")
    print("5. Koniec")

    user_input = int(input("Give your input: "))
    print()
