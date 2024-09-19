from matplotlib import pyplot as plt
import seaborn as sns

quant = 30

# Função para processar os dados
def processar_dados(filename, quant):
    with open(filename, 'r') as arquivo:
        linhas = arquivo.readlines()
        
    tempos = []
    for linha in linhas:
        valores = linha.strip().split()
        tempos.extend([int(valor) for valor in valores])  # Convertendo para int
        
    medias = []
    cont_media = 0
    cont = 0
    
    for tempo in tempos:
        cont_media += tempo
        cont += 1
        if cont == quant:
            media = cont_media / quant
            medias.append(media)
            cont = 0
            cont_media = 0
    
    return medias

# Processando arquivos
medias = processar_dados('QuickSortIteracoesCasoMedio.txt', quant)
medias_pior = processar_dados('QuickSortIteracoesPiorCaso.txt', quant)

x_values = list(range(5000, 50000 + 1, 5000))

# Plotando o gráfico
plt.figure(figsize=(12, 6))
sns.set_theme(style="darkgrid")

plt.plot(x_values, medias, color='red', label='Caso médio', marker='o')
plt.plot(x_values, medias_pior, color='green', label='Pior caso', marker='o')

plt.xticks(ticks=x_values, labels=x_values, rotation=45)
plt.yticks(ticks=range(0, int(max(max(medias), max(medias_pior))) + 1, int(max(max(medias), max(medias_pior)) / 10)))
plt.gca().yaxis.set_major_formatter(plt.FuncFormatter(lambda x, _: int(x)))  # Formatar eixo Y como inteiro

plt.xlabel('Tamanho do Vetor')
plt.ylabel('Média das Iterações')
plt.title('Quick Sort')

plt.legend()
plt.tight_layout()
plt.show()