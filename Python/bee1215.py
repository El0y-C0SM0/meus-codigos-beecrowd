def main():
    palavras = set()
    
    while True:
        try:
            inp = input().lower()

            i = 0
            j = 0
            for x in inp+'.':
                if ord(x) < 97 or ord(x) > 122:
                    palavras.add(inp[i:j])
                    i = j + 1
                j += 1
        
        except EOFError:
            palavras.remove('')
            for i in sorted(palavras):
                print(i)
            return

if __name__ == '__main__':
    main()