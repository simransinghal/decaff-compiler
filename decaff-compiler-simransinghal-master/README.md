#Structure#
Directory Phase1: Phase 1 of project
Directory Phase2: Phase 2 of project
Phase2/parser.y: Bison parser
Phase2/scanner.l: Flex scanner
Phase2/parser.cpp: cpp file to create AST
parser: binary file to be executed

#Run#
Compile: 
$flex scanner.l
$bison -d parser.y
$g++ parser.cpp lex.yy.c parser.tab.c -o parser

Execute: 
$./parser < <input_file_name>
Run compiler on sample programs
1. $./out < ../hanoi.dcf
2. $./out < ../even.dcf
3. $./out < ../linear.dcf
4. $./out < ../prime.dcf
5. $./out < ../vecadd.dcf

*Description*
Features Implemented-
1. Scanner using Flex
2. Parser using Bison
3. AST generation
4. LLVM code generation
