### OPERADORES

a <- 10
b <- 20
c <- 2
d <- 16
e <- -4

# OPERADORES MATEMÁTICOS
a + b # adição
a - b # subtração
a * c # multiplicação
a / c # divisão
a ** c # exponenciação
sqrt(d) # raiz quadrada
a %% c # resto da divisão
abs(e) # módulo
log(exp(1)) # log natural de euler
log10(a) # log de base 10


# OPERADORES COMPARATIVOS
a == b # igual à
a != b # diferente de
a < b # menor que
a > b # maior que
a <= b # menor ou igual que
a >= b # maior ou igual que


# OPERADORES LÓGICOS
# & (e lógico)
# | (ou lógico)
# ! (não lógico)
a != b & a < b
a == b & a < b

a != b | a < b
a == b | a < b

!(a > b)
!(a < b)


# exemplos práticos
head(mtcars) # exibe as primeiras linhas da tabela mtcars (nativa do R)

mtcars$gear == 5 # retorna um vetor de TRUE ou FALSE
mtcars[mtcars$gear == 5,]

mtcars[mtcars$mpg <= 16,] # lista todos com o campo mpg <= 16

mtcars$gear == 5
!mtcars$gear == 5 # <=> mtcars$gear != 5

# usando operadores lógicos
busca <- mtcars$gear == 5 & mtcars$mpg >= 21 # ambos devem ser verdade
mtcars[busca, ]

busca <- mtcars$gear == 5 | mtcars$mpg >= 21 # pelo menos um deve ser verdade
mtcars[busca, ]

# operador %in%
# puxa os dados iguais do data frame de um valor
hp <- c(93, 110, 335) # exibirá todos os valores que contenham os elementos do vetor
mtcars[mtcars$hp %in% hp, ]

##### CONDICIONAIS
# usaremos o ifelse()

# verifica uma condição (test), se for verdade exibe o YES, se for falsa exibe o NO
ifelse(test = mtcars$mpg > 21,
       yes = "Econômico",
       no = "Ineficiente")

# para usar mais condições (famoso elif, else if):
# usaremos o case_when()

# install.packages("dplyr")
library(dplyr)

# case_when(
  # condição1 ~ resultado1,
  # condicao2 ~ resultado2,
  #  ...
  # condicaoN ~ resultadoN,
  # TRUE ~ default (resultado padrão)
# )

# criando uma nova coluna "consumo"
mtcars$consumo <- case_when(
  mtcars$mpg < 16 ~ "Muito Ineficiente",
  mtcars$mpg < 21 ~ "Ineficiente",
  mtcars$mpg < 25 ~ "Econômico",
  TRUE ~ "Muito Econômico"
)

head(mtcars, 10)

# o jeito tradicional (mas é de 1 por 1)
if (mtcars$mpg[1] < 16){
  "Muito Ineficiente"
}else if (mtcars$mpg[1] < 21){
  "Ineficiente"
}else if  (mtcars$mpg[1] < 25){
  "Econômico"
}else{
  "Muito Econômico"
}





