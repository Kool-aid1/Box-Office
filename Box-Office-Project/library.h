#include <string>
using namespace std;

const int CAPACITY = 10;

struct Movie_stats{
   
  string director;
  string movie;
  double rating;
  int movie_choice = 0;
  int avg_sale[7]; 
  bool found = false;

};

struct Box_Office{

  int size = 7;
  int sales = 0;
  int highest = 0;
  int lowest = 9999;

};

bool collect_stats(Movie_stats arr[], Box_Office& b, int n);

void display_stats(Movie_stats arr[], Box_Office& b, int n);

void sort_highest_rating(Movie_stats arr[], int n);
void sort_lowest_rating(Movie_stats arr[], int n);

void sort_title_asc(Movie_stats arr[], int n);
void sort_title_dsc(Movie_stats arr[], int n);

void sort_director_asc(Movie_stats arr[], int n);
void sort_director_dsc(Movie_stats arr[], int n);

void delete_movie(Movie_stats arr[], Movie_stats m , Box_Office b, int n);