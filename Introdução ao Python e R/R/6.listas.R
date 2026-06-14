#### listas
# estrutura de dados mais complexa, permite outros tipos de dados dentro dela, bem como outra lista

lt <- list(
  "numeros" = 1:100,
  "LETRAS" = LETTERS,
  "matriz" = matrix(1:12, nrow = 3),
  "df" = data.frame(
    ID = 1:25,
    Sexo = factor(sample(1:2, 25, replace = TRUE), labels = c("Masculino", "Feminino")),
    Cidade = sample(c("São Paulo", "Rio de Janeiro", "Brasília"), 25, replace = TRUE),
    Pontuacao = sample(50:100, 25, replace = TRUE)
  ),
  "lista" = list(
    c(2, 4, 6, 7, 8, 11),
    c("a", "e", "i", "o", "u")
  )
)
lt

# acessando os dados
lt$df # retorna o campo df
lt[[4]] # retorna o campo df
lt[4] # retorna o campo df (mostra o nome do campo antes)

# verificando as classes
class(lt$df) # data.frame
class(lt[[4]]) # data.frame
class(lt[4]) # list

# acessando mais dados
lt[[4]][3] # cidade do df
lt[[4]]$Cidade # cidade do df

lt[[4]][3,] # acessa a 3ª linha do df
lt[[4]][,2] # acessa a 2ª coluna do df

# a função str() exibe detalhes da estrutura
str(lt)


# manipulando listas
# aqui são gerados 2 data frames dentro da lista lt2
lt2 <- list(
  carros = mtcars[1:20,],
  flores = iris[1:20,]
)
lt2

#### função lapply()
# aplicando funções em todos os elementos da lista

lapply(lt2, head) # exibe o head de todos os elementos (df) da lista

lapply(lt2, dplyr::select, 2:3)


# a função map() é uma alternativa ao lapply()

# install.packages("purrr") # instala o pacote purrr
purrr::map(lt2, dplyr::select, 2:3)



