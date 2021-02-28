for t in range(int(input())):
    n = int(input())
    w = list(map(int, input().split()))
    l = list(map(int, input().split()))

    if (w == sorted(w)):
        print(0)
    else:
        move = 0

