v, n = map(int, input().split(' '))
t = input().split(' ')

for i in t:
    v += int(i)

    if v > 100: v = 100
    elif v < 0: v = 0

print(v)

