// pstr.c
// PascalString (c) 2025 Baltasar MIT License <baltasarq@gmail.com>


#include "pstr.h"

#include <string.h>
#include <stdlib.h>


inline
size_t pstr_len(const pstr *s)
{
    return (size_t) ( (unsigned char) s->raw[ 0 ] );
}

static inline
void set_len(pstr *s, size_t len)
{
    s->raw[ 0 ] = (unsigned char) len;
}

inline
const char * pstr_to_cstr(const pstr *s)
{
    return s->raw + 1;
}

inline
void pstr_destroy(pstr * s)
{
    free( s );
}

inline
char pstr_get(const pstr *s, size_t pos)
{
    if ( pos <= pstr_len( s ) ) {
        return s->raw[ 1 + pos ];
    }
    
    return '\0';
}

inline
pstr * pstr_create()
{
    pstr * toret = (pstr *) malloc( sizeof( pstr ) );
    
    if ( toret != NULL ) {
        toret->raw[ 0 ] = toret->raw[ 1 ] = 0;
    }
    
    return toret;
}

pstr * pstr_copy(const pstr *s)
{
    pstr * toret = pstr_create();
    
    if ( toret != NULL ) {
        size_t len = pstr_len( s );
        
        if ( len > PSTR_MAX_CHARS ) {
            len = PSTR_MAX_CHARS;
        }
        
        strncpy(
            (char *) pstr_to_cstr( toret ),
            pstr_to_cstr( s ),
            len + 1 );

        set_len( toret, len );
    }
    
    return toret;
}

pstr * pstr_create_from(const char * s)
{
    size_t len = strlen( s );
    pstr * toret = pstr_create();
    
    if ( toret != NULL ) {
        if ( len > PSTR_MAX_CHARS ) {
            len = PSTR_MAX_CHARS;
        }
        
        strncpy(
            (char *) pstr_to_cstr( toret ),
            s,
            len + 1 );

        set_len( toret, len );
    }
    
    return toret;
}

pstr * pstr_concat(const pstr *s1, const pstr *s2)
{
    pstr * toret = pstr_create_from( pstr_to_cstr( s1 ) );
    
    if ( toret != NULL ) {
        size_t len_s1 = pstr_len( s1 );
        size_t len_s2 = pstr_len( s2 );
        size_t space_left = PSTR_MAX_CHARS - len_s1;

        if ( len_s2 > space_left ) {
            len_s2 = space_left;
        }
        
        strncpy(
            (char *) pstr_to_cstr( toret ) + len_s1,
            pstr_to_cstr( s2 ),
            len_s2 );
            
        toret->raw[ 1 + len_s1 + len_s2 ] = '\0';
        set_len( toret, len_s1 + len_s2 );
    }
    
    return toret;
}
