nome = input()
salario = float(input())
comissao = float(input())

total = salario + (comissao * 0.15)

print('TOTAL = R$ %.2f' % total)