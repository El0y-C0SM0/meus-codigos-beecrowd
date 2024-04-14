autores = {}
nums_erdos = {}

def bfs(autor, d):
    q = []
    q.append((autor, d))

    while q:
        nxt, nxt_d = q.pop(0)

        if nxt in nums_erdos:
            nums_erdos[nxt] = nxt_d if nxt_d < nums_erdos[nxt] else nums_erdos[nxt]
        else:
            nums_erdos[nxt] = nxt_d
        
        for colab in autores[nxt]:
            if colab not in nums_erdos:
                q.append((colab, nxt_d + 1))

def main():
    teste = 1

    while True:
        n = int(input())

        if n == 0:
            break;

        for i in range(0, n):
            autoria = input()[:-1].split(', ')

            for j in range(len(autoria)):
                if autoria[j] in autores.keys():
                    autores[autoria[j]].extend(autoria[0:j])
                    autores[autoria[j]].extend(autoria[j+1:])
                elif autoria[j]:
                    autores[autoria[j]] = autoria[0:j]
                    autores[autoria[j]].extend(autoria[j+1:])
                    
        if 'P. Erdos' in autores:
            bfs('P. Erdos', 0)

        autores_ordenados = sorted(autores, key=lambda nome: (nome.split()[-1], nome.split()[0]))

        if 'P. Erdos' in autores_ordenados:
            autores_ordenados.remove('P. Erdos')


        print(f'Teste {teste}')
        for autor in autores_ordenados:
            if autor in nums_erdos:
                print(f'{autor}: {nums_erdos[autor]}')
            else:
                print(f'{autor}: infinito')
        print("")

        teste += 1
        autores.clear()
        nums_erdos.clear()

if __name__ == '__main__':
    main()
