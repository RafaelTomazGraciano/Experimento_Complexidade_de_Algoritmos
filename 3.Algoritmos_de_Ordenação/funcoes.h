#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenche_vetor(int arr[], int n){
    for(int i = 0; i < n; i++){
        arr[i] = n-i;
    }
}

// Funcao para misturar o vetor
void mistureVetor ( int arr [] , int n ) {
    for ( int i = 0; i < n; i ++) {
        if (( rand () / ( double ) RAND_MAX ) < 0.5) {
            int j = ( int ) ((n -1) *( rand () /( double ) RAND_MAX ));
            int temp = arr [ i ];
            arr [i ] = arr [j ];
            arr [j ] = temp ;
        }
    }
}
// Implementacao do Selection Sort
void selectionSort ( int arr [] , int n , int * iteracoes ) {
    * iteracoes = 0;
    for ( int i = 0; i < n - 1; i ++) {
    int min_idx = i ;
    for ( int j = i + 1; j < n; j ++) {
        (*iteracoes)++;
        if ( arr [j] < arr [ min_idx ]) {
            min_idx = j;
        }
    }
    int temp = arr [ min_idx ];
    arr [ min_idx ] = arr [i ];
    arr [i ] = temp ;
    }
}

void insertionSort(int arr[], int n, int *iteracoes){
    *iteracoes = 0;
    int chave, j;
    for(int i = 0; i < n; i++){
        chave = arr[i];
        for(j = i-1; j >= 0 && arr[j] > chave; j--){
            (*iteracoes)++;
            arr[j+1] = arr[j];
        }
        arr[j+1] = chave;
    }
}

void bubble(int arr[], int n, int *iteracoes){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            (*iteracoes)++;
            if(arr[j+1] < arr[j]){
                int aux = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void merge(int arr[], int inicio, int meio, int fim, int *iteracoes){
    int i = inicio, j = meio+1, aux = 0;
    int *vetAux = (int *) malloc((fim-inicio+1) * sizeof(int));
    while(i <= meio && j <= fim){
        (*iteracoes)++;
        if(arr[i] <= arr[j]){
            vetAux[aux++] = arr[i++];
        }
        else{
            vetAux[aux++] = arr[j++];
        }
    }
    while(i <= meio){
        (*iteracoes)++;
        vetAux[aux++] = arr[i++];
    }
    while(j <= fim){
        (*iteracoes)++;
        vetAux[aux++] = arr[j++];
    }
    for(aux = 0; aux < (fim-inicio+1); aux++){
        (*iteracoes)++;
        arr[inicio+aux] = vetAux[aux];
    }
    free(vetAux);
}

void mergeSort(int arr[], int inicio, int fim, int *iteracoes){
    if(inicio < fim){
        int meio = (inicio+fim)/2;
        mergeSort(arr, inicio, meio, iteracoes);
        mergeSort(arr, meio+1, fim, iteracoes);
        merge(arr, inicio, meio, fim, iteracoes);
    }
}

int particao(int arr[], int inicio, int fim, int *iteracoes){
    int pivo = arr[fim];
    int indice = inicio;
    for(int i = inicio; i < fim; i++){
        (*iteracoes)++;
        if(arr[i] <= pivo){
            int aux = arr[i];
            arr[i] = arr[indice];
            arr[indice] = aux;
            indice++;
        }
    }
    int aux = arr[fim];
    arr[fim] = arr[indice];
    arr[indice] = aux;
    return indice;
}

void quickSort(int arr[], int inicio, int fim, int *iteracoes){
    if(inicio < fim){
        int pivo = particao(arr, inicio, fim, iteracoes);
        quickSort(arr, inicio, pivo - 1, iteracoes);
        quickSort(arr, pivo + 1, fim, iteracoes);
    }
}

int particiona_random(int arr[], int inicio, int fim, int *iteracoes){
    int pivo_indice = (rand() % (fim-inicio+1)) + inicio;
    int aux = arr[pivo_indice];
    arr[pivo_indice] = arr[fim];
    arr[fim] = aux;
    return particao(arr, inicio, fim, iteracoes);
}

void quickSortAleatorizado(int arr[], int inicio, int fim, int *iteracoes){
    if(inicio < fim){
        int pivo = particiona_random(arr, inicio, fim, iteracoes);
        quickSortAleatorizado(arr, inicio, pivo-1, iteracoes);
        quickSortAleatorizado(arr, pivo+1, fim, iteracoes);
    }
}
