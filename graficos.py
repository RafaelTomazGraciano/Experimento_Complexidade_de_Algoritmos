from matplotlib import pyplot as plt
import seaborn as sns

with open("tempos.txt", 'r') as arquivo:
    linhas = arquivo.readlines()
    
    # Inicializando uma lista para armazenar os tempos
    tempos = []

    # Processando cada linha
    for linha in linhas:
        # Removendo espaços em branco e dividindo a linha em valores
        valores = linha.strip().split()
        # Convertendo cada valor para float e adicionando à lista de tempos
        tempos.extend([float(valor) for valor in valores])

    
    medias = []
    cont_media = 0
    cont = 0
    for tempo in tempos:
        cont_media += tempo
        cont += 1
        if cont == 30:
            medias.append(cont_media / 30)
            cont = 0
            cont_media = 0



# Plotando o grafico
plt.figure(figsize=(12, 6))
sns.set_theme(style="darkgrid")
plt.plot(medias, color='red')
x_values = list(range(5000, 50000 + 1, 5000))
plt.xticks(ticks=range(len(medias)), labels=x_values, rotation=45)
plt.xlabel('n - quantidade de vezes')
plt.ylabel('Tempo')
plt.title('Plot dos Tempos')
plt.xticks(rotation=45)
plt.show()


arquivo.close()