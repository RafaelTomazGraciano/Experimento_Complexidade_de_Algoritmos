from matplotlib import pyplot as plt
import seaborn as sns

with open("tempos.txt", "r") as arquivo:
    conteudo = arquivo.readlines()
    plt.figure(figsize = (8,6))
    plt.xticks(rotation = 45)
    sns.set_theme(style = "darkgrid")
    sns.lineplot(data = conteudo[1], x = 'n', y = 'tempo', color = 'red')


arquivo.close()