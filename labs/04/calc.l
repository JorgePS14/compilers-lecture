%{
#include <stdio.h>
#include "y.tab.h"
extern double varArr[23];
%}

%%
p                               {return PRINT;}
i                               {return INTDCL;}
f                               {return FLOATDCL;}
[a-eg-hj-oq-z]                  {yylval.vblno = (int)yytext[0] - 97;
				return ID;}
[0-9]+                          {yylval.dval = atoi(yytext);
				return INT;}
[0-9]+"."[0-9]+                 {yylval.dval = atof(yytext);
				return FLOAT;}
=                               {return ASSIGN;}
\+                              {return ADD;}
\-                              {return SUB;}
\*                              {return MUL;}
\/                              {return DIV;}
\/\/.*[\n]                      {// Ignore comments.
				}
[ \t]                           {// Ignore whitespaces.
				}
\n                              {// Ignore newLine.
				}
<<EOF>>                         {// Ignore End of File.
				} 
%%
