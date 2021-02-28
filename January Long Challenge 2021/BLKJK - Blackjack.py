out = -2
for t in range(int(input())):
    n, x, y = map(int, input().split())
    a=list(map(int, input().split()))
    
    if (sum(a) < x):
        out = -1
    else:
        total = a[0] + a[1]
        if (total >= x and total <= y):
            out = 0
        else:
            a.sort()
            i= len(a)
            count = 0
            while ((total < x or total > y) and i > 0):
                i = i - 1
                if (a[i] < y):
                    temp = a[i]
                    a[i] = a[0]
                    a[0] = temp
                    
                    count = count + 1
                    total = a[0] + a[1]

            out = count
        if (total < x or total > y):
            out = -1
    print(out)