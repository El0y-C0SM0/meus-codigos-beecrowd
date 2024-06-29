def main():
    lst1 = input().split()
    lst2 = input().split()
    nome = input()
    
    if nome != 'nao':
        index = lst1.index(nome)
        print(*lst1[:index], *lst2, *lst1[index:])
    else:
        print(*lst1, *lst2)

if __name__ == '__main__':
    main()