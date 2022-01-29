#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "library.h" 
using namespace std; 

//DATES starts Sun Nov 7 - Sat Nov 13

int main() {
  
  Movie_stats movie_stats;
  Box_Office box_office;
  Movie_stats arr[CAPACITY];
  int n = 5;

  char choice;
  int sort_choice = 0;
  bool program = true;

  cout << left << setw(30) << "Movie title"; 
  cout << setw(10) << "Rating";
  cout << setw(20) << "Director";
  cout << right << setw(30) << "Box Office Sun Nov 7 - Sat Nov 13";
  cout << right << setw(8) << "Total";
  cout << right << setw(6) << "High"; 
  cout << right << setw(6) << "Low" << endl;
  cout << setfill('=') << setw(115) << '='<< endl;
  cout << setfill(' ');

  collect_stats(arr, box_office, n);
  display_stats(arr, box_office, n);
  cout << endl;

  do{
    cout << "Would you like to sort or delete? (s/d)"<<endl;
    cout << "To close application, enter 'n'" << endl;
    cin >> choice;
    cout << endl;

    if(choice == 's' || choice == 'S'){
      cout << "How woud you like to sort the information?" << endl;
      cout << left << setw(30) << "1. By highest rating";
      cout << left << setw(30) << "2. By lowest rating" << endl;
      cout << left << setw(30) << "3. By titles ascending";
      cout << left << setw(30) << "4. By titles descending" << endl;
      cout << left << setw(30) << "5. By director ascending";
      cout << left << setw(30) << "6. By director descending" << endl;

      //get user input for "sort_choice" variable
      cin >> sort_choice;
      cout << endl;

      switch(sort_choice){
        case 1:
          sort_highest_rating(arr, n);
          display_stats(arr, box_office, n);
          cout << endl;
          break;
        case 2:
          sort_lowest_rating(arr, n);
          display_stats(arr, box_office, n);
          cout << endl;
          break;
        case 3:
          sort_title_asc(arr, n);
          display_stats(arr, box_office, n);
          cout << endl;
          break;
        case 4:
          sort_title_dsc(arr, n);
          display_stats(arr, box_office, n);
          cout << endl;
          break;
        case 5:
          sort_director_asc(arr, n);
          display_stats(arr, box_office, n);
          cout << endl;
          break;
        case 6:
          sort_director_dsc(arr, n);
          display_stats(arr, box_office, n);
          cout << endl;
          break;
      } // end of switch case

    } // end of if statement for choice of s

    //Delete option in main
    if(choice == 'd' || choice == 'D'){
      delete_movie(arr, movie_stats,box_office, n);
      n--;
      display_stats(arr, box_office, n);
      cout << endl;
    } // end of if statement for choice d
  
    if (choice == 'n' || choice == 'N'){
      program = false;
    } // end of if statment for choice n

  } while(program == true);

} 