#include "funcoes.h"


int main () {
    int tamanhos [] = {5000 , 10000 , 15000 , 20000 , 25000 , 30000 ,35000 , 40000 , 45000 , 50000};
    int num_tamanhos = sizeof ( tamanhos ) / sizeof ( tamanhos [0]) ;
    // Abrir arquivo para armazenar os resultados
    FILE *fp_selection_medio = fopen (" SelectionSortIteracoesCasoMedio.txt", "w" );
    FILE *fp_insertion_medio = fopen (" InsertionSortIteracoesCasoMedio.txt", "w" );
    FILE *fp_bubble_medio = fopen (" InsertionSortIteracoesCasoMedio.txt", "w" );
    FILE *fp_selection_pior = fopen (" SelectionSortIteracoesPiorCaso.txt", "w" );
    FILE *fp_insertion_pior = fopen (" InsertionSortIteracoesPiorCaso.txt", "w" );
    FILE *fp_bubble_pior = fopen (" InsertionSortIteracoesPiorCaso.txt", "w" );
    srand (time(0)) ; // Iniciar os numeros aleatorios

    // Loop pelos tamanhos de vetor
    for ( int i = 0; i < num_tamanhos ; i ++) {
        printf("%d\n", tamanhos[i]);
        int tam = tamanhos[i];
        int * arr = (int *) malloc (tam * sizeof(int));
        // Preencher o array com valores crescentes
        for (int j = 0; j < tam ; j++) {
            arr[j] = j;
        }
        // Executar 30 repeticoes para obter o caso medio
        for ( int j = 0; j < 30; j++) {
            mistureVetor ( arr, tam );
            int iteracoes = 0;
            // Selection Sort
            selectionSort (arr, tam , &iteracoes ) ;
            fprintf (fp_selection_medio , "%d  ", iteracoes );
        }
        fprintf (fp_selection_medio, "\n");
        free (arr); // Liberar memoria do array
    }
    // Fechar arquivo
    fclose (fp_selection_medio);
    fclose(fp_insertion_medio);
    fclose(fp_bubble_medio);
    fclose(fp_selection_pior);
    fclose(fp_insertion_pior);
    fclose(fp_bubble_pior);
    return 0;
}
