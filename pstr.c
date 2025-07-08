// pstr.c
// PascalString (c) 2025 Baltasar MIT License <baltasarq@gmail.com>


#include "pstr.h"

#include <string.h>
#include <stdlib.h>


inline size_t pstr_len(const pstr *s)
{
    return (size_t) s->raw[ 0 ];
}

inline const char * pstr_to_cstr(const pstr *s)
{
    return s->raw + 1;
}

inline void pstr_destroy(pstr * s)
{
    free( s );
}

inline char pstr_get(const pstr *s, size_t pos)
{
    if ( pos <= PSTR_MAX_CHARS ) {
        return s->raw[ pos + 1 ];
    }
    
    return 0;
}

pstr * pstr_create()
{
    pstr * toret = (pstr *) malloc( sizeof( pstr ) );
    
    toret->raw[ 0 ] = toret->raw[ 1 ] = 0;
    
    return toret;
}

pstr * pstr_copy(const pstr *s)
{
    pstr * toret = pstr_create();
    
    strncpy(
        (char *) pstr_to_cstr( toret ),
        pstr_to_cstr( s ),
        PSTR_MAX_CHARS );

    toret->raw[ 0 ] = (unsigned char) pstr_len( s );
    
    return toret;
}

pstr * pstr_create_from(const char * s)
{
    size_t len = strlen( s );
    pstr * toret = NULL;
    
    if ( len <= PSTR_MAX_CHARS ) {
        toret = pstr_create();
        
        strncpy(
            (char *) pstr_to_cstr( toret ),
            s,
            PSTR_MAX_CHARS );

        toret->raw[ 0 ] = (char) len;
    }
    
    return toret;
}

pstr * pstr_concat(const pstr *s1, const pstr *s2)
{
    size_t target_len = pstr_len( s1 ) + pstr_len( s2 );
    pstr * toret = NULL;
    
    if ( target_len <= PSTR_MAX_CHARS ) {
        toret = pstr_create_from( pstr_to_cstr( s1 ) );
        size_t s1_len = pstr_len( toret );
        
        strncpy(
            (char *) pstr_to_cstr( toret ) + s1_len,
            pstr_to_cstr( s2 ),
            PSTR_MAX_CHARS - s1_len );
            
        toret->raw[ 0 ] = s1_len + pstr_len( s2 );
    }
    
    return toret;
}
