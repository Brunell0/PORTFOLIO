######### objetos <=> variáveis
# Tipos de dados: Numeric, Character, Logical e Factor

# <- ou = (atribuição)
a <- 40
a # exibe na tela
a + 10

a <- a - 5 # reatribui

b <- "casa"

# remover objeto
rm(b)

######### funções
# combine: c(V1,V2,V3, ..., Vn)
# cria conjuntos

var1 <- c(10, 20, 30)
var2 <- c("amora", "banana", "cereja", "damasco")
var3 <- c(1:3) # cria um vetor de 1 até 3

# as operações vetoriais são iguais a álgebra linear
var1 + var3 # soma todos os elementos dos vetores, um a um
var3 + 5
var1 * 2  
var3 - 1

# funções de estatística (muito usadas)
var4 <- c(5, 10, 15, 20, 25, 30)

sum(var4) # soma
mean(var4) # média
median(var4) # mediana
min(var4) # mínimo
max(var4) # máximo
summary(var4) # mostra informações relevantes (mínimo, 1° quartil, mediana, média, 3° quartil, máximo)

# função paste() une informações textuais
# sep = " " é default!
paste("Eu moro em uma" , b, sep=" ") # concatena o texto com o objeto b. sep é o separador entre eles, podendo ser qualquer caractere
paste("Números da loteria:", paste(var4, collapse=", ")) # collapse une os elementos do vetor em um texto só
paste("Números da loteria:", toString(var4)) # transforma o vetor em string/texto (literal)

texto <- paste("A", b, "do vizinho é ao lado da minha", sep=" \" ")
cat(texto) # interpreta o texto de forma limpa

# procurar informações de uma função específica: ?function
?paste # abre o help da função paste





  
