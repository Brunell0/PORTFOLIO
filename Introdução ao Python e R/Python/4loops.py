# while - enquanto
# for - para

# break - sai do loop na hora
# continue - pula iteração
# pass - não serve para nada

condicao = 10
while condicao < 50:
    if condicao == 15:
        condicao += 1
        continue
    print(f"Condicao numero: {condicao}")
    condicao += 1

for _ in range(10):
    pass