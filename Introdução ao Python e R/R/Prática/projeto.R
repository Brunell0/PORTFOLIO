##### PROJETO PRÁTICO
# O projeto consiste em analisar dados de vendas de uma planilha do Excel
# O projeto utiliza gráficos

### instalar apenas uma vez
# install.packages("readxl")
# install.packages("dplyr")
# install.packages("ggplot2")


library(readxl)
library(dplyr)
library(ggplot2)

# PARA LER A PLANILHA, GARANTA QUE O WORKING DIRECTORY ESTÁ CORRETO
getwd()
# alterar o wd:
# setwd("Disco:/pasta1/pasta2")

# Ler planilha
vendas <- read_excel("vendas.xlsx")

# Criar coluna de faturamento
vendas <- vendas %>%
  mutate(Faturamento = Quantidade * Preco_Unitario)

# Informações úteis

cat("===== RELATÓRIO DE VENDAS =====\n\n")

# Faturamento total
faturamento_total <- sum(vendas$Faturamento)

cat("Faturamento total: R$",
    round(faturamento_total, 2),
    "\n")

# Produto mais vendido
produto_mais_vendido <- vendas %>%
  group_by(Produto) %>%
  summarise(Total = sum(Quantidade)) %>%
  arrange(desc(Total)) %>%
  slice(1)

cat("\nProduto mais vendido:",
    produto_mais_vendido$Produto,
    "\n")

cat("Quantidade vendida:",
    produto_mais_vendido$Total,
    "\n")

# Ticket médio
ticket_medio <- mean(vendas$Faturamento)

cat("\nTicket médio por venda: R$",
    round(ticket_medio, 2),
    "\n")

# Mês com maior faturamento
vendas$Data <- as.Date(vendas$Data)

vendas$Mes <- format(vendas$Data, "%Y-%m")

faturamento_mes <- vendas %>%
  group_by(Mes) %>%
  summarise(Faturamento = sum(Faturamento))

melhor_mes <- faturamento_mes %>%
  arrange(desc(Faturamento)) %>%
  slice(1)

cat("\nMês com maior faturamento:",
    melhor_mes$Mes,
    "\n")

cat("Valor: R$",
    round(melhor_mes$Faturamento, 2),
    "\n")


ggplot(faturamento_mes,
       aes(x = Mes,
           y = Faturamento,
           group = 1)) +
  
  geom_line(size = 1) +
  
  geom_point(size = 3) +
  
  labs(
    title = "Faturamento por mês",
    x = "Mês",
    y = "Faturamento (R$)"
  )