//SELECTION SORT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h.>
#include <math.h>
#include "confere.h"

void mergeSort(int *v, int begin, int end);
void merge (int *v, int  begin, int half, int end);

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

    mergeSort(v, 0, n-1);

    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long millis = end.tv_usec - begin.tv_usec;
    double total = seconds + millis*1e-6;

    if (confere(n, v)) printf("\nOrdenado!");
    else printf("\nErro!");

    printf("Tempo de execucao: %.8f\n segundos", total);
}

void mergeSort(int *v, int begin, int end) {
    int half;
    if (begin < end) {
        half = floor((begin+end)/2);
        mergeSort(v, begin, half);
        mergeSort(v, half+1, end);
        merge(v, begin, half, end);
    }
}

void merge (int *v, int  begin, int half, int end) {
    int *aux, p1, p2, tam, j, k, end1 = 0, end2 = 0;

    tam = end - begin + 1; 
    p1 = begin;
    p2 = half + 1;
    aux = (int*) malloc (tam * sizeof(int));

    if(!aux) exit(1);

    for (int i = 0; i < tam; i++) {
        if ( !end1 && ! end2) {
            if (v[p1] < v[p2]) aux[i] = v[p1++];
            else aux[i] = v[p2++];
            if (p1 > half) end1 = 1;
            if (p2 > end) end2 = 1;
        } else {
            if(!end1) aux[i] = v[p1++];
            else aux[i] = v[p2++];
        }
    }
    for (j = 0, k = begin; j < tam; j++, k++) {
        v[k] = aux[j];
    }
    free(aux);
}

