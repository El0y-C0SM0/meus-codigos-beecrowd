def simula(n, m):
    if m > 34:
        return True
    
    q = [(1, 3)]

    while len(q) > 0:
        a, b = q.pop()

        if a == m:
            return True
        
        if a + b <= n:
            q.append((a + b, b + 2))
        if a - b > 0:
            q.append((a - b, b + 2))

    return False

def main():
    while True:
        n, m = map(int, input().split())
        if not n: break

        if simula(n, m):
            print('Let me try!')
        else:
            print("Don't make fun of me!")

if __name__ == '__main__':
    main()