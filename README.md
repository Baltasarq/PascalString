# Pascal String

A C implementation of Pascal strings.

**p-strings** ([Pascal Strings](https://en.wikipedia.org/wiki/String_(computer_science))),  are created as 1/4 kb blocks: the first char is devoted to store the length of the string, while the remaining bytes (255) are dedicated to store the string itself. This means that strings are always aligned in memory, in chunks of exact size. Also, the obtaining the length of the string is an O(1) operation, while using a C-String getting the length is an O(n) operation (`strlen()`). The downside is that you can only use 255 characters, tops.

Of course, no UTF-8. This was just at a time (with **Basic** in '80s, **Pascal** in '90s...). when ASCII was used. You could easily implement UTF-16, though, reserving two bytes for each character, but limiting strings to 127 chars.

In this implementation, the max characters that can be stored are 254. This is because still a trailing zero is used so these strings are interoperable with C strings (`string.h`, those `str***()` functions). I remark this is only for interfacing with C Strings, Pascal Strings do not use a trailing zero.

There have been indeed lots of hybrid implementations, such as C Strings which also store the size of the string in their (hidden) first bytes. Or **p-strings** that use a character termniator or more than one byte for the length.
