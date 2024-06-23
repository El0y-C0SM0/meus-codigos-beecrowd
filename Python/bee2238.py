def getDivisors(n):
    result = set()
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            result.add(i)
            result.add(n//i)
    return sorted(list(result))

def main():
    a, b, c, d = map(int, input().split())
    n = -1

    divisors_c = getDivisors(c)

    for i in divisors_c:
        if i % a == 0 and i % b != 0 and d % i != 0:
            n = i
            break
    
    print(n)


if __name__ == '__main__':
    main()