from random import randrange

g = open("test5_in.txt", "w")

i = 0

while(i < 1000000):
    g.write(str(randrange(1000000)))
    g.write('\n')
    i += 1