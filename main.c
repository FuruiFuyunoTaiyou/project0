#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list_headers.h"
#include "lib_headers.h"

int main(){
  printf("LINKED LIST TESTS\n");
  printf("------------------------------------------------------------\n");
  printf("Testing list_len, print_node, and print_list:\n");
  song_node * nullptr = NULL;
  song_node * front = (song_node *)calloc(1, sizeof(song_node *));
  strcpy(front->name, "Ikai no Shin'en");
  strcpy(front->artist, "Nobuo Uematsu");
  front->next = nullptr;
  printf("List starting with null pointer: \t%d\n", list_len(nullptr));
  printf("front: ");
  print_node(nullptr);
  printf("\nlist: ");
  print_list(nullptr);
  printf("List with one node: \t\t\t%d\n", list_len(front));
  printf("front: ");
  print_node(front);
  printf("\nlist: ");
  print_list(front);
  front = insert_front(front, "Lightbringer", "Pentakill");
  printf("List with two nodes: \t\t\t%d\n", list_len(front));
  printf("front: ");
  print_node(front);
  printf("\nlist: ");
  print_list(front);
  front = insert_front(front, "Deathfire Grasp", "Pentakill");
  printf("List with three nodes: \t\t\t%d\n", list_len(front));
  printf("front: ");
  print_node(front);
  printf("\nlist: ");
  print_list(front);
  printf("------------------------------------------------------------\n");
  printf("Testing insert_ordered:\n");
  song_node * front1 = insert_ordered(nullptr, "ikai no shin'en", "nobuo uematsu");
  print_list(front1);
  front1 = insert_ordered(front1, "deathfire grasp", "pentakill");
  print_list(front1);
  front1 = insert_ordered(front1, "hex core", "pentakill");
  print_list(front1);
  front1 = insert_ordered(front1, "lightbringer", "pentakill");
  print_list(front1);

  song_node * table[27];
  int index = 0;
  for(; index < 27; index++){
    table[index] = NULL;
  }

  
  
  //remember to free everything
  return 0;
}
