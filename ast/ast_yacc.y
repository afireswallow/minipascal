%{
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include "ast.c"

#define MAXSTR 20
#define MAXMEMBER 100

#define INTTYPE  0
#define REALTYPE 1
#define ARRAYTYPE 5

extern struct node root;

extern int yylex();
extern FILE* yyin;
extern char str1[20];
/*int CheckKeyWord(char *str);*/
void OutputQ(void);
int yyparse();
void OutputIList(void);
int yyerror(char*);

int LookUp(char* name);
int Enter(char* name);
int Entry(char* name);
int Gen(char* op, int arg1, int arg2, int result);
int NewTemp(void);
int Merge(int p1, int p2);
void BackPatch(int p, int t);
void make_node(struct node *father, char *s);
void make_father(struct node **nd, char *s);
void output_ast(struct node *nd, int num);

int VarCount=0;
int SymbolCount = 0;
int TempCount = 0;
int add = 0;
FILE* fp;
int NXQ=0;  /* used to indicate the number of next Quater*/


struct QUATERLIST {
	char op[6];
	int arg1,arg2,result;
} 
QuaterList[MAXMEMBER];

struct VARLIST{
	char name[20];
	int type;
	int addr;
	/*union{int Iv;float Rv;} Value;*/
} VarList[MAXMEMBER];

struct SYMBOLLIST{
	char name[20];
	int type;
	int addr;
} SymbolList[MAXMEMBER];

%}
%start    ProgDef
%union 
{
	struct { struct node *nd; int n;} Iv;
	struct { struct node *nd; int n;} CH;
	struct { struct node *nd; int n;} NO;
	struct { struct node *nd; int TC,FC;} _BExpr;
	struct { struct node *nd; int LoopStartPlace, Chain;} _WBD;
	struct { struct node *nd; int type,place;} _Expr;
	struct { struct node *nd; char s[5];} _Rop;
	struct { struct node *nd; int n;} First;
	char str[20];
	struct node *ast_node;
	struct { struct node *nd; int place, Chain, Loop;} _FoL;
}
/*Define const:  */
%token <str>   	Iden    300
%token <str>   	IntNo		301
%token <str>  	RealNo  302
/*Define keywords here:*/
%token	<str>  	Program 400
%token	<str>  	Begin		401
%token	<str> 	End			402
%token	<str>  	Var			403
%token	<str>  	Integer 	404
%token	<str>  	Real		405
%token	<str>  	While		406
%token	<str>  	Do			407
%token	<str>	If			408
%token	<str>	Then		409
%token	<str>	Else		410
%token	<str>	Or			411
%token	<str>	And			412
%token	<str>	Not			413
%token  <str>	For			414
%token  <str>	To			415
%token	<str>	Array		416
%token  <str>	Of			417
/*Define double_character terminates:   */
%token	<str>	LE	500
%token	<str>	GE	501
%token	<str>	NE	502

%left 	Or
%left		And
%nonassoc  	Not
%nonassoc '<' '>' '=' LE GE NE
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS


%type <ast_node> ProgDef
%type <ast_node> SubProg
%type <CH> VarDef
%type <CH> VarDefList
%type <Iv> Type
%type <CH> VarDefState
%type <First> VarList
%type <CH> Statement
%type <CH> StateList
%type <CH> S_L
%type <CH> CompState
%type <CH> AsignState
%type <CH> ISE
%type <CH> IBT
%type <_WBD> WBD
%type <_Rop> RelationOp
%type <_Expr> Expr
%type <CH> Wh
%type <NO> Variable 
%type <_Expr> Const 
%type <_BExpr> BoolExpr
%type <_BExpr> BoolExprAnd
%type <_BExpr> BoolExprOr
%type <_FoL> ForLoop


%%
//program
ProgDef:	Program Iden {set_node_val_str(&root,str1);} ';' SubProg '.'
        {
			printf("\n\n**** test ast node ****\n");
			$$=&root;
			make_node($$, "Program");
			make_node($$, root.val.str);
			make_node($$, ";");
        	add_son_node($$, $5);
			make_node($$, ".");

			output_ast(&root, 0);

			printf("**** Program %s ****\n",root.val.str);
        }
	;
//var begin end
SubProg:	VarDef CompState
		{
			make_father(&$$, "SubProg");
			add_son_node($$, $1.nd);
			add_son_node($$, $2.nd);
		}
	;
