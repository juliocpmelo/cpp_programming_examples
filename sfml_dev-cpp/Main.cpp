
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
//#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <cstdlib>


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
//using namespace std;
int main()
{
  sf::Music music;
  
  std::cout<<"playing file"<<std::endl;
  if (!music.openFromFile("resources/file_example_OOG_2MG.ogg")){
    std::cout<<"open from file error"<<std::endl;
    return -1; // error
  }
  std::cout<<"playing file"<<std::endl;
  music.play();
  Sleep(10000);
  return EXIT_SUCCESS;
}

