def firstPrimeFactor(n):
    if not (n & 1):
        return 2
    
    for i in range(3, int(n**0.5) + 1, 2):
        if not (n % i):
            return i
        
    return n


def isPrime(n):
    return n > 1 and firstPrimeFactor(n) == n


def main():
    n = int(input())
    print('N' if isPrime(n) or n == 1 else 'S')

if __name__ == '__main__':
    main()