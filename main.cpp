#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <stdio.h>
#include <ncurses.h>




using namespace std;

  vector<char> star_storage;
  int star_counter=0;
  int  print_star()
  {
    cout.setf(std::ios::unitbuf); //disable buffering , necessary for output in one line

    do {


      this_thread::get_id();
       star_storage.push_back('*');    //push stars into vector
    cout<<"*";
    star_counter++;
    this_thread::sleep_for(chrono::milliseconds(2000)); //thread falls asleap for 2 seconds


      }while(star_counter < 20);
    return  star_storage.size();
  };


void remove_star()
{

char ch ;
  while(star_storage.size()!= 20) {
 ch = getchar();   //get symbol from keyboard
 if(ch==' '){
     star_storage.pop_back(); // remove star from vector
     star_counter--;
     cout<<"\b"<<" ";   //overwrite a star with empty space
      }
 else if(star_storage.size()<=0)
        {
      cout<<"Wait for at least 1 star"<<endl;
        }

    }

}

int main()
{
  initscr(); //initialization of ncurses library
   noecho(); //disable the output of symbols from keybord
thread star(print_star);
thread nostar(remove_star);
star.join();
nostar.detach();
endwin();  //restore terminal after Curses
return 0;
}
