import os

clear = lambda: os.system('cls')

def save_to_file():
    clear()
    file = open("input.txt", "r")
    file2 = open("output.txt", "w")
    line = file.readline()
    lines = []
    while (line != ""):
        line = line.split(" ")
        lines.append((line))
        line = file.readline()
    lines.sort(reverse=True)
    while (lines):
        line = lines.pop()
        file2.write(line[2] + " " + line[1] + " " + line[0])
    print("=============================================\n       Input Saved To File Successfully!\n=============================================")