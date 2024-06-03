#include "funcoes.h"


int main(){
    clock_t inicio_t, fim_t;
    double total_t;
    FILE *arq;
    lista *lst = cria_no_lista();

    arq = fopen("tempos.txt", "w"); // abre o arquivo

    for(int i = 5000; i <= 50000; i += 5000){
        printf("%d\n", i);
        for(int j = 0; j < 30; j++){
            inicio_t = clock(); // comeca o timer
            for(int k = i; k > 0; k--){
                lst = insere_ordenado_crescente(lst, k);
            }
            fim_t = clock(); // finaliza o timer
            total_t = (double)(fim_t - inicio_t) / CLOCKS_PER_SEC; // faz a conta do tempo
            fprintf(arq, "%lf", total_t); // escreve no arquivo
        }
        lst = free_lista(lst);
        fprintf(arq, "\n");
    }

    fclose(arq); // fecha arquivo
    return 0;
}