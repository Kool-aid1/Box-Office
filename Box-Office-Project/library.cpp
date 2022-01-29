#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "library.h"

using namespace std;

bool collect_stats(Movie_stats arr[], Box_Office& b , int n){

  string website;

  ifstream input_file;
  input_file.open("input.dat");
    if(!input_file.is_open()){
    return false;
  } else {
    //cout << "Files opened" << endl;
  }

  getline(input_file, website, '\n');
  
  do {
    for (int i =0; i < 5; i++){
      getline(input_file, arr[i].movie, ',');
      input_file >> arr[i].rating;
      input_file.ignore();
      getline(input_file, arr[i].director);

      for (int j = 0; j < b.size; j++){
        input_file >> arr[i].avg_sale[j];   
      } //end of loop for j
      input_file.ignore(); 
    } //end of loop for i
  } while(!input_file.eof());
  return true;

}  //end of collect_data 

void display_stats(Movie_stats arr[], Box_Office& b, int n){
  for(int i = 0; i < n; i++){
    cout << left << setw(30) << arr[i].movie;
    cout << setw(10) << arr[i].rating;
    cout << setw(20) << arr[i].director;
    
    for (int j = 0; j < b.size; j++){
      b.sales += arr[i].avg_sale[j];
      cout << left << setw(5) << arr[i].avg_sale[j]; 

      if(arr[i].avg_sale[j] > b.highest){
        b.highest = arr[i].avg_sale[j];
        }

      if(arr[i].avg_sale[j] < b.lowest){
        b.lowest = arr[i].avg_sale[j];
        }
    
      } // end of loop for j

      cout << right << setw(6) << b.sales;
      cout << right << setw(6) << b.highest; 
      cout << right << setw(6) << b.lowest;
      cout << endl;

      //To reset the current stats to show next movies stats
      b.sales = 0;
      b.highest = 0;
      b.lowest = 9999;

  } //end of loop for i
} // end of display_stats


void sort_highest_rating(Movie_stats arr[], int n){
  for (int j = 1; j < n; j++){
    for(int i = j; i > 0 && arr[i-1].rating < arr[i].rating; i--){
      swap(arr[i-1], arr[i]);

    } // end of loop for i
  } // end of loop for j
}

void sort_lowest_rating(Movie_stats arr[], int n){
  for (int j = 1; j < n; j++){
    for(int i = j; i > 0 && arr[i-1].rating > arr[i].rating; i--){
      swap(arr[i-1], arr[i]);

    } // end of loop for i
  } // end of loop for j
}

void sort_title_asc(Movie_stats arr[], int n){
  for (int j = 1; j < n; j++){
    for(int i = j; i > 0 && arr[i-1].movie > arr[i].movie; i--){
      swap(arr[i-1], arr[i]);

    } // end of loop for i
  } // end of loop for j
}

void sort_title_dsc(Movie_stats arr[], int n){
  for (int j = 1; j < n; j++){
    for(int i = j; i > 0 && arr[i-1].movie < arr[i].movie; i--){
      swap(arr[i-1], arr[i]);

    } // end of loop for i
  } // end of loop for j
}

void sort_director_asc(Movie_stats arr[], int n){
  for (int j = 1; j < n; j++){
    for(int i = j; i > 0 && arr[i-1].director > arr[i].director; i--){
      swap(arr[i-1], arr[i]);

    } // end of loop for i
  } // end of loop for j
}

void sort_director_dsc(Movie_stats arr[], int n){
  for (int j = 1; j < n; j++){
    for(int i = j; i > 0 && arr[i-1].director < arr[i].director; i--){
      swap(arr[i-1], arr[i]);
      
    } // end of loop for i
  } // end of loop for j
}

void delete_movie(Movie_stats arr[], Movie_stats m, Box_Office b,int n){
  
  int pos;

  cout << "Which movie would you like to delete? " << endl;
  cout << "Please input a number for your choice" << endl;
  cout << left << setw(30) << "1. Eternals" << endl;
  cout << left << setw(30) << "2. Dune" << endl;
  cout << left << setw(30) << "3. No Time to Die" << endl;
  cout << left << setw(30) << "4. Venom: Let There Be Carnage" << endl;
  cout << left << setw(30) << "5. The French Dispatch" << endl;

  cin >> m.movie_choice;
  cout << endl;

  switch(m.movie_choice){
    case 1:
      m.movie = "Eternals";
    break;
    case 2:
      m.movie = "Dune";
    break;
    case 3:
      m.movie = "No Time to Die";
    break;
    case 4:
      m.movie = "Venom: Let There Be Carnage";
    break;
    case 5:
      m.movie = "The French Dispatch";
    break;
  }
  
  for (int i = 0; i < n && !m.found; i++){
    if(arr[i].movie == m.movie){
      pos = i;
      m.found = true;

      for (int i = pos; i < n-1; i++){
        arr[i].movie = arr[i+1].movie;
        arr[i].director = arr[i+1].director;
        arr[i].rating = arr[i+1].rating;

      } // end of for loop statement
      n--;
    } // end of if loop i
  }// end of for loop statement
}