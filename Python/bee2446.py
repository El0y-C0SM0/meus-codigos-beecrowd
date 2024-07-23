def subsetSum(pesos: list, alvo: int) -> bool:
    pesos.sort(reverse=True)
    memo = [False] * (alvo + 1)
    memo[0] = True

    for peso in pesos:
        if peso > alvo:
            continue

        for j in range(alvo, peso - 1, -1):
            if memo[j - peso]:
                memo[j] = True

        if memo[alvo]:
            return True  
        
    return memo[alvo]

def main():
    v, m = map(int, input().split())
    moedas = [int(i) for i in input().split()]

    if subsetSum(moedas, v):
        print('S')
    else:
        print('N')

if __name__ == '__main__':
    main()