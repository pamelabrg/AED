//Pâmela Braga - M2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool haveConflict ( char ** event1, char ** event2 ) {
    int ev1_c[3], ev1_f[3], ev2_c[3], ev2_f[3];
    sscanf ( event1[0], "%d:%d", &ev1_c[0], &ev1_c[1] );
    sscanf ( event1[1], "%d:%d", &ev1_f[0], &ev1_f[1] );
    sscanf ( event2[0], "%d:%d", &ev2_c[0], &ev2_c[1] );
    sscanf ( event2[1], "%d:%d", &ev2_f[0], &ev2_f[1] );

    ev1_c[2] = ( ev1_c[0] * 60 ) + ( ev1_c[1] );
    ev1_f[2] = ( ev1_f[0] * 60 ) + ( ev1_f[1] );
    ev2_c[2] = ( ev2_c[0] * 60 ) + ( ev2_c[1] );
    ev2_f[2] = ( ev2_f[0] * 60 ) + ( ev2_f[1] );

    if ( ev1_c[2] > ev1_f[2] ) return false;
    if ( ev2_c[2] > ev2_f[2] ) return false;

    if ( ev1_c[2] <= ev2_c[2] ) {
        if ( ( ev1_f[2] >= ev2_c[2] ) ) return true;
    }
    else if ( ev1_c[2] >= ev2_c[2] ) {
        if ( ( ev2_f[2] >= ev1_c[2] ) ) return true;
    }
    return false;
}

int main () {
    char **evento1, **evento2, letra;
    int i, j;
    bool retorno;

    evento1 = ( char** ) malloc( 2 * sizeof ( char ) );
    evento2 = ( char** ) malloc( 2 * sizeof ( char ) );
   
    evento1[0] = ( char* ) malloc ( 5 * sizeof ( char ) );
    evento1[1] = ( char* ) malloc ( 5 * sizeof ( char ) );

    evento2[0] = ( char* ) malloc ( 5 * sizeof ( char ) );
    evento2[1] = ( char* ) malloc ( 5 * sizeof ( char ) );

    for (i = 0; i < 2; i++) {
        printf ( "Informe o primeiro evento: " );
        letra =  getchar( );
        for (j = 0; j < 5; j++) {
            evento1[i][j]  = letra;
            letra = getchar( );
        }
    }

    for (i = 0; i < 2; i++) {
        printf ( "Informe o segundo evento: " );
        letra =  getchar();
        for (j = 0; j < 5; j++) {
            evento2[i][j]  = letra;
            letra = getchar( );
        }
    }
    retorno = haveConflict ( evento1, evento2 );
    if ( retorno ) printf ("\nTrue");
    else printf ( "\nFalse" );

    for ( i = 0; i < 3; i++) {
        free ( evento1[i] );
        free ( evento2[i] );
    }
    free ( evento1 );
    free ( evento2 );
}