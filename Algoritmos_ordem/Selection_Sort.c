//SELECTION SORT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h.>
#include "confere.h"

void selectionSort(int n, int *v);

int main ( ) {
    int n, *v;
    srand(time(NULL));

    printf("informe n:");
    scanf("%d", &n);
    v = (int*)malloc(n * sizeof(int));

    if (!v) exit(1);

    for(int i = 0; i < n; i++){
        v[i] = rand() % 1000;
    }

    struct timeval begin, end;
    gettimeofday(&begin,0);

    selectionSort(n, v);

    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long millis = end.tv_usec - begin.tv_usec;
    double total = seconds + millis*1e-6;

    if (confere(n, v)) printf("\nOrdenado!");
    else printf("\nErro!");
    
    printf("Tempo de execucao: %.8f\n segundos", total);
}

void selectionSort(int n, int *v){
    int menor, aux_troca, comp = 0, movimentacoes = 0;

    for (int i = 0; i < n - 1; i++) {
        menor = i;
        for (int k = i + 1; k < n; k++) {
            comp++;
            if (v[k] < v[menor]) {
                menor = k;
            } 
        }
        if (i != menor) {
            movimentacoes++;
            aux_troca = v[i];
            v[i] = v[menor];
            v[menor] = aux_troca;
        }
    }
     printf("Comparacoes: %d\nMovimentacoes: %d", comp, movimentacoes);
}
