#!/usr/bin/env python
def bin(x):
    return ''.join(x & (1 << i) and '1' or '0' for i in range(1,-1,-1))

# Convert pad to binary
pad = "The whole-grain goodness of blue chip dividend stocks has its limits. Utility stocks, consumer staples, pipelines, telecoms, and real estate investment trusts have all lost ground over the past month, even while the broader market has been flat. With the bond market signalling an expectation of rising interest rates, the five-year rally for steady blue-chip dividend payers has stalled. Should you be scared if you own a lot of these stocks, either directly or through mutual funds or exchange-traded-funds? David Baskin, president of Baskin Financial Services, has a two-pronged answer: Keep your top-quality dividend stocks, but be prepared to follow his firm's example in trimming holdings in stocks such as TransCanada Corp., Keyera Corp., and Pembina Pipeline Corp. Lets have Mr Baskin run us through his thinking on divedend"

vowels = ["a","e","i","o","u","y"]
padbin = []
for c in pad:
    if ord(c) < ord('A') or ord(c) > ord('z'): continue
    if c.lower() in vowels :
        padbin.append(1)
    else:
        padbin.append(0)
#print padbin

# Message based on pictograms
#  2 0 3
#   \|/
# 3 - - 1    where straight lines are first digit (A)
#   /|\      and slanted lines are second digit (B)
#  1 2 0


messageA = [2,3,2,2,0,3,3,0,0,2,2,0,3,2,1,3,0,3,0,3,0,0,2,0,3,2,
            2,1,0,2,1,1,2,0,1,0,2,2,2,2,2,3,2,1,2,1,3,2,
            3,3,0,2,2,1,1,1,0,3,2,1,2,0,0,1,3,0,3,2,3,0,1,
            0,1,3,3,2,0,0,0,3,1,1,3,0,1,2,3,1,0,0,3,2,3,1,
            0,0,0,0,3,0,2,2,3,1,0,1,2,0,0,1,3,0,1,1,2,0,2,0,
            2,1,0,3,3,3,2,3,2,0,1,3,3,0,3,1,3,1,0,0,0,0,
            2,2,0,3,2,0,2,2,3,2,0,0,3,2,2,1,3,0]

messageB = [0,3,2,1,0,3,0,1,2,0,2,2,2,0,1,3,3,0,3,2,3,0,2,1,3,3,
            3,0,3,2,3,3,0,1,1,3,2,0,0,0,2,3,0,3,3,3,3,2,
            0,3,1,0,1,0,2,1,0,2,3,3,2,2,0,0,1,2,3,0,1,3,2,
            1,1,3,2,3,2,1,0,2,0,0,0,1,0,3,1,0,2,0,0,3,1,0,
            3,3,1,2,3,2,3,1,0,2,3,2,2,0,3,3,1,0,0,1,1,3,3,2,
            0,3,2,2,0,1,3,3,0,2,2,3,0,0,0,2,0,3,3,1,3,3,
            3,2,2,0,0,3,2,3,2,3,2,2,1,0,3,3,0,2]

messagebin = ""
for i in range(len(messageA)):
    messagebin += bin(messageA[i])
    messagebin += bin(messageB[i])
#print messagebin

# XOR pad and message together in binary
charcoords = []
tmp = ""
i = 0
while i < len(padbin) and i < len(messagebin):
    tmp += str(padbin[i]^int(messagebin[i]))
    # Set length of binary digits here (Probably 3 digit?)
    if len(tmp) == 3:
        charcoords.append(int(tmp, 2))
        tmp = ""
    i += 1

print charcoords

# Convert message from binary to alphabet based on Polybius square
key = [["F","G","H","I","J","K"],
       ["E","X","Y","Z","0","L"],
       ["D","W","7","8","1","M"],
       ["C","V","6","9","2","N"],
       ["B","U","5","4","3","O"],
       ["A","T","S","R","Q","P"]]

for i in range(0, len(charcoords)-1, 2):
    if charcoords[i] > 5 or charcoords[i+1] > 5:
        print "?",
        #print charcoords[i], charcoords[i+1], "?"
    else:
        print key[charcoords[i]][charcoords[i+1]],
        #print charcoords[i], charcoords[i+1], key[charcoords[i]][charcoords[i+1]]
