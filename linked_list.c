#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_headers.h"

int list_len(song_node * current){
  int i = 0;
  while(current){
    i++;
    current = current->next;
  }
  return i;
}

void print_node(song_node * node){
  printf("%s : %s", node->artist, node->name);
}

void print_list(song_node * current){
  if(list_len(current) == 0){
    printf("[\n]\n");
  }else{
    printf("[");
    while(current){
      printf("\t");
      print_node(current);
      printf("\n");
      current = current->next;
    }
    printf("]");
  }
}

song_node * insert_front(song_node * front, char song_name[], char song_artist[]){
  song_node * new_front = (song_node *)calloc(1, sizeof(song_node));
  strcpy(new_front->name, song_name);
  strcpy(new_front->artist, song_artist);
  new_front->next = front;
  return new_front;
}

