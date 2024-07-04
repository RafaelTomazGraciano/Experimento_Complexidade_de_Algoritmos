#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Funcao para misturar o vetor
void mistureVetor ( int arr [] , int n ) {
    for ( int i = 0; i < n; i ++) {
        if (( rand () / ( double ) RAND_MAX ) < 0.5) {
            int j = ( int ) ((n -1) *(rand () /( double ) RAND_MAX ));
            int temp = arr [i];
            arr [i] = arr [j];
            arr [j] = temp ;
        }
    }
}

void selectionSort(int v[], int n, int *iteracoes){
    *iteracoes = 0;
    for(int i = 0; i < n-1; i++){
        int indice_menor = i;
        for(int j = i+ 1; j < n; j++){
            (*iteracoes)++;
            if(v[j] < v[indice_menor]){
                indice_menor = j;
            }
        }
        int aux = v[i];
		v[i] = v[indice_menor];
		v[indice_menor] = aux;
    }
}

void insertionSort(int v[], int n, int *iteracoes){
    *iteracoes = 0;
    int key, j;
    for(int i = 1; i < n-1; i++){
        key = v[i];
        for(j = i-1; j >= 0 && v[j] > key; j--){
            (*iteracoes)++;
            v[j+1] = v[j];
        }
        v[j+1] = key;
    }
}

void bubbleSort(int v[], int n, int *iteracoes){
    *iteracoes = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n; j++){
            (*iteracoes)++;
            if(v[j] > v[j+1]){
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}