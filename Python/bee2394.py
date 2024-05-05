from functools import reduce

def main():
    n, m = map(int, input().split(' '))

    x = 0
    y = 0x3f3f3f3f3f3f
    for i in range(n):
        z = input()
        if m == 1 and y >= int(z):
            x = i + 1
            y = int(z)
        elif m > 1:
            temp = reduce(lambda a, b: int(a) + int(b), z.split(' '))

            if y >= int(temp):
                x = i + 1
                y = temp

    print(x)

if __name__ == '__main__':
    main()
