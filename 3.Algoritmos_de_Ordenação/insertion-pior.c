#include "funcoes.h"

int main () {
    int tamanhos [] = {5000 , 10000 , 15000 , 20000 , 25000 , 30000 ,35000 , 40000 , 45000 , 50000};
    int num_tamanhos = sizeof ( tamanhos ) / sizeof ( tamanhos [0]) ;
    // Abrir arquivo para armazenar os resultados
    FILE * fp_selection = fopen ("InsertionSortIteracoesPiorCaso.txt" , "w" );
    srand ( time (0) ) ; // Iniciar os numeros aleatorios
    // Loop pelos tamanhos de vetor
    for ( int i = 0; i < num_tamanhos ; i ++) {
        int tam = tamanhos [i];
        printf("%d\n", tam);
        int * arr = ( int *) malloc ( tam * sizeof (int));
        // Executar 30 repeticoes para obter o caso medio
        for ( int j = 0; j < 30; j ++) {
            // Preencher o array com valores decrescentes
            preenche_vetor(arr, tam);
            int iteracoes = 0;
            // Selection Sort
            insertionSort ( arr , tam , & iteracoes) ;
            fprintf (fp_selection , "%d  " ,iteracoes);
        }
        fprintf(fp_selection, "\n");
        free (arr); // Liberar memoria do array
    }
    // Fechar arquivo
    fclose (fp_selection);
    return 0;
}