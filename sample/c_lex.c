/*
====
regex: '(\s)|(\t)'
priority: 0
hander: 
printf("BLANK :: '%s'\n", shm_str);
====
*/

/*
====
regex: '(\n)|(\r)'
priority: 1
hander: 
printf("New Line\n");
====
*/

/*
====
regex: '(if)|(else)|(while)|(do)|(break)|(switch)|(for)|(case)|(struct)|(typedef)'
priority: 2
hander: 
printf("KEY WORD :: '%s'\n", shm_str);
====
*/

/*
====
regex: '(int)|(float)|(double)|(long)|(char)'
priority: 3
hander: 
printf("TYPE :: '%s'\n", shm_str);
====
*/

/*
====
regex: '(un)?signed'
priority: 4
hander: 
printf("TYPE_MODIFIER :: '%s'\n", shm_str);
====
*/

/*
====
regex: '#((include)|(define)|(undef)|(ifdef)|(ifndef)|(if)|(endif)|(elif)|(else))'
priority: 5
hander: 
printf("PREPROC_DERIV :: '%s'\n", shm_str);
====
*/

/*
====
regex: '([a-zA-Z_])([a-z0-9A-Z_]*)'
priority: 6
hander: 
printf("IDENTIFIER :: '%s'\n", shm_str);
====
*/

/*
====
regex: '([1-9])([0-9]*)|([0-9])'
priority: 7
hander: 
printf("INTEGER :: '%s'\n", shm_str);
====
*/

/*
====
regex: '(\+)|(\-)|(\*)|/|%'
priority: 8
hander: 
printf("ARITHMETIC_OP :: '%s'\n", shm_str);
====
*/

/*
====
regex: '(==)|(&&)|(\|\|)|!|<|>|(<=)|(>=)'
priority: 9
hander: 
printf("LOGICAL_OP :: '%s'\n", shm_str);
====
*/

/*
====
regex: '^|&|~|\|'
priority: 10
hander: 
printf("BIT_OP :: '%s'\n", shm_str);
====
*/

/*
====
regex: '\->'
priority: 11
hander: 
printf("ACCESS_OP :: '%s'\n", shm_str);
====
*/

/*
====
regex: '='
priority: 12
hander: 
printf("ASSIGN_OP :: '%s'\n", shm_str);
====
*/

/*
====
regex: ';'
priority: 13
hander: 
printf("SEMICOLON :: '%s'\n", shm_str);
====
*/

/*
====
regex: '\.'
priority: 14
hander: 
printf("DOT :: '%s'\n", shm_str);
====
*/

/*
====
regex: ','
priority: 15
hander: 
printf("COMMA :: '%s'\n", shm_str);
====
*/

/*
====
regex: '\['
priority: 16
hander: 
printf("LEFT_SQBRAC :: '%s'\n", shm_str);
====
*/

/*
====
regex: '\]'
priority: 17
hander: 
printf("RIGHT_SQBRAC :: '%s'\n", shm_str);
====
*/

/*
====
regex: '\('
priority: 18
hander: 
printf("LEFT_PAREN :: '%s'\n", shm_str);
====
*/

/*
====
regex: '\)'
priority: 19
hander: 
printf("RIGHT_PAREN :: '%s'\n", shm_str);
====
*/

/*
====
regex: '}'
priority: 20
hander: 
printf("BLOCK_START :: '%s'\n", shm_str);
====
*/

