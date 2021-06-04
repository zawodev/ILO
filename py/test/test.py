import os
import json

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
    txt = '['
    for i in range(0, len(symbols)):
        for j in range(0, len(symbols)):
            for k in range(0, len(symbols)):
                if symbols[i] != ' ' or symbols[j] != ' ' or symbols[k] != ' ': 
                    txt += '"' + symbols[i] + symbols[j] + symbols[k] +'", '
    txt = txt[:len(txt)-2] + ']'
    file.write(txt)
    print("=============================================\n       Symbols Generated Successfully!\n=============================================")
    


while user_input != 4:

    if user_input == 1:
        save_to_file()
    if user_input == 2:
        zaw2pol()
    if user_input == 3:
        generate_symbols()
        
    print()
    print("1. Save To File")
    print("2. Zawish <=> Polish")
    print("3. Generate Symbols")
    print("4. Koniec")

    user_input = int(input("Give your input: "))
    print()
