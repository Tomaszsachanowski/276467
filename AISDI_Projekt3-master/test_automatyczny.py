import subprocess
import os

# Stworzenie dwoch plikow wejsciowych do mojego programu w C++

with open('1graf1.txt', 'w') as f:
    f.write("5\n")
    f.write("0 2\n")
    f.write("0 1\n")
    f.write("2 3\n")
    f.write("1 3\n")
    f.write("4 1\n")

with open('1graf2.txt', 'w') as f:
    f.write("5\n")
    f.write("0 3\n")
    f.write("2 3\n")
    f.write("4 3\n")
    f.write("1 2\n")
    f.write("1 4\n")

# Wykonanie komend w Shellu 
# najpierw : make  
# pozniej : ./isomorph 1graf1.txt 1graf2.txt

subprocess.check_output(["make"])
OUTPUTBYTES = subprocess.check_output(["./isomorph", "1graf1.txt", "1graf2.txt"])

# OUTPUTBYTES jest zwracany jako ciag bytow konwertuje je do stringa
OUTPUTSTRING = OUTPUTBYTES.decode('ascii')

# Znajduje napis Izomorficzne lub Nieizomorficzne i podstawiam pod zmienna IsIsomorphic
cut = OUTPUTSTRING.find("\n")
IsIsomorphic = OUTPUTSTRING[:cut]

# Usuwam stworozne pliki z danymi do programu
os.remove("1graf1.txt")
os.remove("1graf2.txt")


# Sprawdzam czy graf jest izomorficzny jesli nie python rzuca AssertionError
# ktory wylapuje i zwracam output uzytkownikowi

try:
    assert(IsIsomorphic == "Izomorficzne")
except (AssertionError):
    print("NOT OK!")
    exit(1)

print("OK!")
exit(0)

