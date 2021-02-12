No windows 10 (nao testei em outras versoes)
1 - instale o mingw usado pela SFML (https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download)
1.1 como o esse compilador não é instalado no windows, vc pode deixá-lo em qualquer lugar do sistema, no meu caso adicionaei em C:/Program Files (x86)
1.2 adicione o caminho <local de instalação do mingw>\bin\ na sua variável de ambiente PATH 
1.2 Abra um powershell e tente executar o comando g++ -v
  - se o compilador tiver sido instalado corretamente a saída deve mostrar a versão do gcc instalada, .tem que ser 7.3.0 (que é o g++ baixado no link do passo 1).
2 - Baixe os binários da SFML do windows https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit.zip
3 - Baixe o projeto de teste
3.1 configure no makefile o local dos binários e includes da SFML que voce baixou
3.2 - abra um terminal, navegue até o local onde o projeto foi baixado e execute o comando: 
    mingw32-make.exe executavel
3.3 - para rodar o programa você precisa ir no diretório (usando o explorer) e dar dois clicks no executável gerado.
    
  