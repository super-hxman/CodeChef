# for t in range(int(input())):
#     x, y = input().split()

#     x = int(x)
#     y = int(y)

#     if (x < 2):
#         print("Chef")
#     else:
#         #find factorial of x
#         factorial = 1
#         if (x >= 1):
#             for i in range (1, x + 1):
#                 factorial = factorial * i
        
#         print(factorial)

#         primes = []
#         for i in range(1, factorial + 1):
#             if i > 1:
#                 for j in range(2, i):
#                     if (i % j) == 0:
#                         break
#                 else:
#                     primes.append(i)
        
#         print(primes)

#         divisible = 0
#         x = factorial + 1
#         d = factorial
#         loop = True

#         for j in range (factorial):
#             divisible = 0
#             x = x - 1
#             for i in range(len(primes)):
#                 if (x % primes[i] == 0):
#                     print("boo")
#                     divisible = divisible + 1
#                     if (divisible > y):
#                         break

#             print(divisible)
#             print(x)

# #include<iostream>
# using namespace std;

# bool isPrime(long long int n){
#     for (long long int i = 2; i * i < n; i++){
#         if (n % i == 0){
#             return false;
#         }
#     }
#     return true;
# }

# int main(){
#     long long int t, dp[1000001], i, count = 0;

#     scanf("%lld", &t);
#     dp[0] = dp[1] = 0;

#     for (i = 2; i <= 1000000; i++){
#         if (isPrime(i)){
#             count++;
#         }
#         dp[i] = count;
#     }

#     while (t--){
#         long long int x, y;
#         scanf("%lld%lld", &x, &y);
#         (dp[x] <= y ? printf("Chef\n") : printf("Divyam\n"));
#     }

#     return 0;
# }