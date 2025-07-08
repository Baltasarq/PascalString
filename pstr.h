// pstr.h
// PascalString (c) 2025 Baltasar MIT License <baltasarq@gmail.com>


#include <stddef.h>


#define PSTR_MAX_CHARS 254

typedef struct p_str {
    /* Position 0         : holds the length of the string (0-254).
     * Position 1         : It's the position 0 of the string.
     * Position n         : It's the (n - 1)th position of the string.
     * Position length - 1: It's a 0, to be able to interact with C strings.
     */
    char raw[PSTR_MAX_CHARS + 2];
} pstr;


/** @return a new Pascal string. */
pstr * pstr_create();

/** Free memory associated to s. */
void pstr_destroy(pstr * s);

/** @return a new Pascal string, being a copy of s. */
pstr * pstr_create_from(const char * s);

/** @param pstr2 a string to copy.
  * @return a new Pascal String as a copy of s.
  */
pstr * pstr_copy(const pstr *s);

/** @param s1 a given Pascal String.
  * @param s2 a given Pascal String.
  * @return the concatenation of s1 and s2.
  */
pstr * pstr_concat(const pstr * s1, const pstr * s2);

/** @return the number of characters. */
size_t pstr_len(const pstr *s);

/** @param pos a given position.
  * @param s the Pascal String to extrach chars from.
  * @return the character at position pos.
  */
char pstr_get(const pstr * s, size_t pos);

/** @return a C string version of this Pascal String. */
const char * pstr_to_cstr(const pstr * s);
