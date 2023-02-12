#include <stdio.h>

int main( void ) {
	int n, i, cont_A = 0, cont_B = 0, cont_C = 0, cont_D = 0, cont_E = 0;
    char nota;

	scanf ( "%d", &n );
	
    for (i = 1; i <= n; i++)
    {
        getchar ();
        scanf ( "%c", &nota );

        if ( nota =='A' ) cont_A++;
        else if ( nota == 'B' ) cont_B++;
        else if ( nota == 'C' ) cont_C++;
        else if ( nota == 'D' ) cont_D++;
        else if ( nota == 'E' ) cont_E++;
        else {
            printf ( "nota invalida\n" );
            i--;
        }
    }

    printf ( "A: %d \nB: %d \nC: %d \nD: %d \nE: %d", cont_A, cont_B, cont_C, cont_D, cont_E );
    return ( 0 );
}