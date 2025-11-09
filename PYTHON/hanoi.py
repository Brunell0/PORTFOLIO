import time
import os

'''
Resolve a torre de hanói, desenhando pelo terminal cada etapa, e ao final exibe quantos movimentos foram realizados

O mínimo de movimentos é dado por 2^(n) - 1. Por exemplo, 4 discos: 2^(4) - 1 = 16 - 1 = 15
'''
tempo = 0.6


def mostrar_torres(torres):
    os.system('cls' if os.name == 'nt' else 'clear')  #limpa a tela
    print("\n---- TORRE DE HANÓI ----\n")
    altura = max(len(t) for t in torres.values())

    for i in range(altura, 0, -1):
        for nome in torres:
            if len(torres[nome]) >= i:
                disco = "■" * torres[nome][i - 1]
                print(f"{disco:^10}", end="")
            else:
                print(f"{'|':^10}", end="")
        print()
    print("   E        C        D\n")
    time.sleep(tempo)

def mover(n, de, para, aux, torres, contador):
    if n > 0:
        mover(n-1, de, aux, para, torres, contador)
        torres[para].append(torres[de].pop())
        contador[0] += 1
        mostrar_torres(torres)
        mover(n-1, aux, para, de, torres, contador)

def hanoi(n):
    torres = {'E': list(range(n, 0, -1)), 'C': [], 'D': []}
    contador = [0]
    mostrar_torres(torres)
    mover(n, 'E', 'D', 'C', torres, contador)
    print(f"\nTotal de movimentos: {contador[0]}")

n = int(input("Quantos discos? "))
hanoi(n)
