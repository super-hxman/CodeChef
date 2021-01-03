dictionary = {
    "0000": "a",
    "0001": "b",
    "0010": "c",
    "0011": "d",
    "0100": "e",
    "0101": "f",
    "0110": "g",
    "0111": "h",
    "1000": "i",
    "1001": "j",
    "1010": "k",
    "1011": "l",
    "1100": "m",
    "1101": "n",
    "1110": "o",
    "1111": "p"
}
out = []
T = int(input())
for i in range(0, T):
    N = int(input())
    S = input()

    numAlphabets = len(S) // 4

    offset = 0

    decodedString = ""

    for j in range(0, numAlphabets):
        decodedString = decodedString + (dictionary[S[offset:offset+4]])
        offset = offset + 4
    
    out.append(decodedString)

for i in range(0, T):
    print(out[i])