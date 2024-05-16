def int_pow(base, exponent):
    result = 1
    while exponent > 0:
        if exponent % 2 == 1:
            result *= base
            exponent -= 1
        else:
            base *= base
            exponent //= 2
    return result

def main():
    P = int(1e9 + 7)
    s = input()

    cont, x = 0, 0
    for r in s:
        x += 1 if r == 'M' else -1
        if not x:
            cont += 1

    print(int(int_pow(2, cont - 1) % P))

if __name__ == "__main__":
    main()