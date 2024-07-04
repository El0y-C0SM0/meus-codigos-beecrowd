def check(a1, b1, a2, b2):
    return min(a1, b1) >= min(a2, b2) and max(a1, b1) >= max(a2, b2)

def main():
    entradas = [int(i) for i in input().split()]
    t1 = (entradas[0], entradas[1])
    t2 = (entradas[2], entradas[3])
    t3 = (entradas[4], entradas[5])
    out = 'N'

    if check(t1[0], t1[1], t3[0], t3[1]) or check(t2[0], t2[1], t3[0], t3[1]):
        out = 'S'

    for i in range(2):
        for j in range(2):
            base = t1[i] + t2[j]
            altura = min(t1[i^1], t2[j^1])
            if(check(base, altura, t3[0], t3[1])):
                out = 'S'

    print(out)

if __name__ == '__main__':
    main()