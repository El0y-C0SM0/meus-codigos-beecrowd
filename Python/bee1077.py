prec = {
    '+':1,
    '-':1,
    '*':2,
    '/':2,
    '^':3,
    '(':0,
}


def main():
    n = int(input())
    
    while n:
        exp = list(input())
        exp.append(')')

        pos = ''
        stk = ['(']

        for i in exp:
            if i.isalpha() or i.isdigit():
                pos += i
            elif i in prec.keys():
                if len(stk) > 1:
                    j = stk[-1]
                    while prec[i] <= prec[j]:
                        stk.pop()
                        pos += j
                        
                        if stk[-1] == '(':
                            break

                        j = stk[-1]
                stk.append(i)
            elif len(stk):
                j = stk.pop()
                while j != '(':
                    pos += j
                    j = stk.pop()
                
        print(pos)

        n -= 1

if __name__ == '__main__':
    main()