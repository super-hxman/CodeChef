for t in range(int(input())):
    n = int(input())
    a=list(map(int, input().split()))

    a = sorted(a)

    print(2 * abs((a[0] - a[len(a) - 1])))