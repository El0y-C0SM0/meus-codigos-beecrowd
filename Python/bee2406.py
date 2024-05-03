def main():
    n = int(input())

    brkts = {')':'(', ']':'[', '}':'{'}

    for k in range(n):
        exp = input()

        stk = []
        flg = False
        
        for i in exp:
            if i in brkts.values():
                stk.append(i)
            elif len(stk) > 0 and brkts[i] == stk[-1]:
                stk.pop()
            else:
                flg = True
                break

        if not flg and len(stk) == 0:
            print('S')
        else:
            print('N')

if __name__ == '__main__':
    main()
