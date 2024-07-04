#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

int geraPosRandomBusca ( int tam ) {
    return ( int ) (( tam -1) *(( double ) rand () / RAND_MAX ));
}

int main(){
    srand(time(0));
    FILE *arq_caso_medio_linear = fopen("IteracoesMedioCasoLinear.txt", "w");
    FILE *arq_caso_medio_ordenado = fopen("IteracoesMedioCasoOrdenado.txt", "w");
    FILE *arq_caso_medio_binario = fopen("IteracoesMedioCasoBinario.txt", "w");
    FILE *arq_caso_pior_linear = fopen("IteracoesPiorCasoLinear.txt", "w");
    FILE *arq_caso_pior_ordenado = fopen("IteracoesPiorCasoOrdenado.txt", "w");
    FILE *arq_caso_pior_binario = fopen("IteracoesPiorCasoBinario.txt", "w");

    for(int tamanho = 5000; tamanho <= 50000; tamanho += 5000){
        int vetor[tamanho];
        for(int i = 0; i < tamanho; i++){
            vetor[i] = i; 
        }
        printf("%d\n", tamanho);
        for(int repete = 0; repete < 100; repete++){
            int pos = geraPosRandomBusca(tamanho);
            fprintf(arq_caso_medio_linear, "%d  ", buscaLinear(vetor, tamanho, vetor[pos])); //caso medio
            fprintf(arq_caso_medio_ordenado, "%d  ", buscaOrdenada(vetor, tamanho, vetor[pos])); // caso medio
            fprintf(arq_caso_medio_binario, "%d  ", buscaBinaria(vetor, tamanho, vetor[pos])); // caso medio
            fprintf(arq_caso_pior_linear, "%d  ", buscaLinear(vetor, tamanho, -1)); // pior caso
        fprintf(arq_caso_pior_ordenado, "%d  ", buscaOrdenada(vetor, tamanho, tamanho-1)); // pior caso
        fprintf(arq_caso_pior_binario, "%d  ", buscaBinaria(vetor, tamanho, -1)); // pior caso
        }
        fprintf(arq_caso_medio_linear, "\n");
        fprintf(arq_caso_medio_ordenado, "\n");
        fprintf(arq_caso_medio_binario, "\n");
        fprintf(arq_caso_pior_linear, "\n");
        fprintf(arq_caso_pior_ordenado, "\n");
        fprintf(arq_caso_pior_binario, "\n");
    }

    fclose(arq_caso_medio_linear);
    fclose(arq_caso_medio_ordenado);
    fclose(arq_caso_medio_binario);
    fclose(arq_caso_pior_linear);
    fclose(arq_caso_pior_ordenado);
    fclose(arq_caso_pior_binario);
    return 0;
}
