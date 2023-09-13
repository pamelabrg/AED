//QUICK SORT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h.>
#include "confere.h"

void quickSort (int *v, int left, int right, unsigned long *comp, unsigned long *movimentacoes);

int main ( ) {
    int n, *v;
    unsigned long *movimentacoes, *comp;
    movimentacoes = (unsigned long*)malloc(sizeof (unsigned long));
    comp = (unsigned long*)malloc(sizeof (unsigned long));
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

    quickSort(v, 0, n-1, comp, movimentacoes);

    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long millis = end.tv_usec - begin.tv_usec;
    double total = seconds + millis*1e-6;

    if (confere(n, v)) printf("\nOrdenado!");
    else printf("\nErro!");

    printf("Tempo de execucao: %.8f\n segundos", total);
    printf("Comparacoes: %lu\nMovimentacoes: %lu", *comp, *movimentacoes);
}

void quickSort (int *v, int left, int right, unsigned long *comp, unsigned long *movimentacoes) {
    int mid, aux, i, k;
    i = left;
    k = right;
    mid =  v[(left + right) / 2];
    do {
        while(v[i] < mid)
            i++;
        while(mid < v[k]) 
            k--;

        if (i <= k) {
            movimentacoes++;
            aux = v[i];
            v[i] = v[k];
            v[k] = aux;
            i++;
            k--;
        }
    } while (i <= k);

    if (left < k) quickSort(v, left, k, comp, movimentacoes);
    if (i < right) quickSort(v, i, right, comp, movimentacoes);
}