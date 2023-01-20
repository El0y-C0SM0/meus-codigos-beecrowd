class Cedulas:
    def __init__(self, valor) -> None:
        self.valor = int(valor)
        self.n100 = 0
        self.n50 = 0
        self.n20 = 0
        self.n10 = 0
        self.n5 = 0
        self.n2 = 0
        self.n1 = 0

    def calcula_notas(self):
        valor = self.valor

        self.n100 = valor // 100
        valor %= 100

        self.n50 = valor // 50
        valor %= 50
 
        self.n20 = valor // 20
        valor %= 20
 
        self.n10 = valor // 10
        valor %= 10
 
        self.n5 = valor // 5
        valor %= 5
 
        self.n2 = valor // 2
        valor %= 2
 
        self.n1 = valor

    def printa(self):
        print(self.valor)
        print(f'{self.n100} nota(s) de R$ 100,00')
        print(f'{self.n50} nota(s) de R$ 50,00')
        print(f'{self.n20} nota(s) de R$ 20,00')
        print(f'{self.n10} nota(s) de R$ 10,00')
        print(f'{self.n50} nota(s) de R$ 5,00')
        print(f'{self.n2} nota(s) de R$ 2,00')
        print(f'{self.n1} nota(s) de R$ 1,00')


def main():
    cedulas = Cedulas(input())
    cedulas.calcula_notas()
    cedulas.printa()

main()