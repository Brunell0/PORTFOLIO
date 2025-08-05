# Autor: Bruno Antonello (01/08/2025)
"""
CONVERSOR DE BASES *N PARA DECIMAIS E DECIMAIS PARA BASES N
N pertence ao intervalo [2, 16]
"""
import sys

run = 1
while(run):
    print("--------------------")
    print("Conversor de bases:")
    print("--------------------")

    base = int(input("Digite a base (até 16 - hexadecimal)\n"))
    while(base < 2 or base > 16):
        print("Digite um valor entre 2 e 16")
        base = int(input("Digite a base (até 16 - hexadecimal)\n"))
        
    tipo = int(input(f"1 - Decimal para base {base}\n2 - Base {base} para decimal\n"))
    while(tipo != 1 and tipo != 2):
        print("Digite uma das opções listadas!\n")
        tipo = int(input(f"1 - Decimal para base {base}\n2 - Base {base} para decimal\n"))
        
    valor = input("Digite o valor para conversão\n")

    #dicionários
    num_for_hexa = {
        10 : 'A',
        11 : 'B',
        12 : 'C',
        13 : 'D',
        14 : 'E',
        15 : 'F',
    }

    hexa_for_num = {
        'A' : 10,
        'B' : 11,
        'C' : 12,
        'D' : 13,
        'E' : 14,
        'F' : 15,
    }


    if tipo == 1:
        quociente = 1
        resto_arr = []
        resto_num = 0
        first = True
        
        while(True):
            if (int(valor) == 0):
                print("0")
                sys.exit()
                break
            [1, 1]
            if quociente == 0:
                break
            
            if (first):
                quociente = int(valor) // base
                resto_num = int(valor) % base
                
                if resto_num >= 10 and resto_num <= 15: #intervalo de letras em hexadecimal
                    resto_arr.append(num_for_hexa[resto_num])
                else:
                    resto_arr.append(resto_num)
            else:
                resto_num = quociente % base
                quociente = quociente // base
                
                if resto_num >= 10 and resto_num <= 15: #intervalo de letras em hexadecimal
                    resto_arr.append(num_for_hexa[resto_num])
                else:
                    resto_arr.append(resto_num)
                    
            first = False
        
        print(resto_arr[::-1])
    else:
        tam = len(valor)
        increment = 1
        decimal_number = 0
        
        for i in valor:
            if i in hexa_for_num:
                val = hexa_for_num[i]
            else:
                val = int(i)
            
            decimal_number += val * base**(tam-increment)
            increment+=1
            
        print(decimal_number)
    
    run = int(input("Deseja continuar?" \
    "\n1 - Sim" \
    "\n0 - Não (Encerrar)\n"))

    while (run != 0 and run != 1):
        print("Escolha entre as opções disponíveis!")
        run = int(input("Deseja continuar?" \
        "\n1 - Sim" \
        "\n0 - Não (Encerrar)\n"))
        
    #encerramento
    if run != True:
        print("-----------------------------------------------------")
        print("Desenvolvido por Bruno Antonello - Brunello Softwares")
        print("-----------------------------------------------------")
        sys.exit()
