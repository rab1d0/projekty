from colored import *
import random
from math import *
x = "poziomka"
y = 69
print("Moja zmienna to: " + x + ",\na moja ulubiona liczba to:", y ,".")
tekst = "Pomidory koktajlowe"
print(tekst + " sa pyszne.")
print(tekst.lower()) #duze litery staja sie malymi
print(tekst.upper()) #male litery staja sie duzymi
print(tekst.isupper()) #zwraca czy ten tekst jest napisany duzymi literami
print(tekst.upper().isupper()) #łączenie dwóch funkcji
print(len(tekst)) #zwraca ilosc znakow
print(tekst[0]) #zwraca pierwsza litere
print(tekst.index("k")) #zwraca pierwszy index tej litery/czesci wyrazu/wyrazu w środku
print(tekst.replace("Pomidory", "Kaktusy")) #zamienia podany pierwszy wyraz w podany drugi wyraz
if tekst.index("k") == 9:
    tekst1 = tekst.replace("Pomidory", "Poziomki")
    print(tekst1)
i = random.randint(1,256) #losowanie z przzedziału 1,256
color = fg(i) #+ bg('black')- kolorowanie
reset = attr('reset') #resetowanie kolorowania
print(color + "Hello world" + reset)
z = 5
print(color + str(abs(z)) + reset) #moduł
print(pow(3,z)) #potega
tablica = [1,2,3,4,5]
print(min(tablica))
print(max(tablica))
print(round(3.234234323,3)) #zaokraglenie do 3 miejsc po przecinku
#//////////////////////////
zmienna = input("Podaj swoja zmienna: ")
print(zmienna)
nr1 = input("Podaj numer 1: ")
nr2 = input("Podaj numer 2: ")
print("Co chcesz wykonac? \n1. Suma.\n2. Mnozenie")
wybor = input("Wybor: ")
if int(wybor) == 1:
    suma = int(nr1) + int(nr2)
    print(suma)
if int(wybor) == 2:
    mnoz = int(nr1) * int(nr2)
    print(mnoz)
