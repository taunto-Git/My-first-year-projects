import tkinter as tk
from tkinter import *
from tkinter.ttk import Combobox
import random

def random_gen():
    global passw
    keyboard = [["q"], ["w"], ["e"], ["r"], ["t"], ["y"], ["u"], ["i"], ["o"], ["p"],
               ["a"], ["s"], ["d"], ["f"], ["g"], ["h"], ["j"], ["k"], ["l"],
               ["z"], ["x"], ["c"], ["v"], ["b"], ["n"], ["m"],["1"], ["2"], ["3"], ["4"], ["5"], ["6"], ["7"], ["8"], ["9"], ["0"],
               ["!"], ["£"], ["$"], ["%"], ["/"], ["("], [")"], ["="], ["?"], ["^"], [","], ["."], ["-"], [":"], ["_"], ["@"], ["#"], ["["], ["]"]
               ]
    
    password = ""
    
    for _ in range(lunghezza.get()+1):
        numero = random.randint(0,54)
        password += keyboard[numero][0]
    testo_password.config(text="pass : \n"+password)
    passw = password
    testo_password.pack()


def save_pass():
    ragg = reason.get() + "->"
    global passw
    try:
        with open("password_fighe.txt","a") as f:
            f.write("\n")
            f.write(ragg+passw)
        success = tk.Label(text="password salvata con successo!")
        success.grid()
    except:
        error = tk.Label(text="c'è stato un problema nel salvare la password")
        error.grid()

def search_pass():
    try:
        with open("password_fighe.txt","r") as f:
            linee=f.readlines()
        
    except:
        eroraccio = tk.Label(text="errore nel trovare le password")
        eroraccio.grid()
    return linee


main = tk.Tk()
main.title("generatore di password")
main.geometry("400x300")
main.resizable(False,False)
passw = str()

testo = tk.Label(main,text="inserisci lunghezza password")
testo.pack()

lunghezza = IntVar()
entrata_caratteri = tk.Entry(main,textvariable=lunghezza)
entrata_caratteri.pack()

tasto_gen = tk.Button(main,command=random_gen,text="invio") 
tasto_gen.pack()

texto_reason = tk.Label(main,text="inserisci a cosa serve questa password")
texto_reason.pack()

reason = StringVar()
entry_reason = tk.Entry(main,textvariable=reason)
entry_reason.pack()

save_button = tk.Button(main,command=save_pass,text="Salva password")
save_button.pack()

testo_password = tk.Label(main)
testo_password.pack_forget()

search_ask_Label = tk.Label(main,text="Cerca password")
search_ask_Label.pack()

password_selez = StringVar()
Combo_pass = Combobox(main,textvariable=password_selez)
Combo_pass['values'] = search_pass()
Combo_pass['state'] = "readonly"
Combo_pass.pack()
main.mainloop()


