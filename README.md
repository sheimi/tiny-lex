TINY-LEX
========

Overview
--------

This is the homework of 'compiler' -- to implement a tiny lex.

MYLEX SYNTAX
------------

File Format
    [N] the number of entries
    [Entry]
    [Entry]
    ...
Entry Format
    [Regex]
    [Handler] with the param (shm_str)
    ========= (at least 4 '=')
Smaple
    2
    a*b|c
    printf("This is : %s\n", shm_str);
    ===========
    (c*|d)|a
    printf("That is %s\n", shm_str);
    ===========
