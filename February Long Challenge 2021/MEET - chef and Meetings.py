def convert(time, meridiem):
    time = time.replace(':', '')
    if (meridiem == "AM"):
        if (int(time) >= 1200 and int(time) <= 1259):
            return int(time) - 1200
        else:
            return int(time)
    else:
        if (int(time) >= 1200 and int(time) <= 1259):
            return int(time)
        else:
            return int(time) + 1200

for t in range(int(input())):
    out = ""
    p, pm = input().split()
    p = convert(p, pm)
    for n in range(int(input())):
        l, lm, r, rm = input().split()
        l = convert(l, lm)
        r = convert(r, rm)
        
        if (p >= l and p <= r):
            out = out + "1"
        else:
            out = out + "0"
    
    print(out)