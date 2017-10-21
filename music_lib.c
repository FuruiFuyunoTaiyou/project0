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