//var
VarDef:		Var VarDefList ';'
        {
			make_father(&$$.nd, "VarDef");
			make_node($$.nd, "Var");
			add_son_node($$.nd, $2.nd);
			make_node($$.nd, ";");
		}
	;
//muticle var
VarDefList:	VarDefList';'VarDefState
        {
			make_father(&$$.nd, "VarDefList");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, ";");
			add_son_node($$.nd, $3.nd);
		}
	|	VarDefState
	    {
			make_father(&$$.nd, "VarDefList");
			add_son_node($$.nd, $1.nd);
        }
	;
//single var
VarDefState:	VarList':'Type
		{
			for (int i = 0; i < SymbolCount; i++){
				if (SymbolList[SymbolCount - i].type == 2){
					SymbolList[SymbolCount - i].type = $3.n;
					VarList[VarCount].type = $3.n;
					strcpy(VarList[VarCount].name, SymbolList[SymbolCount - i].name);
					if ($3.n == ARRAYTYPE) {
						SymbolList[SymbolCount - i].addr = add;
						VarList[VarCount].addr = add;
					}
					VarCount++;
				}
				else {
					break;
				}
			}

			make_father(&$$.nd, "VarDefState");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, ":");
			add_son_node($$.nd, $3.nd);
		}
	;
Type:	Integer
		{
			$$.n = INTTYPE;

			make_father(&$$.nd, "Type");
			make_node($$.nd, "Integer");
		}
	|	Real
		{
			$$.n = REALTYPE;

			make_father(&$$.nd, "Type");
			make_node($$.nd, "Real");
		}
	|	Array '[' IntNo ']' Of Type
		{
			$$.n = ARRAYTYPE;

			add = atoi(str1);
			make_father(&$$.nd, "Type");
			make_node($$.nd, "[");
			make_node($$.nd, str1);
			make_node($$.nd, "]");
			make_node($$.nd, "Of");
			add_son_node($$.nd, $6.nd);
		}
	;
VarList:	VarList','Variable
		{
			if ($3.n) {
				yyerror("repeat the var\n");
				return 0;
			}

			make_father(&$$.nd, "VarList");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, ",");
			add_son_node($$.nd, $3.nd);
		}
	|	Variable
		{
			if ($1.n) {	
				yyerror("repeat the var\n");
				return 0;
			}

			make_father(&$$.nd, "VarList");
			add_son_node($$.nd, $1.nd);
		}
	;
StateList:	S_L Statement
		{
			$$.n = $2.n;

			make_father(&$$.nd, "StateList");
			add_son_node($$.nd, $1.nd);
			add_son_node($$.nd, $2.nd);
		}
	|	Statement
		{
			$$.n = $1.n;

			make_father(&$$.nd, "StateList");
			add_son_node($$.nd, $1.nd);
		}
	;
S_L:		StateList ';'
		{
			BackPatch($1.n, NXQ);

			make_father(&$$.nd, "S_L");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, ";");
		}
	;
Statement:	AsignState
		{
			$$.n = 0;

			make_father(&$$.nd, "Statement");
			add_son_node($$.nd, $1.nd);
		}
	|	ISE Statement
		{
			$$.n = Merge($1.n, $2.n);

			make_father(&$$.nd, "Statement");
			add_son_node($$.nd, $1.nd);
			add_son_node($$.nd, $2.nd);
		}
	|	IBT Statement
		{
			$$.n = Merge($1.n, $2.n);

			make_father(&$$.nd, "Statement");
			add_son_node($$.nd, $1.nd);
			add_son_node($$.nd, $2.nd);
		}
	|	WBD Statement
		{
			BackPatch($2.n, $1.LoopStartPlace);
			Gen("j", 0, 0, $1.LoopStartPlace);
			$$.n = $1.Chain;

			make_father(&$$.nd, "Statement");
			add_son_node($$.nd, $1.nd);
			add_son_node($$.nd, $2.nd);
		}
	|	CompState
	    {
			$$.n = $1.n;

			make_father(&$$.nd, "Statement");
			add_son_node($$.nd, $1.nd);
		}
	|	ForLoop Do Statement
		{
			BackPatch($3.n, NXQ);
			Gen("+", $1.place, 1, $1.place);
			Gen("j", 0, 0, $1.Loop);
			$$.n = $1.Chain;

			make_father(&$$.nd, "Statement");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, "Do");
			add_son_node($$.nd, $3.nd);
		}
	|	{
			make_father(&$$.nd, "Statement");
	    }
	;
