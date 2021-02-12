Testado no windows 10 (nao testei em outras versoes)

1.Instale o mingw usado pela [SFML](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download)
		1. Como o esse compilador não é instalado no windows, vc pode deixá-lo em qualquer lugar do sistema, no meu caso adicionei em ```C:/Program Files \(x86\)```
		2. Adicione o caminho ```<local de instalação do mingw>\bin\``` na sua variável de ambiente __PATH__
		3. Abra um powershell e tente executar o comando: ```g++ -v```
		4. Se o compilador tiver sido instalado corretamente a saída deve mostrar a versão do gcc instalada, tem que ser 7.3.0 (que é o g++ baixado no link do passo 1)
2. Baixe os binários da SFML do [windows](https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit.zip)
		1. Descompacte os binários em algum diretório (de preferencia em algum que __não precise__ de permissão de administrador)
3. Configure no makefile o local dos binários e includes da SFML que voce baixou
		1. abra um terminal, navegue até o local onde o projeto foi baixado e execute o comando: ```mingw32-make.exe executavel```
		2. para rodar o programa você precisa ir no diretório (usando o explorer) e dar dois clicks no executável gerado.
    
  
