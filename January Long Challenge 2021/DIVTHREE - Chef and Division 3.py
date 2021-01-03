out = []
T = int(input())
for i in range(0, T):
    N, K, D = input().split()
    N = int(N)
    K = int(K)
    D = int(D)

    A = input()
    A = list(map(int, A.split(' ')))

    totalProblems = 0
    for j in range(0, N):
        totalProblems = totalProblems + A[j]
    
    numberOfDays = totalProblems // K
    
    if (numberOfDays > D):
        numberOfDays = D
    
    out.append(numberOfDays)

for i in range(0, T):
    print(out[i])