# Tipos de dados (CLASSES): Numeric, Character, Logical e Factor

# class() - tipo de dado do objeto
var_char <- "sou um character"
class(var_char)

class(20)
class(15.23)

var_vect <- c(1, 2, 3, NA, 5) # NA (Not Available - dado ausente)
class(var_vect)

# is.CLASSE(objeto) - verifica se o objeto pertence a certo tipo, retorna TRUE ou FALSE
is.numeric(var_vect) # TRUE
is.character(var_vect)
is.logical(var_vect)
is.factor(var_vect)

# as.CLASSE(objeto) - converte o tipo de dado do objeto
var_vect <-  as.character(var_vect) # SALVA na variável
as.numeric(var_vect) # NÃO SALVA na variável

is.numeric(var_vect) # FALSE
is.character(var_vect) # TRUE

# Logical (Boolean)
class(TRUE)
class(FALSE)
class(NA)

# Aritmética de Logicals
# TRUE = 1 / FALSE = 0
TRUE + TRUE + TRUE # 3

# verificando se algum dado está vazio em um conjunto de dados
is.na(var_vect)

var_vect <- as.numeric(var_vect) # retransforma para numérico

mean(var_vect, na.rm = TRUE) # retorna a média IGNORANDO os NA

# removendo os NA
var_vect <- na.omit(var_vect)

mean(var_vect)

# DETALHE IMPORTANTE: atenção para salvar os dados nos objetos, pois é necessário atribuir (<-)

### FACTORS: são categorias

# neste exemplo, os números estão associados aos textos:
# Fundamental => 1
# Médio => 2
# Superior => 3
# Pós-graduado => 4

escolaridade <- factor(x = c(1, 1, 2, 1, 3, 4, 2, 3, 3, 2),
                       labels = c("Fundamental", "Médio", "Superior", "Pós-graduado"),
                       ordered = TRUE) # está ordenado
escolaridade
levels(escolaridade)

# todos os textos viram categorias!
regiao <- factor(x = c("Norte", "Sul", "Nordeste", "Centro-Oeste", "Sudeste"))
regiao # está em ordem alfabética

# convertendo dados para factor
as.factor(var_vect)

# convertendo factor para outros tipos de dados
as.numeric(escolaridade)
as.character(regiao)

