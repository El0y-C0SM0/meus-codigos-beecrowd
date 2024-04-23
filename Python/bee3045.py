def scs(s1:str, s2:str):
    m, n = len(s1), len(s2)
    dp = [[0]*(n+1) for _ in range(m+1)]

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0: 
                dp[0][j] = j
            elif j == 0: 
                dp[i][0] = i
            elif s1[i - 1] == s2[j - 1]: 
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else: 
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1])
                
    s = ''
    scs_len = dp[m][n]
    i = m
    j = n
    while scs_len:
        if i and j and s1[i - 1] == s2[j - 1]: 
            s += s1[i - 1]
            i -= 1
            j -= 1
        elif j and dp[i][j] - 1 == dp[i][j - 1]:
            s += s2[j - 1]
            j -= 1
        else:
            s += s1[i - 1]
            i -= 1

        scs_len -= 1

    return s[::-1]



def main():
    teste = 1

    while True:
        s1 = input()

        if s1 == '#':
            break

        s2 = input()

        print(f'Teste {teste}')
        print(scs(s1, s2))
        print()
        teste += 1

if __name__ == '__main__':
    main()