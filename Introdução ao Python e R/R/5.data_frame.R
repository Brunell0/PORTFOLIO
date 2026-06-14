##### DATA FRAME
# é uma estrutura de dados bidimensional (similar a uma tabela)

# a criação pode ser proveniente de exportação, ou criar os nomes como argumentos:
df <- data.frame(
  ID = 1:25,
  Nome = paste("Pessoa", 1:25),
  Idade = sample(18:60, 25, replace = TRUE),
  Sexo = factor(sample(1:2, 25, replace = TRUE), labels = c("Masculino", "Feminino")),
  Cidade = sample(c("São Paulo", "Rio de Janeiro", "Belo Horizonte", "Curitiba"), 25, replace = TRUE),
  Pontuacao = sample(50:100, 25, replace = TRUE)
)
df
# nas linhas 4, 12 e 20, colunas 3 e 5, serão valores NA
df[c(4, 12, 20), c(3, 5)] <- NA
df

# visualização dos dados
head(df) # exibe apenas as primeiras linhas
head(df, 10) # exibe apenas as 10 primeiras linhas

tail(df) # exibe apenas as últimas linhas
tail(df, 10) # exibe apenas as 10 últimas linhas

class(df) # exibe a classe (data.frame)

str(df) # exibe as informações de classes e variáveis do objeto

na.omit(df) # omite linhas com valores NA

# obtendo valores das colunas
df$Pontuacao # retorna um vetor dos valores de Pontuacao
df$ID
df$Sexo

df$Sexo[3] # Acessando a posição 3 deste vetor

# visualização de dados (similar a uma matriz)
df[3,] # retorna somente a linha 3
df[,4] # retorna somente a coluna 4
df[4, 4] # retorna o valor da linha 4 coluna 4

df[2] # com apenas um número ele retorna a COLUNA
df[4]

df[-c(2, 4, 3)] # remove a coluna 2, 3 e 4

# pacote para visualização dos dados de data frames
install.packages("dplyr")
library(dplyr)

# select(dataframe, colunas...)
# exibe ou omite colunas do data frame, podendo passar o número ou nome da coluna

select(df, 3, 4, Pontuacao) # exibe as colunas 3, 4 e Pontuacao
select(df, -Nome) # exibe omitindo o Nome (seria igual a df[-2])

# filter(dataframe, campos...) 
# esta função filtra de acordo com o interesse

filter(df, Cidade == "Curitiba")
filter(df, Cidade == "Curitiba", Sexo == "Masculino")
filter(df, Cidade == "Curitiba", Sexo == "Feminino")
filter(df, Pontuacao > 75)

# somando os valores de uma coluna a partir de filtros
sum(filter(df, Cidade == "Curitiba", Sexo == "Feminino")["Pontuacao"]) # soma
count(filter(df, Cidade == "Curitiba", Sexo == "Feminino")) # contagem

# reorganizando os dados
arrange(df, Pontuacao) # exibe em ordem crescente de Pontuacao
arrange(df, Pontuacao, Idade) # exibe em ordem crescente de Pontuacao e Idade

arrange(df, desc(Pontuacao)) # exibe em ordem DEcrescente de Pontuacao

##### encadeando operações com o pipe %>%
# exemplo:
head(df)
df %>% head()

# Este trecho OMITE a coluna Nome, FILTRA a Cidade como "Belo Horizonte" e deixa a Pontuacao em ORDEM CRESCENTE
df %>%
  select(-Nome) %>%
  filter(Cidade == "Belo Horizonte") %>%
  arrange(Pontuacao)






