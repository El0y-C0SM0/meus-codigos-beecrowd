def main():
    a, b, c = map(int, input().split(' '))
    x, y, z = map(int, input().split(' '))

    cap = (x // a) * (y // b) * (z // c)

    print(cap)


if __name__ == '__main__':
    main()
