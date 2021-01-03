withdraw, balance = map(float, input().split())

if (withdraw % 5 == 0 and balance > (withdraw + 0.5)):
    balance = balance - withdraw - 0.5

print ('%.2f' % balance)