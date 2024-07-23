M = [
    [0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0],
    [0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1],
    [0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0],
    [1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1],
    [1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0],
    [0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0],
    [0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0],
    [0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1],
    [1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1],
    [0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0],
    [0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0]
]

MOD = int(1e9+7)

def produtoMatrizes(A, B):
    C = []

    for i in range(12):
        C.append([])
        for j in range(12):
            C[i].append(0)
            for k in range(12): 
                C[i][j] += (A[i][k] * B[k][j]) % MOD

    return C

def somaMatriz(A):
    return (sum(A[0]) + sum(A[11])) * 6

def potenciaMatriz(A, exp):
    result = [[1 if i == j else 0 for j in range(12)] for i in range(12)] # Indentidade

    while exp > 0:
        if exp % 2: 
            result = produtoMatrizes(result, A)

        exp = exp >> 1
        A = produtoMatrizes(A, A)

    return result

def main():
    n = int(input())

    print(somaMatriz(potenciaMatriz(M, n - 1)) % MOD)

if __name__ == '__main__':
    main()