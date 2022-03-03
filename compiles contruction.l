%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int str=0;
int num=0;
int  newline=0; 
int tap=0;
int sym=0;
%}
letter [A-Za-z]
digit [0-9]
symbol [+|-|*|=|<|<=|>|>=|<>|.|,|:|:|.|:=]
%%
if|for|else|end|and|begin|forword|div|do|function|array|mod|not|of|or|procedure|program|record|then|to|type|var|while {printf("keyword");}
[A-Z]* {printf ("ID (UPPER) \t");str++;}
[a-z]* {printf ("ID (1ower) \t");str++;}
[A-Za-z][a-zA-Z0-9]* {printf("ID\t");}
[0-9]+ {printf("INT\t");num++;}
[+|-|*|=|<] {printf("SYM\t");sym++;}
[<=|>|>=|<>|.|,|:|;|..|:=] {printf("SYM\t");sym++;}
[        ]+ {printf("tap\t");tap++;}
[\n]+ {printf("newline\t");newline++;}
"{".*"}" {printf("%s\n", yytext);}
%%
int yywarp(){
    return 1 ;
}
int main(){
    printf("Enter a string\n");
    yylex();
    printf("STR=%d  and SYM=%d and INT=%d and keyword=%s and tap=%d and newline=%d" ,str,sym,num,yytext,tap,newline);
    
}