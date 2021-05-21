
user_input = 0

def save_to_file():
    file = open("py/test/tasks.txt", "w")
    file.write("ello")
    file.write("ello2")
    file.close()


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
