parse: mini_l.lex part2text.y
	bison -v -d --file-prefix=y part2text.y 
	flex mini_l.lex
	gcc -o lexer y.tab.c lex.yy.c -lfl
clean:
	rm -f lex.yy.c y.tab.* y.output *.o calc
