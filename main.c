// PascalString (c) 2025 Baltasar MIT License <baltasarq@gmail.com>


#include <stdio.h>

#include "pstr.h"


int main(int argc, char **argv)
{
    pstr * s0 = pstr_create_from( "Hola, " );
    pstr * s1 = pstr_copy( s0 );
    pstr * s2 = pstr_create_from( "mundo!" );
    pstr * s3 = pstr_concat( s1, s2 );
    
    printf("%d: '%s'\n", pstr_len( s1 ), pstr_to_cstr( s1 ) );
    printf("%d: '%s'\n", pstr_len( s2 ), pstr_to_cstr( s2 ) );
    printf("%d: '%s'\n", pstr_len( s3 ), pstr_to_cstr( s3 ) );
    
    for(size_t i = 0; i < pstr_len( s3 ); ++i) {
        char c = pstr_get( s3, i );
        
        printf("'%c' (%03d) ", c, c );
    }
    
    printf( "\n" );
    printf( "%s\n", pstr_to_cstr( s3 ) );
    printf( "%s%s\n", pstr_to_cstr( s1 ), pstr_to_cstr( s2 ) );
    
    return 0;
}
