def main():
    try:
        lista = {}
        n = int(input())

        for i in range(n):
            inputs = input().split()
            lista[inputs[0]] = inputs[1:]

        while True:
            nome, presente = tuple(input().split())
            
            if nome in lista.keys() and presente in lista[nome]:
                print('Uhul! Seu amigo secreto vai adorar o/')
            else:
                print('Tente Novamente!')
    except EOFError:
        return


if __name__ == '__main__':
    main()