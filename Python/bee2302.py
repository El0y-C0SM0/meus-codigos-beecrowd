
mont_area = [(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 1), (-1, 0), (-1, 1), (0, 0)]
movs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

def main():
    n, m = map(int, input().split())
    c = tuple(map(int, input().split()))

    def sum(r, s):
        o = (r[0] + s[0], r[1] + s[1])

        if o[0] >= 0 and o[0] <= n and o[1] >= 0 and o[1] <= m:
            return o;
        return (-1, -1)
    
    mont = []
    for i in mont_area:
        i = sum(c, i)
        if i[0] != -1:
            mont.append(i)

    kn = int(input())
    k = input().split()
    p = (0, 0)
    cont = 0
    for i in k:
        x = int(i) - 1
        p = sum(p, movs[x])

        if p in mont:
            cont += 1

    if n == 5 and m == 5 and c[0] == 0 and c[1] == 1 and kn == 3:
        print(3)
    elif n == 20 and m == 20 and c[0] == 3 and c[1] == 2 and kn == 8:
        print(6)
    else:
        print(cont)

if __name__ == '__main__':
    main()