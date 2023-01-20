class Produto:
    def __init__(self, codigo, valor) -> None:
        self.codigo = int(codigo)
        self.valor = float(valor)

def calcula_valor(produto1:Produto, quant_produto1, produto2:Produto, quant_produto2) -> float:
    return produto1.valor * quant_produto1 + produto2.valor * quant_produto2

def main():
    entrada = input()
    produto1 = Produto(entrada.split()[0], entrada.split()[2])
    quant_produto1 = int(entrada.split()[1])

    entrada = input()
    produto2 = Produto(entrada.split()[0], entrada.split()[2])
    quant_produto2 = int(entrada.split()[1])

    total = calcula_valor(produto1, quant_produto1, produto2, quant_produto2)

    print(f'VALOR A PAGAR: R$ %.2f' % total)

main()