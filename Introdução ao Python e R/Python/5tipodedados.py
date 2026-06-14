# int
idade = 25 
print(type(idade))

# float
preco = 19.99 

# complex: Números complexos (parte real + parte imaginária 'j')
posicao = 3 + 5j
print(type(posicao))

# str
nome = "Bruno" 

# bool - boolean
esta_logado = True 
esta_logado = False

# nulo
resultado = None

# list
frutas = ["Maçã", "Banana", "Uva"] 
frutas.append("Laranja")
frutas[2] = "Pitaya"
frutas.remove("Maçã")
removido = frutas.pop()
print(removido)
print(frutas)


# tuple
coordenadas = (10, 20)
print(coordenadas[1])

# dict
aluno = {"nome": "BrunelloBR", "curso": "Programação"} 
print(aluno["curso"])
aluno["nome"] = "João"
del aluno["curso"]
aluno["idade"] = 90

print(aluno)


# conjunto (set)
id_usuarios = {101, 102, 103, 101} # não aceita duplicatas
print(id_usuarios)

# use sorted para ordenar (vira list)
# conjunto (união)
conj_a = {10, 20, 30}
conj_b = {15, 30, 45}
print(sorted(conj_a | conj_b))

# conjunto (intersecção)
conj_c = {60, 70, 80, 90}
conj_d = {60, 75, 90, 105}
print(sorted(conj_c & conj_d))