CompState:	Begin StateList End
		{
			$$.n = $2.n;

			make_father(&$$.nd, "CompState");
			make_node($$.nd, "Begin");
			add_son_node($$.nd, $2.nd);
			make_node($$.nd, "End");
		}
	;
AsignState:	Variable ':''=' Expr
		{
			if ($1.n)
				Gen(":=", $4.place, 0, $1.n);
			else {
				yyerror("variable wrong!\n");
				return 0;
			}

			make_father(&$$.nd, "AsignState");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, ":");
			make_node($$.nd, "=");
			add_son_node($$.nd, $4.nd);
		}
	;
ISE:		IBT Statement Else
		{
			int q = NXQ;
			Gen("j", 0, 0, 0);
			BackPatch($1.n, NXQ);
			$$.n = Merge($2.n, q);

			make_father(&$$.nd, "ISE");
			add_son_node($$.nd, $1.nd);
			add_son_node($$.nd, $2.nd);
			make_node($$.nd, "Else");
		}
	;
IBT:		If BoolExpr Then
		{
			BackPatch($2.TC, NXQ);
			$$.n = $2.FC;

			make_father(&$$.nd, "IBT");
			make_node($$.nd, "If");
			add_son_node($$.nd, $2.nd);
			make_node($$.nd, "Then");
		}

	;
WBD: Wh BoolExpr Do
		{
			BackPatch($2.TC, NXQ);
			$$.Chain = $2.FC;
			$$.LoopStartPlace = $1.n;

			make_father(&$$.nd, "WBD");
			add_son_node($$.nd, $1.nd);
			add_son_node($$.nd, $2.nd);
			make_node($$.nd, "Do");
		}
	;
Wh:		While
        {
			$$.n = NXQ;

			make_father(&$$.nd, "Wh");
			make_node($$.nd, "While");
        }
	;
ForLoop:	For Variable ':' '=' Expr
		{
			char c[5];
			sprintf(c, "%d", $2.n);
			int i = Entry(c);
			Gen("=", $5.place, 0, i);
			$$.place = i;

			make_father(&$$.nd, "ForLoop");
			make_node($$.nd, "For");
			add_son_node($$.nd, $2.nd);
			make_node($$.nd, ":");
			make_node($$.nd, "=");
			add_son_node($$.nd, $5.nd);
		}
	|	ForLoop To Expr
		{
			int p = NXQ;
			$$.Loop = NXQ;
			Gen("j<=", $1.place, $3.place, p+2);
			$$.place = $1.place;
			$$.Chain = NXQ;
			Gen("j", 0, 0, 0);

			make_father(&$$.nd, "ForLoop");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, "To");
			add_son_node($$.nd, $3.nd);
		}
Expr:	Expr'+'Expr
		{
			$$.place = NewTemp();
			Gen("+", $1.place, $3.place, $$.place);

			make_father(&$$.nd, "Expr");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, "+");
			add_son_node($$.nd, $3.nd);
		}
	|	Expr'-'Expr
		{
			$$.place = NewTemp();
			Gen("-", $1.place, $3.place, $$.place);

			make_father(&$$.nd, "Expr");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, "-");
			add_son_node($$.nd, $3.nd);
		}

	|	Expr'*'Expr
		{
			$$.place = NewTemp();
			Gen("*", $1.place, $3.place, $$.place);

			make_father(&$$.nd, "Expr");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, "*");
			add_son_node($$.nd, $3.nd);
		}
	|	Expr'/'Expr
		{
			$$.place = NewTemp();
			Gen("/", $1.place, $3.place, $$.place);

			make_father(&$$.nd, "Expr");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, "/");
			add_son_node($$.nd, $3.nd);
		}
	|	'('Expr')'
		{
			$$.place = $2.place;

			make_father(&$$.nd, "Expr");
			make_node($$.nd, "(");
			add_son_node($$.nd, $2.nd);
			make_node($$.nd, ")");
		}
	|	'-' Expr %prec UMINUS
		{
		}
	|	Variable
		{
			if ($1.n)
				$$.place = $1.n;
			else {
				yyerror("variable wrong!\n");
				return 0;
			}

			make_father(&$$.nd, "Expr");
			add_son_node($$.nd, $1.nd);
		}

	|	Const
		{
			$$.place = $1.place;

			make_father(&$$.nd, "Expr");
			add_son_node($$.nd, $1.nd);
		}
	;

