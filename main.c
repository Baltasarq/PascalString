// PascalString (c) 2025 Baltasar MIT License <baltasarq@gmail.com>


#include <stdio.h>

#include "pstr.h"


int main(int argc, char **argv)
{
    pstr * big_str1 = pstr_create_from(
                        "0123456789a0123456789b0123456789c0123456789d\n" );
    pstr * big_str2 = pstr_copy( big_str1 );
    pstr * big_str3 = pstr_concat( big_str1, big_str2 );
    pstr * big_str4 = pstr_copy( big_str3 );
    pstr * big_str5 = pstr_concat( big_str3, big_str4 );
    pstr * big_str6 = pstr_copy( big_str5 );
    pstr * big_str7 = pstr_concat( big_str5, big_str6 );

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
    
    printf( "%03d:\n%s\n", pstr_len( big_str1 ), pstr_to_cstr( big_str1 ) );
    printf( "%03d:\n%s\n", pstr_len( big_str3 ), pstr_to_cstr( big_str3 ) );
    printf( "%03d:\n%s\n", pstr_len( big_str5 ), pstr_to_cstr( big_str5 ) );
    printf( "%03d:\n%s\n", pstr_len( big_str7 ), pstr_to_cstr( big_str7 ) );
    
    pstr_destroy( s0 );
    pstr_destroy( s1 );
    pstr_destroy( s2 );
    pstr_destroy( s3 );
    pstr_destroy( big_str1 );
    pstr_destroy( big_str2 );
    pstr_destroy( big_str3 );
    pstr_destroy( big_str4 );
    pstr_destroy( big_str5 );
    pstr_destroy( big_str6 );
    pstr_destroy( big_str7 );
    return 0;
}
