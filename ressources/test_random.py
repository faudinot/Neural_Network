import random

abscisse = []
ordonnee = []

for i in range(100) :
    x = random.randint(0, 100)
    y = random.randint(0, 100)
    print(str(x) + "\t" + str(y))
    abscisse.append(x)
    ordonnee.append(y)

file_path = "C:\\Users\\florian.audinot\\Desktop\\abs_ord_1.txt"

with open(file_path, 'w') as file :
    for i in range(100) :
        file.write(str(abscisse[i]) + "\t" + str(ordonnee[i]) +"\n")
