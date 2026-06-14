##### FUNÇÕES PERSONALIZADAS
# ESTRUTURA:
# nome_da_funcao <- function(parâmetros){
# corpo da função
#}


# função de soma do R: sum()
soma <- function(n1, n2){
  n1 + n2
}

soma(4, 4)
soma(5, 10)


# função equivalente do R: mean()
media <- function(numeros){
  soma <- sum(numeros)
  quantidade <- length(numeros)
  soma / quantidade
}

media(c(1, 2, 3, 4, 5, 6, 7))


# Prática
df <- data.frame(
  Nome = paste("Pessoa", 1:25),
  Idade = sample(18:60, 25, replace = TRUE),
  Sexo = factor(sample(1:2, 25, replace = TRUE), labels = c("Masculino", "Feminino")),
  Prova1 = sample(50:100, 25, replace = TRUE),
  Prova2 = sample(0:10, 25, replace = TRUE)
)

descrever_coluna <- function(coluna){
  data.frame(
    Media = mean(coluna, na.rm = TRUE),
    DesvioPadrao = sd(coluna, na.rm = TRUE),
    Minimo = min(coluna, na.rm = TRUE),
    Maximo = max(coluna, na.rm = TRUE)
  )
}

# aplica a função em algumas colunas
descrever_coluna(df$Prova1)
descrever_coluna(df$Prova2)
descrever_coluna(df$Idade)


# aplicando funções em todas as colunas de um data frame
# install.packages("purrr")
library(purrr)

# mostra os dados da função "descrever_coluna" se for numérico
map_df(df, ~ if(is.numeric(.x)) descrever_coluna(.x))


# função para calcular as informações e exibir o nome da coluna
descrever_df <- function(df){
  # filtra para manter apenas as colunas numéricas
  data_num <- dplyr::select(df, where(is.numeric))
  
  # aplica a função descrever_coluna em todas as numéricas
  result <- map_df(data_num, descrever_coluna)
  
  # combina os nomes corretos com os resultados
  cbind(nomes = names(data_num), result)
}

descrever_df(df)











