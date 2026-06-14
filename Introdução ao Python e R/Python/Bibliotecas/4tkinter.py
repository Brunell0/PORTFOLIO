import tkinter as tk

def ao_clicar():
    label.config(text="Olá, Mundo!")

janela = tk.Tk()
janela.title("Meu Primeiro App")
janela.geometry("300x200")

label = tk.Label(janela, text="Clique no botão abaixo")
label.pack(pady=20)

botao = tk.Button(janela, text="Clique Aqui", command=ao_clicar)
botao.pack()

janela.mainloop()