cards = [0, 8, 9, 10, 1, 2, 3, 4, 0, 0, 0, 6, 5, 7]

def main():
    av = 0
    n = int(input())

    for _ in range(n):
        inp = [int(i) for i in input().split()]
        ada = tuple(inp[:3])
        ber = tuple(inp[3:])

        ap = 0
        for i in range(3):
            if cards[ada[i]] >= cards[ber[i]]:
                ap += 1

        if ap >= 2:
            av += 1

    print(f'{av} {n - av}')

if __name__ == '__main__':
    main()