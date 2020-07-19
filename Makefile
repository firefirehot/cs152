parse: mini_l.lex part2text.y
	bison -v -d --file-prefix=parser part2text.y 
	flex mini_l.lex
	g++ -std=c++11 -o parser parser.tab.c lex.yy.c -lfl
clean:
	rm -f lex.yy.c y.tab.* y.output *.o calc
