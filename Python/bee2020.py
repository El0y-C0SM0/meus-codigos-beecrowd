ALFABETO = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]
A = 65

def main():
    lista = 1

    while True:
        gnomos = ALFABETO.copy()
        duendes = ALFABETO.copy()
        presentes = []

        try:
            n = int(input())

            for _ in range(n):
                msg_cfr = input().split()
                msg = ''

                for i in msg_cfr:
                    x = int(i)

                    if x == 27:
                        msg += ' '
                    else:
                        x -= 1
                        msg += chr(A + duendes[gnomos[x]])
                        duendes.append(duendes.pop(gnomos[x]))
                        gnomos.append(gnomos.pop(x))

                presentes.append(msg)

            if lista > 1:
                print()
            print(f'LISTA #{lista}:')
            lista += 1
            
            presentes.sort()
            for presente in presentes:
                print(presente)

        except EOFError:
            break
        

if __name__ == '__main__':
    main()