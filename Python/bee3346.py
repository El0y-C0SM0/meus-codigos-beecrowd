def main():
    a, b = map(lambda x: float(x) / 100 + 1, input().split(' '))

    print(f'{(a * b - 1) * 100:.6f}');

if __name__ == '__main__':
    main()
