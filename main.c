#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_headers.h"
#include "lib_headers.h"

int main(){
  printf("LINKED LIST TESTS\n");
  printf("____________________________________________________________\n");
  song_node * nullptr = NULL;
  song_node * front = (song_node *)calloc(1, sizeof(song_node *));
  strcpy(front->name, "Ikai no Shin'en");
  strcpy(front->artist, "Nobuo Uematsu");
  front->next = nullptr;
  printf("Testing list_len:\n");
  printf("List starting with null pointer: \t%d\n", list_len(nullptr));
  
  printf("____________________________________________________________\n");





  song_node * table[27];
  int index = 0;
  for(; index < 27; index++){
    table[index] = NULL;
  }

  
  
  //remember to free everything
  return 0;
}
