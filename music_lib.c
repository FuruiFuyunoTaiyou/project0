#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list_headers.h"
#include "lib_headers.h"

int find_index(char artist_name[]){
  char c = 97;
  int i = 0;
  while(i < 26){
    if(artist_name[0] == c + i){
      return i;
    }
    i++;
  }
  return i;
}

void print_letter(song_node * table[], char c[]){
  if(c[0] < 97 || c[0] > 122){
    printf("misc: ");
  }else{
    printf("%c: ", c[0]); 
  }
  print_list(table[find_index(c)]); 
  
}

void print_library(song_node * table[]){
  char c[1] = "a";
  for(; c[0] < 124; c[0]++){ //122 is z, but let's include misc also
    print_letter(table, c);
  }
}

void add_song(song_node * table[], char song_name[], char artist_name[]){
  int correct_index = find_index(artist_name);
  song_node * front = table[correct_index];
  table[correct_index] = insert_ordered(front, song_name, artist_name);
}

song_node * find_song(song_node * table[], char song_name[], char artist_name[]){
  int correct_index = find_index(artist_name);
  song_node * front = table[correct_index];
  return find_node(front, song_name, artist_name);
}

song_node * find_artist(song_node * table[], char artist_name[]){
  int correct_index = find_index(artist_name);
  song_node * front = table[correct_index];
  return first_song(front, artist_name);
}

void print_artist(song_node * table[], char artist_name[]){
  printf("%s: [\n", artist_name);
  song_node * first = find_artist(table, artist_name);
  while(first){
    printf("\t");
    print_node(first);
    printf("\n");
    first = first_song(first->next, artist_name);
  }
  printf("] \n");
}
//untested
void shuffle(song_node * table[], int amt){
  srand(time(NULL));
  int rand_index;
  song_node * node;
  for(; amt > 0; amt--){
    rand_index = rand() % 27;
    node = rand_node(table[rand_index]);
    print_node(node);
    printf("\n");
  }
}

void delete_song(song_node * table[], char song_name[], char artist_name[]){
  int correct_index = find_index(artist_name);
  song_node * front = table[correct_index];
  table[correct_index] = rm_node(front, song_name, artist_name);
}
//untested 
void delete_all(song_node * table[]){
  int i = 0;
  for(; i < 27; i++){
    table[i] = free_list(table[i]);
  }
}
