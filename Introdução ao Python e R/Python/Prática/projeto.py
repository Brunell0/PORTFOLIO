import pandas as pd
import matplotlib.pyplot as plt
import os

# Leitura do Excel
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

CAMINHO_EXCEL = os.path.join(BASE_DIR, "vendas.xlsx")

# print(CAMINHO_EXCEL)

vendas = pd.read_excel(CAMINHO_EXCEL)

print("\n=== PRIMEIRAS LINHAS ===")
print(vendas.head())


# Preparação dos dados

# Converter coluna Data
vendas["Data"] = pd.to_datetime(vendas["Data"])

# Criar faturamento
vendas["Faturamento"] = (
    vendas["Quantidade"] *
    vendas["Preco_Unitario"]
)


# Informações úteis

print("\n===== RELATÓRIO DE VENDAS =====")

# Faturamento total
faturamento_total = vendas["Faturamento"].sum()

print(f"\nFaturamento total: R$ {faturamento_total:,.2f}")


# Produto mais vendido
produto_mais_vendido = (
    vendas.groupby("Produto")["Quantidade"]
    .sum()
    .sort_values(ascending=False)
)

print("\nProduto mais vendido:")
print(produto_mais_vendido.head(1))


# Ticket médio
ticket_medio = vendas["Faturamento"].mean()

print(f"\nTicket médio: R$ {ticket_medio:.2f}")


# Faturamento por mês

vendas["Mes"] = vendas["Data"].dt.strftime("%Y-%m")

faturamento_mes = (
    vendas.groupby("Mes")["Faturamento"]
    .sum()
    .sort_index()
)

print("\nFaturamento por mês:")
print(faturamento_mes)


# Melhor mês
melhor_mes = faturamento_mes.idxmax()
maior_faturamento = faturamento_mes.max()

print(
    f"\nMês com maior faturamento: "
    f"{melhor_mes}"
)

print(
    f"Valor: "
    f"R$ {maior_faturamento:.2f}"
)


# Top 3 produtos

top3 = (
    vendas.groupby("Produto")["Faturamento"]
    .sum()
    .sort_values(ascending=False)
    .head(3)
)

print("\nTop 3 produtos por faturamento:")
print(top3)


# Gráfico

plt.figure(figsize=(8, 5))

plt.plot(
    faturamento_mes.index,
    faturamento_mes.values,
    marker="o"
)

plt.title("Faturamento por mês")
plt.xlabel("Mês")
plt.ylabel("Faturamento (R$)")
plt.grid(True)

plt.tight_layout()

plt.show()