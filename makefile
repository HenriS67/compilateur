RECEPTCOMP.exe: main.o lexer.o symbole.o etat.o automate.o
	g++ -o RECEPTCOMP.exe main.o lexer.o symbole.o etat.o automate.o


main.o: main.cpp
	g++ -c main.cpp

lexer.o: lexer.cpp lexer.h symbole.h 
	g++ -c lexer.cpp

symbole.o: symbole.cpp symbole.h
	g++ -c symbole.cpp

automate.o: automate.cpp automate.h symbole.h lexer.h
	g++ -c automate.cpp

etat.o: etat.cpp etat.h symbole.h automate.h
	g++ -c etat.cpp

clean:
	rm -f *.o *.EXE
