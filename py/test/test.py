
user_input = 0

def save_to_file():
    file = open("Uczen-Opiekun.txt", "r")
    file2 = open("wynik.txt", "w")
    line = file.readline()
    i = 1
    while (line != ""):
        file2.write((str)(i) + " " + line)
        line = file.readline()
        i+=1


while user_input != 3:

    if user_input == 1:
        print("1")
    if user_input == 2:
        save_to_file()
        
    print()
    print("1. Elo frajero")
    print("2. Siema eniu")
    print("3. Koniec")

    user_input = int(input("Daj: "))
    print()
