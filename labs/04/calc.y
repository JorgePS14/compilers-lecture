%{
#include <stdio.h>
#include <math.h>
double varArr[23];
extern FILE *yyin;
extern FILE *yyout;
extern int yylex();
%}

%union {
	double dval;
	int vblno;
}

%token PRINT INTDCL FLOATDCL ASSIGN ADD SUB MUL DIV
%token <dval> INT FLOAT
%token <vblno> ID
%type <dval> expression value division
%%

prog: declarations statements

declarations: declaration declarations
	    |	;

declaration: INTDCL ID {varArr[$2] = 0;}
	   | FLOATDCL ID {varArr[$2] = 0;};

statements: statement statements
	  |	;

statement: ID ASSIGN expression {varArr[$1] = $3;}
	 | PRINT ID {printf("%g\n", varArr[$2]);}
	 |	;

expression: value ADD expression {$$ = $$ + $3;}
	  | value MUL expression {$$ = $$ * $3;}
	  | value SUB expression {$$ = $$ - $3;}
	  | value DIV division {$$ = $$ / $3;}
	  | value {$$ = $1;};
division: value {if($1 != 0.0) {
			$$ = $1;
			return 0;
		} else {
			yyerror("Error: Division by zero is not permitted.\n");
			return -1;
		}};
value: INT {$$ = $1;}
     | FLOAT {$$ = $1;}
     | ID {$$ = varArr[$1];};
%%

int main(int argc, char **argv) {
	FILE *fd;

	if(argc == 2) {
		if(!(fd = fopen(argv[1], "r"))) {
			perror("Error: Could not open file.");
			return -1;
		}
		yyin = fd;
		yyparse();
		return 0;
	}
	printf("Please use the correct format: a.out <<file>>\n");
	return 0;

}
