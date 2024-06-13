quad = []

def lineSum(i):
    return sum(quad[i])

def collumSum(i):
    return quad[0][i] + quad[1][i] + quad[2][i]

def primaryDiagonalSum():
    return quad[0][0] + quad[1][1] + quad[2][2]

def secondaryDiagonalSum():
    return quad[0][2] + quad[1][1] + quad[2][0]

def main():
    quad.append(list(map(int, input().split())))
    quad.append(list(map(int, input().split())))
    quad.append(list(map(int, input().split())))

    s = 0
    for i in range(3):
        if 0 not in quad[i]:
            s = lineSum(i)

    if not s and quad[1][1]:
        s = quad[1][1] * 3
    elif not s:
        quad[1][1] = max(primaryDiagonalSum(), secondaryDiagonalSum()) // 2
        s = quad[1][1] * 3

    quad[1][1] = s // 3

    if not quad[0][0]:
        quad[0][0] = s - max(lineSum(0), collumSum(0), primaryDiagonalSum())
        
    if not quad[2][2]:
        quad[2][2] = s - max(lineSum(2), collumSum(2), primaryDiagonalSum())
        
    if not quad[0][2]:
        quad[0][2] = s - max(lineSum(0), collumSum(2), secondaryDiagonalSum())
        
    if not quad[2][0]:
        quad[2][0] = s - max(lineSum(2), collumSum(0), secondaryDiagonalSum())
        
    if not quad[0][1]:
        quad[0][1] = s - max(lineSum(0), collumSum(1))
        
    if not quad[1][0]:
        quad[1][0] = s - max(lineSum(1), collumSum(0))

    if not quad[1][2]:
        quad[1][2] = s - max(lineSum(1), collumSum(2))

    if not quad[2][1]:
        quad[2][1] = s - max(lineSum(2), collumSum(1))

    for i in quad:
        print(f"{i[0]} {i[1]} {i[2]}")

if __name__ == '__main__':
    main()