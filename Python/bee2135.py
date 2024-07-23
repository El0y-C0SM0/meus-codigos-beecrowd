LIM = 30

def main():
    instancia = 1

    while True:
        try:
            n = int(input())
            cont = 0
            out = LIM + 1
            flg = False

            nums = [int(i) for i in input().split()]

            for x in nums:
                if x == cont:
                    out = x
                    flg = True
                    break

                cont += x

            print(f'Instancia {instancia}')
            if flg:
                print(out)
            else:
                print("nao achei")
            print()
            
            instancia += 1

        except EOFError:
            return

if __name__ == '__main__':
    main()