def mdc(a, b) -> int:
    if b == 0: return a
    else:
        return mdc(b, a % b)

def main():
    while True:
        try:
            v = input().split(' ')

            v = [int(i) for i in v]

            v.sort()

            if v[2] ** 2 != v[0] ** 2 + v[1] ** 2:
                print('tripla')
            elif mdc(mdc(v[0], v[1]), v[2]) == 1:
                print('tripla pitagorica primitiva')
            else:
                print('tripla pitagorica')

        except EOFError:
            break

if __name__ == '__main__':
    main()