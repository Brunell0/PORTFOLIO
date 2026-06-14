######## VETORES

# seq cria uma sequência de números
# from => onde começa (inclusivo)
# to => onde termina (inclusivo)
# by => quanto "pula" de um para o outro

i <- seq(from=4, to=160, by=4)
i
length(i) # comprimento do vetor 

# INDEXAÇÃO: acessar valores pelos índices (1° índice = 1), logo posição = índice
i[1]
i[length(i)]

# obter intervalos
i[2:3] # da posição 2 até a 3
i[c(1,3,7,9)] # posições 1, 3, 7 e 9

# filtros
i[i < 80] # valores menores que 80
i[i %% 2 == 1] # somente os ímpares (não existe neste caso!)

# remover a posição
i[-6] # remove o elemento da posição 6 (valor = 24)
i[-1] # remove o elemento da posição 1 (valor = 4)
i[-(1:4)] # remove os elementos das posições 1 até 4 (inclusivo)
i[-c(1, 3, 5, 7, 9, 11)] # remove os elementos das posições do conjunto

# alterar valores
i[1] <-  0 # altera o valor da posição 1
i[c(2, 3, 4, 5)] <- c(1, 2, 3, 4) # alterar os valores das posições do conjunto
i

# pode-se renomear a função
names(i)
names(i) <- paste0("x", 1:40) # todos os valores possuem nomes agora!
i

# selecionar pelo nome
i["x28"]
i[c("x6", "x7", "x8")]


##### MATRIZES
j <- matrix(data = c(1:9), nrow = 3); j # matriz 3x3 com dados de 1 até 9

# mesma matriz, mas os números são ordenados por linha (byrow)
k <- matrix(j, nrow = 3, byrow = TRUE); k 

# indexação: matriz[linha, coluna]
k[2, 3] # retorna o valor da linha 2, coluna 3
k[2,] # retorna a linha 2 inteira
k[,3] # retorna a coluna 3 inteira
k[2] # retorna o valor da posição seguindo a ordem

k[,-2] # remove a coluna 2
k[-1,] # remove a linha 1
k[-1, -3] # remove a linha 1 e a coluna 3 (simultaneamente)

#### podemos renomear as matrizes
# nomes das colunas
colnames(k) <- c("col1", "col2", "col3")
colnames(k)

# nomes das linhas
rownames(k) <-c("row1", "row2", "row3")
rownames(k)

# nomes das dimensões (linhas e colunas)
dimnames(k)


# funções de dimensões

dim(k) # dimensão da matriz
nrow(k) # número de linhas
ncol(k) # número de colunas

k



