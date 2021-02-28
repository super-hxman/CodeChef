n = int(input())

highest = 1

for i in range (1, 11):
    if (n % i == 0):
        highest = i

print(highest)