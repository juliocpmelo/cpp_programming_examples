#include <iostream>
#include <ncurses/ncurses.h>
#include <vector>
#include <thread>  
#include <chrono> 

#define WIDTH 30
#define HEIGHT 10

using namespace std;


void print_choices(int highlight, vector<string> &choices){
  int x, y, i;

  x = 2;
  y = 2;
  for(i = 0; i < choices.size(); ++i){
    if(highlight == i + 1){ /* Highlight actual choice */
      mvprintw(y, x, "> %s", choices[i].c_str());
    }else{
      mvprintw(y, x, "%s", choices[i].c_str());
    }
    ++y;
  }
}

int main(){
    int highlight = 1;
    int choice = 0;


    
    std::vector<std::string> choices = {"One", "Two", "Three", "Four", "Five"};
    int n_choices = choices.size();

    initscr();
    keypad(stdscr, TRUE); //turn keypad on UP/DOWN/LEFT/RIGHT 
    clear();
    noecho();
    cbreak();       /* Buffer de linha desativado. passa tudo */
    mvprintw(0, 0, "Press any key to start (except ESC)");
    refresh();
    while( true ){
        int c = getch();
        clear(); //aways clear before printing
        mvprintw(0, 0, "Use up/down keys to change choice, ESC to exit or any other key to see the value");
        if(c == KEY_UP || c == KEY_DOWN){
            switch(c){
                case KEY_UP:
                    if(highlight == 1){
                        highlight = n_choices;
                    }else{
                        --highlight;
                    }
                    break;
                case KEY_DOWN:
                    if(highlight == n_choices)
                        highlight = 1;
                    else
                        ++highlight;
                    break;
                default:
                    break;
            }
        }
        print_choices(highlight, choices);

        if(std::isalpha(c) || c == ' '){
            mvprintw(HEIGHT-1, 0, "Typed char(int value): %3d typed char: '%c'", c, c);
        }
        else if(c == 27){ //esc doesn't have a constant in ncurses :<
            mvprintw(HEIGHT-1, 0, "bye!");
            refresh();
            break;
        }
        else{ //just help info
            mvprintw(HEIGHT-1, 0, "Digite alguma coisa ou ESC pra sair");
        }
        refresh();
    }

    std::this_thread::sleep_for (chrono::seconds(1)); //so we can see the final message

    endwin();
    return 0;
}

