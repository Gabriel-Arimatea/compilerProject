clear
bison -v -d -o analsint.c analisadorsintatico.y
flex -v -t analisadorlexico.l > analex.c
gcc analsint.c analex.c -o compsintlex
