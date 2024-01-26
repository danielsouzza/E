import matplotlib.pyplot as plt
import subprocess

# Executar o programa C e capturar a saída
process = subprocess.Popen(['./main'], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
output, _ = process.communicate()

# Função para ler os dados do arquivo
def ler_dados_do_arquivo(nome_arquivo):
    algoritmos = []
    caso_medio = []
    melhor_caso = []
    pior_caso = []

    with open(nome_arquivo, 'r') as arquivo:
        linhas = arquivo.readlines()[3:]  # Ignorar as três primeiras linhas

        for linha in linhas:
            valores = linha.strip().split('|')
            algoritmo = valores[0].strip()
            algoritmos.append(algoritmo)
            caso_medio.append(float(valores[1]))
            melhor_caso.append(float(valores[2]))
            pior_caso.append(float(valores[3]))

    return algoritmos, caso_medio, melhor_caso, pior_caso

# Leitura dos dados do arquivo
arquivo_dados = 'Tempo de ordenação.txt'
algoritmos, caso_medio, melhor_caso, pior_caso = ler_dados_do_arquivo(arquivo_dados)

# Criando o gráfico
barWidth = 0.25
r1 = range(len(algoritmos))
r2 = [x + barWidth for x in r1]
r3 = [x + barWidth for x in r2]

plt.bar(r1, caso_medio, color='blue', width=barWidth, edgecolor='grey', label='Caso Médio')
plt.bar(r2, melhor_caso, color='green', width=barWidth, edgecolor='grey', label='Melhor Caso')
plt.bar(r3, pior_caso, color='red', width=barWidth, edgecolor='grey', label='Pior Caso')

# Adicionando detalhes ao gráfico
plt.xlabel('Algoritmos', fontweight='bold')
plt.xticks([r + barWidth for r in range(len(algoritmos))], algoritmos)
plt.title('Tempos de Execução dos Algoritmos de Ordenação')
plt.legend()

# Exibindo o gráfico
plt.show()
