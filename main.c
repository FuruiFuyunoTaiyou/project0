#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list_headers.h"
#include "lib_headers.h"

int main(){
  printf("LINKED LIST TESTS\n");
  printf("============================================================\n");
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
  front1 = insert_ordered(front1, "puraido kakumei", "honey works");
  print_list(front1);
  printf("------------------------------------------------------------\n");
  printf("Testing find_node:\n");
  printf("looking for: honey works : puraido kakumei\n");
  song_node * loc = find_node(front1, "puraido kakumei", "honey works");
  if(loc){
    printf("\tsong found: ");
    print_node(loc);
    printf("\n");
  }else{
    printf("\tsong was not found\n");
  }
  printf("looking for: pentakill : hex core\n");
  loc = find_node(front1, "hex core", "pentakill");
  if(loc){
    printf("\tsong found: ");
    print_node(loc);
    printf("\n");
  }else{
    printf("\tsong was not found\n");
  }
  printf("looking for: eminem : when i'm gone\n");
  loc = find_node(front1, "when i'm gone", "eminem");
  if(loc){
    printf("\tsong found: ");
    print_node(loc);
    printf("\n");
  }else{
    printf("\tsong was not found\n");
  }
  printf("------------------------------------------------------------\n");
  printf("Testing first_song:\n");
  printf("looking for: nobuo uematsu\n");
  loc = first_song(front1, "nobuo uematsu");
  if(loc){
    printf("\tsong found: ");
    print_node(loc);
    printf("\n");
  }else{
    printf("\tsong was not found\n");
  }
  printf("looking for: pentakill\n");
  loc = first_song(front1, "pentakill");
  if(loc){
    printf("\tsong found: ");
    print_node(loc);
    printf("\n");
  }else{
    printf("\tsong was not found\n");
  }
  printf("looking for: eminem\n");
  loc = first_song(front1, "eminem");
  if(loc){
    printf("\tsong found: ");
    print_node(loc);
    printf("\n");
  }else{
    printf("\tsong was not found\n");
  }
  printf("------------------------------------------------------------\n");
  printf("Testing rand_node:\n");
  int i0 = 0;
  for(; i0 < 10; i0++){
    print_node(rand_node(front1));
    //strange...in gdb when running, will print the same thing 10x
    //when setting a breakpoint at 111, will print different things
    printf("\n");
  }
  //------------just randomizing the first time???------------
  printf("------------------------------------------------------------\n");
  printf("Testing rm_node:\n");
  printf("removing: honey works : puraido kakumei\n");
  front1 = rm_node(front1, "puraido kakumei", "honey works");
  print_list(front1);
  printf("removing: pentakill : hex core\n");
  front1 = rm_node(front1, "hex core", "pentakill");
  print_list(front1);
  printf("removing: eminem : when i'm gone\n");
  front1 = rm_node(front1, "when i'm gone", "eminem");
  print_list(front1);
  printf("------------------------------------------------------------\n");
  printf("Testing free_list:\n");
  printf("first list freed: ");
  print_list(free_list(front));
  printf("second list freed: ");
  print_list(free_list(front1));

  printf("\nMUSIC LIBRARY TESTS\n");
  printf("============================================================\n");
  printf("Testing print_letter, print_library, and add_song:\n");
  song_node * table[27];
  int index = 0;
  for(; index < 27; index++){
    table[index] = NULL;
  }
  printf("library: \n");
  print_library(table);
  printf("adding: eminem: berserk\n");
  add_song(table, "berserk", "eminem");
  printf("adding: eminem: when i'm gone\n");
  add_song(table, "when i'm gone", "eminem");
  printf("adding: pentakill: orb of winter\n");
  add_song(table, "orb of winter", "pentakill");
  printf("adding: 123: random song\n");
  add_song(table, "random song", "123"); 
  print_letter(table, "e");
  print_letter(table, "[");
  printf("library: \n");
  print_library(table);

  
  
  //remember to free everything

  return 0;
}
