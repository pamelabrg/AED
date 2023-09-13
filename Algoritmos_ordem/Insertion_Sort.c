//INSERTION SORT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h.>
#include "confere.h"

void insertionSort(int n, int *v);

int main ( ) {
    int n, *v;
    srand(time(NULL));

    printf("informe n:");
    scanf("%d", &n);
    v = (int*)malloc(n * sizeof(int));

    if (!v) exit(1);

    for(int i = 0; i < n; i++){
        v[i] = rand() % 1000;
        //printf("%d   ", v[i]);
    }

    struct timeval begin, end;
    gettimeofday(&begin,0);

    insertionSort(n, v);

    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long millis = end.tv_usec - begin.tv_usec;
    double total = seconds + millis*1e-6;
    
    if (confere (n, v)) printf("\nOrdenado\n");
    else printf("\nErro!");
    printf("Tempo de execucao: %.8f\n segundos", total);

}

void insertionSort (int n, int* v){
    int aux, aux_ind;
    unsigned long comp = 0, movimentacoes = 0;

    for(int k = 1; k <= n - 1; k++){
        aux = v[k];
        aux_ind = k - 1;

        while(aux_ind >= 0 && aux < v[aux_ind]){
            comp++;
            movimentacoes++;
            v[aux_ind + 1] = v[aux_ind];
            aux_ind--;
        }

        v[aux_ind+1] = aux;
        comp++;
    }
    printf("Comparacoes: %lu\nMovimentacoes: %lu", comp, movimentacoes);
}

