#esse diretório deve ser o lugar que contém a pasta build que foi criada na compilação

main.o: %.o : %.cpp
	g++ -c $< 

executavel: main.o
	g++ -o executavel.exe main.o -lsfml-window -lsfml-audio -lsfml-system -lsfml-graphics

clean:
	rm *.exe *.o
