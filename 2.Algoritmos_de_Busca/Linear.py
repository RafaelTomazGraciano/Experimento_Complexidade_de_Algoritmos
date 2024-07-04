import numpy as np
from matplotlib import pyplot as plt
import seaborn as sns

quant = 100

# Função para processar os dados
def processar_dados(filename, quant):
    with open(filename, 'r') as arquivo:
        linhas = arquivo.readlines()
        
    tempos = []
    for linha in linhas:
        valores = linha.strip().split()
        tempos.extend([float(valor) for valor in valores])
        
    medias = []
    desvios_padroes = []
    cont_media = 0
    cont = 0
    bloco = []
    
    for tempo in tempos:
        cont_media += tempo
        bloco.append(tempo)
        cont += 1
        if cont == quant:
            media = cont_media / quant
            medias.append(media)
            desvios_padroes.append(np.std(bloco))
            cont = 0
            cont_media = 0
            bloco = []
    
    return medias, desvios_padroes

# Processando arquivos
medias, desvios_padroes = processar_dados("IteracoesMedioCasoLinear.txt", quant)

with open("IteracoesPiorCasoLinear.txt", 'r') as arquivo:
    linhas = arquivo.readlines()
    
tempos_pior = []
for linha in linhas:
    valores = linha.strip().split()
    tempos_pior.extend([float(valor) for valor in valores])

medias_pior = []
cont_media = 0
cont = 0
for tempo in tempos_pior:
    cont_media += tempo
    medias_pior.append(cont_media/10)


# Plotando o grafico
plt.figure(figsize=(12, 6))
sns.set_theme(style="darkgrid")

plt.plot(medias, color='red', label='Caso médio')
plt.plot(desvios_padroes, color='blue', label='Desvio Padrão')
plt.plot(medias_pior, color='green', label='Pior caso')

x_values = list(range(5000, 50000 + 1, 5000))
plt.xticks(ticks=range(len(medias)), labels=x_values, rotation=45)
plt.xlabel('n - quantidade de vezes')
plt.ylabel('Quantidade de Vezes')
plt.title('Quantidade de Vezes - Busca Linear')

plt.legend()
plt.show()
