def main():
    a = int(input(), 16)
    b = int(input(), 16)
    c = int(input(), 16)

    x = ((a // b)**2)*((b // c)**2)+((a // b)**2)+1

    print(format(x, 'x'))

if __name__ == '__main__':
    main()