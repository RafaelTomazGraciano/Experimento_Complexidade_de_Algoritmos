#include <stdio.h>

int buscaLinear(int *v, int n, int elem){
    int cont = 0;
    for(int i = 0; i < n; i++){
        cont++;
        if(elem == v[i]){
            return cont;
        }
    }
    return cont;
}

int buscaOrdenada(int *v, int n, int elem){
    int cont = 0;
    for(int i = 0; i < n; i++){
        cont++;
        if(elem ==  v[i]){
            return cont;
        }
        else if (elem < v[i]){
            return cont;
        }
    }
    return cont;
}

int buscaBinaria(int *v, int n, int elem){
    int cont = 0;
    int inicio = 0, meio, final = n-1;
    while(inicio <= final){
        cont++;
        meio = (inicio + final)/2;
        if(elem < v[meio]){
            final = meio-1;
        }
        else{
            if(elem > v[meio]){
                inicio = meio+1;
            }
            else{
                return cont;
            }
        }
    }
    return cont;
}
