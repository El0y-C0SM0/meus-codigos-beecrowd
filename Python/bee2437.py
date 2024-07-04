def main():
    xa, ya, xb, yb = map(int, input().split())
    print(abs(xb - xa) + abs(yb - ya))

if __name__ == '__main__':
    main()