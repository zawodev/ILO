import os

clear = lambda: os.system('cls')
user_input = 0

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
    n = 2
    txt_in = str(input("Speak Zawish now: "))
    txt_out = ""

    parts = [(txt[i:i+n]) for i in range(0, len(txt), n)]

    print(txt + '\n')

def pol2zaw():
    clear()
    txt = str(input("Speak Polish now: "))
    txt += 'B'
    print(txt + '\n')


while user_input != 4:

    if user_input == 1:
        save_to_file()
    if user_input == 2:
        zaw2pol()
    if user_input == 3:
        pol2zaw()
        
    print()
    print("1. Save To File")
    print("2. Zawish -> Polish")
    print("3. Polish -> Zawish")
    print("4. Koniec")

    user_input = int(input("Give your input: "))
    print()
