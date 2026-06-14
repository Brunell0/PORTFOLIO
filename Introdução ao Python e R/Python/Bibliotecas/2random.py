import random

opcoes = ["Pedra", "Papel", "Tesoura"]
escolha_computador = random.choice(opcoes)

print(f"O computador escolheu: {escolha_computador}")

print(f"O computador escolheu um número: {random.randint(1, 10)}")