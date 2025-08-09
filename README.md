# Experimento de Complexidade de Algoritmos

[![License: Unlicense](https://img.shields.io/badge/license-Unlicense-blue.svg)](LICENSE)
[![Language: C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Language: Python](https://img.shields.io/badge/language-Python-yellow.svg)](https://www.python.org/)

Este repositório contém experimentos desenvolvidos para a disciplina de Estrutura de Dados na [UENP](https://uenp.edu.br/), com foco na análise de complexidade de algoritmos de ordenação e busca. O objetivo é comparar o desempenho de diferentes algoritmos, tanto em C quanto em Python, utilizando medições práticas e geração de gráficos.

## Estrutura do Projeto

- **1.Ordenação_listas/**: Algoritmos de ordenação de listas, scripts para geração de gráficos e análise de tempos.
- **2.Algoritmos_de_Busca/**: Implementações de algoritmos de busca (linear, binária, ordenada) em Python e C, além de arquivos de análise de iterações.
- **3.Algoritmos_de_Ordenação/**: Implementações e análises de algoritmos de ordenação clássicos (Bubble Sort, Insertion Sort, Merge Sort, Quick Sort, Selection Sort), com scripts para visualização dos resultados.

## Funcionalidades

- Implementações em C e Python dos principais algoritmos de ordenação e busca.
- Scripts para análise de desempenho e geração de gráficos comparativos.
- Arquivos de texto com resultados de iterações e tempos de execução.
- Estrutura modular para facilitar a expansão e manutenção do projeto.

## Como Executar


1. Compile os arquivos C utilizando um compilador compatível (ex: GCC):

   
   ```sh
   gcc main.c -o main.exe
   ```

   Ou compile os arquivos específicos de cada algoritmo conforme necessário.

2. Execute os scripts Python para análise e geração de gráficos:

   
   ```sh
   python graficos.py
   ```

   (Execute os scripts nos diretórios correspondentes para cada experimento.)

## Pré-requisitos

- Compilador C (GCC ou compatível)
- Python 3.x
- Bibliotecas Python: matplotlib, numpy, seaborn (instale via `pip install matplotlib numpy seaborn`)

## Licença

Este projeto está licenciado sob a Unlicense. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.


