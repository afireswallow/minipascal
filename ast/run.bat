bison.exe -d .\ast_yacc.y
flex.exe .\ast_lex.l
gcc .\lex.yy.c .\ast_yacc.tab.c -o ast.exe
.\ast.exe .\a.txt