BoolExpr:	Expr RelationOp Expr
		{
			$$.TC = NXQ;
			$$.FC = NXQ + 1;
			Gen($2.s, $1.place, $3.place, 0);
			Gen("j", 0, 0, 0);

			make_father(&$$.nd, "BoolExpr");
			add_son_node($$.nd, $1.nd);
			add_son_node($$.nd, $2.nd);
			add_son_node($$.nd, $3.nd);
		}
	|	BoolExprAnd BoolExpr
	    {
			$$.TC = $2.TC;
			$$.FC = Merge($1.FC, $2.FC);

			make_father(&$$.nd, "BoolExpr");
			add_son_node($$.nd, $1.nd);
			add_son_node($$.nd, $2.nd);
		}
	|	BoolExprOr BoolExpr
	    {
			$$.FC = $2.FC;
			$$.TC = Merge($1.TC, $2.TC);

			make_father(&$$.nd, "BoolExpr");
			add_son_node($$.nd, $1.nd);
			add_son_node($$.nd, $2.nd);
		}	
	|	Not BoolExpr
	    {
			$$.TC = $2.FC;
			$$.FC = $2.TC;

			make_father(&$$.nd, "BoolExpr");
			make_node($$.nd, "Not");
			add_son_node($$.nd, $2.nd);
		}
	|	'(' BoolExpr ')'
	    {
			$$.TC = $2.TC;
			$$.FC = $2.FC;

			make_father(&$$.nd, "BoolExpr");
			make_node($$.nd, "(");
			add_son_node($$.nd, $2.nd);
			make_node($$.nd, ")");
		}
	;
BoolExprAnd:	BoolExpr And
		{
			BackPatch($1.TC, NXQ);
			$$.FC = $1.FC;

			make_father(&$$.nd, "BoolExprAnd");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, "And");
		}
	;
BoolExprOr:		BoolExpr Or
		{
			BackPatch($1.FC, NXQ);
			$$.TC = $1.TC;

			make_father(&$$.nd, "BoolExprOr");
			add_son_node($$.nd, $1.nd);
			make_node($$.nd, "Or");
		}
	;
Variable:	Iden
		{
			$$.n = LookUp(str1);
			Entry(str1);

			make_father(&$$.nd, "Variable");
			make_node($$.nd, str1);
		}
	;
Const:		IntNo
		{
			int t = Entry(str1);
			SymbolList[t].type = INTTYPE;
			$$.place = t;

			make_father(&$$.nd, "Const");
			make_node($$.nd, str1);
		}
	|	RealNo
		{
			int t = Entry(str1);
			SymbolList[t].type = REALTYPE;
			$$.place = t;

			make_father(&$$.nd, "Const");
			make_node($$.nd, str1);
		}
	;
RelationOp:	'<'
		{
			strcpy($$.s, "j<");

			make_father(&$$.nd, "RelationOp");
			make_node($$.nd, "<");
		}
	|	'>'
		{
			strcpy($$.s, "j>");

			make_father(&$$.nd, "RelationOp");
			make_node($$.nd, ">");
		}	
	|	'='
		{
			strcpy($$.s, "j=");

			make_father(&$$.nd, "RelationOp");
			make_node($$.nd, "=");
		}
	|	GE
		{
			strcpy($$.s, "j>=");

			make_father(&$$.nd, "RelationOp");
			make_node($$.nd, ">=");
		}
	|	NE
		{
			strcpy($$.s, "j<>");

			make_father(&$$.nd, "RelationOp");
			make_node($$.nd, "<>");
		}
	|	LE
		{
			strcpy($$.s, "j<=");

			make_father(&$$.nd, "RelationOp");
			make_node($$.nd, "<=");
		}
	;

%%
/*int yylex(void)
{ 
}
*/

int LookUp(char* name) {
	for (int i = 1; i <= SymbolCount; i++)
		if (!strcmp(SymbolList[i].name, name)) {
			return i;
		}
	return 0;
}

int Enter(char* name) {
	SymbolCount++;
	strcpy(SymbolList[SymbolCount].name, name);
	SymbolList[SymbolCount].type = 2;
	return SymbolCount;
}

int Entry(char* name) {
	int i = LookUp(name);
	if (i)
		return i;
	else
		return Enter(name);
}