/*
====
regex: '{'
priority: 21
hander: 
printf("BLOCK_END :: '%s'\n", shm_str);
====
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void end_handler_0(char* shm_str) {
printf("BLANK :: '%s'\n", shm_str);
}
void end_handler_1(char* shm_str) {
printf("New Line\n");
}
void end_handler_2(char* shm_str) {
printf("KEY WORD :: '%s'\n", shm_str);
}
void end_handler_3(char* shm_str) {
printf("TYPE :: '%s'\n", shm_str);
}
void end_handler_4(char* shm_str) {
printf("TYPE_MODIFIER :: '%s'\n", shm_str);
}
void end_handler_5(char* shm_str) {
printf("PREPROC_DERIV :: '%s'\n", shm_str);
}
void end_handler_6(char* shm_str) {
printf("IDENTIFIER :: '%s'\n", shm_str);
}
void end_handler_7(char* shm_str) {
printf("INTEGER :: '%s'\n", shm_str);
}
void end_handler_8(char* shm_str) {
printf("ARITHMETIC_OP :: '%s'\n", shm_str);
}
void end_handler_9(char* shm_str) {
printf("LOGICAL_OP :: '%s'\n", shm_str);
}
void end_handler_10(char* shm_str) {
printf("BIT_OP :: '%s'\n", shm_str);
}
void end_handler_11(char* shm_str) {
printf("ACCESS_OP :: '%s'\n", shm_str);
}
void end_handler_12(char* shm_str) {
printf("ASSIGN_OP :: '%s'\n", shm_str);
}
void end_handler_13(char* shm_str) {
printf("SEMICOLON :: '%s'\n", shm_str);
}
void end_handler_14(char* shm_str) {
printf("DOT :: '%s'\n", shm_str);
}
void end_handler_15(char* shm_str) {
printf("COMMA :: '%s'\n", shm_str);
}
void end_handler_16(char* shm_str) {
printf("LEFT_SQBRAC :: '%s'\n", shm_str);
}
void end_handler_17(char* shm_str) {
printf("RIGHT_SQBRAC :: '%s'\n", shm_str);
}
void end_handler_18(char* shm_str) {
printf("LEFT_PAREN :: '%s'\n", shm_str);
}
void end_handler_19(char* shm_str) {
printf("RIGHT_PAREN :: '%s'\n", shm_str);
}
void end_handler_20(char* shm_str) {
printf("BLOCK_START :: '%s'\n", shm_str);
}
void end_handler_21(char* shm_str) {
printf("BLOCK_END :: '%s'\n", shm_str);
}
void shm_parse(FILE* shm_file) {
int shm_state;
int shm_i;
char shm_c;
char buffer[1024];
char buffer_index;
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
while (EOF != (shm_c = fgetc(shm_file))) {
  buffer[buffer_index] = shm_c;
  buffer_index++; buffer[buffer_index]='\0';
  switch(shm_state) {
case 0:
  switch(shm_c) {
    case '\n':    // 10
      shm_state = 1;
    break;
    case '\r':    // 13
      shm_state = 1;
    break;
    case ' ':    // 32
      shm_state = 2;
    break;
    case '!':    // 33
      shm_state = 3;
    break;
    case '#':    // 35
      shm_state = 4;
    break;
    case '%':    // 37
      shm_state = 24;
    break;
    case '&':    // 38
      shm_state = 25;
    break;
    case '(':    // 40
      shm_state = 26;
    break;
    case ')':    // 41
      shm_state = 27;
    break;
    case '*':    // 42
      shm_state = 24;
    break;
    case '+':    // 43
      shm_state = 24;
    break;
    case ',':    // 44
      shm_state = 28;
    break;
    case '-':    // 45
      shm_state = 29;
    break;
    case '.':    // 46
      shm_state = 31;
    break;
    case '/':    // 47
      shm_state = 24;
    break;
    case '0':    // 48
      shm_state = 32;
    break;
    case '1':    // 49
      shm_state = 33;
    break;
    case '2':    // 50
      shm_state = 33;
    break;
    case '3':    // 51
      shm_state = 33;
    break;
    case '4':    // 52
      shm_state = 33;
    break;
    case '5':    // 53
      shm_state = 33;
    break;
    case '6':    // 54
      shm_state = 33;
    break;
    case '7':    // 55
      shm_state = 33;
    break;
    case '8':    // 56
      shm_state = 33;
    break;
    case '9':    // 57
      shm_state = 33;
    break;
    case ';':    // 59
      shm_state = 34;
    break;
    case '<':    // 60
      shm_state = 35;
    break;
    case '=':    // 61
      shm_state = 36;
    break;
    case '>':    // 62
      shm_state = 35;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '[':    // 91
      shm_state = 38;
    break;
    case ']':    // 93
      shm_state = 39;
    break;
    case '^':    // 94
      shm_state = 40;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 41;
    break;
    case 'c':    // 99
      shm_state = 46;
    break;
    case 'd':    // 100
      shm_state = 52;
    break;
    case 'e':    // 101
      shm_state = 57;
    break;
    case 'f':    // 102
      shm_state = 58;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 63;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 64;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 67;
    break;
    case 't':    // 116
      shm_state = 81;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 87;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    case '{':    // 123
      shm_state = 90;
    break;
    case '|':    // 124
      shm_state = 91;
    break;
    case '}':    // 125
      shm_state = 92;
    break;
    case '~':    // 126
      shm_state = 40;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 1:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_1(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 2:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_0(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 3:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_9(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 4:
  switch(shm_c) {
    case 'd':    // 100
      shm_state = 5;
    break;
    case 'e':    // 101
      shm_state = 11;
    break;
    case 'i':    // 105
      shm_state = 16;
    break;
    case 'u':    // 117
      shm_state = 23;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 5:
  switch(shm_c) {
    case 'e':    // 101
      shm_state = 6;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 6:
  switch(shm_c) {
    case 'f':    // 102
      shm_state = 7;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 7:
  switch(shm_c) {
    case 'i':    // 105
      shm_state = 8;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 8:
  switch(shm_c) {
    case 'n':    // 110
      shm_state = 9;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 9:
  switch(shm_c) {
    case 'e':    // 101
      shm_state = 10;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 10:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_5(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 11:
  switch(shm_c) {
    case 'l':    // 108
      shm_state = 12;
    break;
    case 'n':    // 110
      shm_state = 14;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 12:
  switch(shm_c) {
    case 'i':    // 105
      shm_state = 13;
    break;
    case 's':    // 115
      shm_state = 9;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 13:
  switch(shm_c) {
    case 'f':    // 102
      shm_state = 10;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 14:
  switch(shm_c) {
    case 'd':    // 100
      shm_state = 15;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 15:
  switch(shm_c) {
    case 'i':    // 105
      shm_state = 13;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 16:
  switch(shm_c) {
    case 'f':    // 102
      shm_state = 17;
    break;
    case 'n':    // 110
      shm_state = 19;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 17:
  switch(shm_c) {
    case 'd':    // 100
      shm_state = 5;
    break;
    case 'n':    // 110
      shm_state = 18;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_5(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 18:
  switch(shm_c) {
    case 'd':    // 100
      shm_state = 5;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 19:
  switch(shm_c) {
    case 'c':    // 99
      shm_state = 20;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 20:
  switch(shm_c) {
    case 'l':    // 108
      shm_state = 21;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 21:
  switch(shm_c) {
    case 'u':    // 117
      shm_state = 22;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 22:
  switch(shm_c) {
    case 'd':    // 100
      shm_state = 9;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 23:
  switch(shm_c) {
    case 'n':    // 110
      shm_state = 18;
    break;
    default:
      fprintf(stdout, "Parse Error : %s\n", buffer);
      fprintf(stdout, "Parse Error : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Parse Error\n");
      exit(1);
      break;
    }
  break;
case 24:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_8(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 25:
  switch(shm_c) {
    case '&':    // 38
      shm_state = 3;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_10(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 26:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_18(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 27:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_19(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 28:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_15(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 29:
  switch(shm_c) {
    case '>':    // 62
      shm_state = 30;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_8(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 30:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_11(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 31:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_14(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 32:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_7(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 33:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 33;
    break;
    case '1':    // 49
      shm_state = 33;
    break;
    case '2':    // 50
      shm_state = 33;
    break;
    case '3':    // 51
      shm_state = 33;
    break;
    case '4':    // 52
      shm_state = 33;
    break;
    case '5':    // 53
      shm_state = 33;
    break;
    case '6':    // 54
      shm_state = 33;
    break;
    case '7':    // 55
      shm_state = 33;
    break;
    case '8':    // 56
      shm_state = 33;
    break;
    case '9':    // 57
      shm_state = 33;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_7(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 34:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_13(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 35:
  switch(shm_c) {
    case '=':    // 61
      shm_state = 3;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_9(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 36:
  switch(shm_c) {
    case '=':    // 61
      shm_state = 3;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_12(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 37:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 38:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_16(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 39:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_17(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 40:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_10(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 41:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 42;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 42:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 43;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 43:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 44;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 44:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 45;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 45:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_2(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 46:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 47;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 49;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 47:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 48;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 48:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 45;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 49:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 50;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 50:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 51;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 51:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_3(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 52:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 53;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 53:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 54;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_2(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 54:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 55;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 55:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 56;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 56:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 51;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 57:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 47;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 58:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 59;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 62;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 59:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 60;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 60:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 61;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 61:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 51;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 62:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 45;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 63:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 45;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 61;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 64:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 65;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 65:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 66;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 66:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 51;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 67:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 68;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 73;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 77;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 68:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 69;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 69:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 70;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 70:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 71;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 71:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 72;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 72:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_4(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 73:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 74;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 74:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 75;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 75:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 76;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 76:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 45;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 77:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 78;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 78:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 79;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 79:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 80;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 80:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 45;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 81:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 82;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_0(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 82:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 83;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 83:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 84;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 84:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 85;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 85:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 86;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 86:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 45;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 87:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 88;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 88:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 89;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 37;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 89:
  switch(shm_c) {
    case '0':    // 48
      shm_state = 37;
    break;
    case '1':    // 49
      shm_state = 37;
    break;
    case '2':    // 50
      shm_state = 37;
    break;
    case '3':    // 51
      shm_state = 37;
    break;
    case '4':    // 52
      shm_state = 37;
    break;
    case '5':    // 53
      shm_state = 37;
    break;
    case '6':    // 54
      shm_state = 37;
    break;
    case '7':    // 55
      shm_state = 37;
    break;
    case '8':    // 56
      shm_state = 37;
    break;
    case '9':    // 57
      shm_state = 37;
    break;
    case 'A':    // 65
      shm_state = 37;
    break;
    case 'B':    // 66
      shm_state = 37;
    break;
    case 'C':    // 67
      shm_state = 37;
    break;
    case 'D':    // 68
      shm_state = 37;
    break;
    case 'E':    // 69
      shm_state = 37;
    break;
    case 'F':    // 70
      shm_state = 37;
    break;
    case 'G':    // 71
      shm_state = 37;
    break;
    case 'H':    // 72
      shm_state = 37;
    break;
    case 'I':    // 73
      shm_state = 37;
    break;
    case 'J':    // 74
      shm_state = 37;
    break;
    case 'K':    // 75
      shm_state = 37;
    break;
    case 'L':    // 76
      shm_state = 37;
    break;
    case 'M':    // 77
      shm_state = 37;
    break;
    case 'N':    // 78
      shm_state = 37;
    break;
    case 'O':    // 79
      shm_state = 37;
    break;
    case 'P':    // 80
      shm_state = 37;
    break;
    case 'Q':    // 81
      shm_state = 37;
    break;
    case 'R':    // 82
      shm_state = 37;
    break;
    case 'S':    // 83
      shm_state = 37;
    break;
    case 'T':    // 84
      shm_state = 37;
    break;
    case 'U':    // 85
      shm_state = 37;
    break;
    case 'V':    // 86
      shm_state = 37;
    break;
    case 'W':    // 87
      shm_state = 37;
    break;
    case 'X':    // 88
      shm_state = 37;
    break;
    case 'Y':    // 89
      shm_state = 37;
    break;
    case 'Z':    // 90
      shm_state = 37;
    break;
    case '_':    // 95
      shm_state = 37;
    break;
    case 'a':    // 97
      shm_state = 37;
    break;
    case 'b':    // 98
      shm_state = 37;
    break;
    case 'c':    // 99
      shm_state = 37;
    break;
    case 'd':    // 100
      shm_state = 37;
    break;
    case 'e':    // 101
      shm_state = 37;
    break;
    case 'f':    // 102
      shm_state = 37;
    break;
    case 'g':    // 103
      shm_state = 37;
    break;
    case 'h':    // 104
      shm_state = 37;
    break;
    case 'i':    // 105
      shm_state = 37;
    break;
    case 'j':    // 106
      shm_state = 37;
    break;
    case 'k':    // 107
      shm_state = 37;
    break;
    case 'l':    // 108
      shm_state = 48;
    break;
    case 'm':    // 109
      shm_state = 37;
    break;
    case 'n':    // 110
      shm_state = 37;
    break;
    case 'o':    // 111
      shm_state = 37;
    break;
    case 'p':    // 112
      shm_state = 37;
    break;
    case 'q':    // 113
      shm_state = 37;
    break;
    case 'r':    // 114
      shm_state = 37;
    break;
    case 's':    // 115
      shm_state = 37;
    break;
    case 't':    // 116
      shm_state = 37;
    break;
    case 'u':    // 117
      shm_state = 37;
    break;
    case 'v':    // 118
      shm_state = 37;
    break;
    case 'w':    // 119
      shm_state = 37;
    break;
    case 'x':    // 120
      shm_state = 37;
    break;
    case 'y':    // 121
      shm_state = 37;
    break;
    case 'z':    // 122
      shm_state = 37;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_6(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 90:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_21(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 91:
  switch(shm_c) {
    case '|':    // 124
      shm_state = 3;
    break;
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_10(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
case 92:
  switch(shm_c) {
    default:
      fseek(shm_file, -1, SEEK_CUR);
      buffer_index--;buffer[buffer_index] = '\0';
end_handler_20(buffer);
buffer[0] = '\0';
buffer_index = 0;
shm_state = 0;
    }
  break;
  }
}
}
int main(int argc, char** argv) {
  FILE* infile; 
  infile = fopen(argv[1], "r");
  shm_parse(infile);
  fclose(infile);
}
