####### LAÇOS DE REPETIÇÃO (LOOPS)
# Não tão úteis em R, devido à lerdeza de código por ser sequencial
# Funções vetorizadas são muito mais eficientes se a ordem não importa

set.seed(33)
df <- data.frame(
  Dia = 1:30,
  Internacoes = sample(10:60, 30, replace = TRUE),
  Materiais = sample(50:100, 30, replace = TRUE)
)

# FOR
# percorre intervalos específicos, "para cada valor"

for (i in df$Internacoes){
  print(i)
}
# similar a
df$Internacoes

soma_internacoes <- 0
for (i in df$Internacoes){
  soma_internacoes <- soma_internacoes + i
}
soma_internacoes
# igual a
sum(df$Internacoes)


# somas cumulativas
soma_cumulativa <- numeric(nrow(df))
soma_cumulativa[1] <- df$Internacoes[1]
for (i in 2:nrow(df)){
  soma_cumulativa[i] <- soma_cumulativa[i-1] + df$Internacoes[i]
}
soma_cumulativa


# WHILE
# repete enquanto for verdadeiro (cuidado com loops infinitos!)

i <- 1
while(df$Materiais[i] <= 90){
  print(df$Materiais[i])
  i <- i + 1 # para pular a iteração
}

# usando o break para QUEBRAR IMEDIATAMENTE o loop
i <- 1
while(df$Materiais[i] <= 90){
  if(df$Materiais[i] < 60){
    break
  }
  print(df$Materiais[i])
  i <- i + 1 # para pular a iteração
}

# usando o next para PULAR A ITERAÇÃO (igual ao continue do Python)
i <- 1
while(df$Materiais[i] <= 90){
  if(df$Materiais[i] < 60){
    i <- i + 1 # para pular a iteração
    next
  }
  print(df$Materiais[i])
  i <- i + 1 # para pular a iteração
}


# somando com while
soma_materiais <- 0
i <- 1

while (soma_materiais <= 500){
  soma_materiais <- soma_materiais + df$Materiais[i]
  i <- i + 1
}
soma_materiais # total de materiais
i # dias 