int Gen(char* op, int arg1, int arg2, int result) {
	strcpy(QuaterList[NXQ].op, op);
	QuaterList[NXQ].arg1 = arg1;
	QuaterList[NXQ].arg2 = arg2;
	QuaterList[NXQ].result = result;
	NXQ++;
	return NXQ - 1;
}

int NewTemp(void) {
	SymbolCount++;
	TempCount++;
	char c[6];
	sprintf(c, "T%d", TempCount);

	strcpy(SymbolList[SymbolCount].name, c);
	SymbolList[SymbolCount].type = -1;
	return SymbolCount;
}

int Merge(int p1, int p2) {
	int p;
	if (!p2) 
		return p1;
	else {
		p = p2;
		while (QuaterList[p].result)
			p = QuaterList[p].result;
		QuaterList[p].result = p1;
		return p2;
	}
}

void BackPatch(int p, int t) {
	int q = p;
	while (q) {
		int q1 = QuaterList[q].result;
		QuaterList[q].result = t;
		q = q1;
	}
	return;
}

void make_node(struct node *father, char *s) {
	struct node *ndd;
	make_father(&ndd, s);
	add_son_node(father, ndd);
}

void make_father(struct node **nd, char *s) {
	new_node(nd);
	init_node(*nd);
	set_node_val_str(*nd, s);
}

void output_ast(struct node *nd, int num) {
	if (nd == NULL)
		return;

	printf("%d", num);

	for (int i = 0; i < num; i++) {
		printf("   ");
	}

	printf("%s\n", nd->val.str);
	output_ast(nd->son, num+1);
	output_ast(nd->next, num);
}

void OutputQ(void)
{
	int i=0;
	
	if(i>=NXQ) {
		printf("no quater exists!\n");
	}
		
	for(i=0;i<NXQ;i++) {
	
		printf("(%3d) ( %5s, ",i,QuaterList[i].op);
		if(QuaterList[i].arg1)
			printf("%6s, ",SymbolList[QuaterList[i].arg1].name);
		else
			printf("      , ");
			
		if(QuaterList[i].arg2)
			printf("%6s, ",SymbolList[QuaterList[i].arg2].name);
		else printf("      , ");
		
		if((QuaterList[i].op[0]=='j')||(QuaterList[i].op[0]=='S')) 
			printf("%6d )\n",QuaterList[i].result);
		else if(QuaterList[i].result)
			printf("%6s )\n",SymbolList[QuaterList[i].result].name);
		else printf("-\t )\n");
	}
	
	return;
}

int main(int argc, char *argv[])
{
	yyin=stdin;
	// init_node(&root);
	
	if(argc>1) {
		if((yyin=fopen(argv[1],"r"))==NULL) {
			printf("Can't open file %s\n",argv[1]);
			return -1;
		}
	}
	
	yyparse();
	
	OutputQ();
	
	OutputIList();
	
	return 0;
}

int yyerror(char *errstr)
{
	printf(" %s\n",errstr);
	return 0;
}

void OutputIList(void)
{
	int i=0;
	
	printf(" No.\t name \t\t   type\n");
	
	if(i>=VarCount) {
		printf("Variable Table is NULL!\n");
	}
	
	for(i=0;i<VarCount;i++) {
		printf("%4d\t%6s\t\t",i,VarList[i].name);
		if(VarList[i].type == REALTYPE) {
			printf(" REAL  \n");
		} else if (VarList[i].type == INTTYPE) {
			printf(" INTEGER\n"); 
		} else {
			printf(" ARRAY\t\t%d\n", VarList[i].addr);
		}
	}

	printf(" No.\t name \t\t   type\n");
	
	i = 0;
	printf("Symbol Table:\n");
	if(SymbolCount == 0) {
		printf("Symbol Table is NULL!\n");
	}
	
	for(i=1;i<=SymbolCount;i++) {
		printf("%4d\t%6s\t\t",i,SymbolList[i].name);
		if(SymbolList[i].type == REALTYPE) {
			printf(" REAL  \n");
		} else if (SymbolList[i].type == INTTYPE) {
			printf(" INTEGER\n"); 
		} else if (SymbolList[i].type == ARRAYTYPE) {
			printf(" ARRAY\t\t%d\n", SymbolList[i].addr);
		} else if (SymbolList[i].type == -1) {
			printf(" Temp\n");
		} else {
			printf(" None Type\n");
		}
	}
	
	return;
}
