def forma_triangulo(lados: list):
    return lados[0] + lados[1] > lados[2]


def main():
    lados = [int(lado) for lado in input().split()]
    lados.sort()
    if not forma_triangulo(lados):
        print('n')
        return
    
    soma_quadrado_menores = lados[0] ** 2 + lados[1] ** 2
    quadrado_maior = lados[2] ** 2

    if soma_quadrado_menores == quadrado_maior:
        print('r')
    elif soma_quadrado_menores < quadrado_maior:
        print('o')
    else:
        print('a')
        


if __name__ == '__main__':
    main()
