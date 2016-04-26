#include <iostream>
#include "HashTable.h"
#include "stdlib.h"

using namespace std;

int DEFAULT_TABLESIZE = 10;
int menu();

int main()
{
  int C, year;
  bool quit = false;
  HashTable h = HashTable(DEFAULT_TABLESIZE);
  string title;
  //h.initToNull();
  while (!quit)
  {
    C = 0;
    try{
      C = menu();
    }
    catch(const char* msg){
      cerr << msg << endl;
    }
    if (C == 1)
    {
      cout << "Enter title:" << endl;
      cin.ignore();
      getline(cin, title);
      uint32_t res[5];
      //h.insertScrabble(title); //Not thoroughly tested, but it seems to work..
      h.SHA1(title,res);
      cout << res[0] << res[1] << res[2] << res[3] << res[4] << endl;
      cout << "Number of collisions: " << h.getCollisions() << endl;
    }
    else if (C == 2)
    {
      cout << "Enter title:" << endl;
      cin.ignore();
      getline(cin, title);
      h.deleteMul(title);
    }
    else if (C == 3)
    {
      cout << "Enter title:" << endl;
      cin.ignore();
      getline(cin, title);
      h.find(title);
    }
    else if (C == 4)
    {
      h.printTableContents();
    }
    else if (C == 5){
      string newsize;
      cout << "This will delete everything in the array" << endl;/*Might want to add option to bail on changing tableSize*/
      cout << "Please enter a new table size:" << endl;
      cin.ignore();
      getline(cin, newsize);
      /*I changed this next comand from stoi becuase that doesn't work on my computer.
      Make sure the string is a valid integer.  Add end pointer (instead of NULL) to make sure that the whole string was used in conversion.
      To force to be base 10 make the last argument 10*/
      h.setTableSize(strtol(newsize.c_str(),NULL,0));
    }
    else if (C == 6)
    {
      quit = true;
      cout << "Goodbye!" << endl;
    }
  }
  return 0;
}
int menu()
{
  int choice;
  cout << "======Main Menu======" << endl;
  cout << "1. Insert movie" << endl;
  cout << "2. Delete movie" << endl;
  cout << "3. Find movie" << endl;
  cout << "4. Print table contents" << endl;
  cout << "5. Change table size" << endl;
  cout << "6. Quit" << endl;
  //cin >> choice;
  if(cin >> choice && choice <= 6 && choice > 0){
  return choice;
}
else{
  cout << "Not a valid input.  Please input the number next to the menu item you wish to select" << endl;
  cin.clear();
  while (cin.get() != '\n') ;
}

  //return choice;
}
