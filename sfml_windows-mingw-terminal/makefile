#esse diretório deve ser o lugar que contém a pasta build que foi criada na compilação
SFML_PATH=C:\Users\Julio\Downloads\SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit\SFML-2.5.1\\
SFML_DLLS=sfml-graphics-d-2 sfml-window-d-2 sfml-system-d-2 sfml-audio-d-2
SFML_EXT_DLLS=openal32

$(SFML_DLLS:=.dll) : % : $(SFML_PATH)\bin\\%
	copy $< .

$(SFML_EXT_DLLS:=.dll) : % : $(SFML_PATH)\bin\\%
	copy $< .
	
main.o: %.o : %.cpp
	g++ -c $< -I$(SFML_PATH)\include

executavel: main.o $(SFML_EXT_DLLS:=.dll) $(SFML_DLLS:=.dll)
	g++ -o executavel main.o -I$(SFML_PATH)\include -L$(SFML_PATH)\bin -lsfml-window-d-2 -lsfml-audio-d-2 -lsfml-system-d-2 -lsfml-graphics-d-2

clean:
	del *.exe *.dll *.o
