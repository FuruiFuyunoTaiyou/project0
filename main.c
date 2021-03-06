#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list_headers.h"
#include "lib_headers.h"

int main(){
  srand(time(NULL));
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
  //---------------just randomizing the first time???---------------------
  //(b/c srand should have been called ONCE, at the beginning of the program (main)
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
  front = free_list(front);
  print_list(front);
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
  printf("------------------------------------------------------------\n");
  printf("Testing find_song:\n");
  printf("looking for: eminem : when i'm gone\n");
  loc = find_song(table, "when i'm gone", "eminem");
  if(loc){
    printf("\tsong found: ");
    print_node(loc);
    printf("\n");
  }else{
    printf("\tsong was not found\n");
  }
  printf("looking for: 123 : random song\n");
  loc = find_song(table, "random song", "123");
  if(loc){
    printf("\tsong found: ");
    print_node(loc);
    printf("\n");
  }else{
    printf("\tsong was not found\n");
  }
  printf("looking for: honey works : puraido kakumei\n");
  loc = find_song(table, "puraido kakumei", "honey works");
  if(loc){
    printf("\tsong found: ");
    print_node(loc);
    printf("\n");
  }else{
    printf("\tsong was not found\n");
  }
  printf("------------------------------------------------------------\n");
  printf("Testing find_artist:\n");
  printf("adding: hyoo woo : where the wind sleeps\n");
  add_song(table, "where the wind sleeps", "hyoo woo"); 
  printf("adding: honey works : puraido kakumei\n");
  add_song(table, "puraido kakumei", "honey works"); 
  printf("looking for: hyoo woo\n");
  loc = find_artist(table, "hyoo woo");
  if(loc){
    printf("\tartist found: ");
    print_node(loc);
    printf("\n");
  }else{
    printf("\tartist was not found\n");
  }
  printf("looking for: pentakill\n");
  loc = find_artist(table, "pentakill");
  if(loc){
    printf("\tartist found: ");
    print_node(loc);
    printf("\n");
  }else{
    printf("\tartist was not found\n");
  }
  printf("looking for: ling\n");
  loc = find_artist(table, "ling");
  if(loc){
    printf("\tartist found: ");
    print_node(loc);
    printf("\n");
  }else{
    printf("\tartist was not found\n");
  }
  printf("------------------------------------------------------------\n");
  printf("Testing print_artist:\n");
  printf("looking for: pentakill\n");
  print_artist(table, "pentakill");
  printf("looking for: eminem\n");
  print_artist(table, "eminem");
  printf("looking for: ling\n");
  print_artist(table, "ling");
  /*printf("------------------------------------------------------------\n");
  printf("Testing shuffle:\n");
  printf("adding: enya : caribbean blue\n");
  add_song(table, "caribbean blue", "enya"); 
  printf("adding: mecano : hijo de la luna\n");
  add_song(table, "hijo de la luna", "mecano"); 
  printf("adding: florence and the machine : cosmic love\n");
  add_song(table, "cosmic love", "florence and the machine"); 
  printf("adding: hikasa youko : bungaku shoujo\n");
  add_song(table, "bungaku shoujo", "hikasa youko"); 
  printf("adding: chihiro onitsuka : memai\n");
  add_song(table, "memai", "chihiro onitsuka"); 
  printf("adding: nobuo uematsu : doga & une\n");
  add_song(table, "doga & une", "nobuo uematsu"); 
  printf("adding: eminem : stan\n");
  add_song(table, "stan", "eminem"); 
  printf("adding: sara bareilles : king of anything\n");
  add_song(table, "king of anything", "sara bareilles"); 
  printf("adding: nobuo uematsu : ikai no shin'en\n");
  add_song(table, "ikai no shin'en", "nobuo uematsu"); 
  printf("shuffling: \n");
  shuffle(table, 5);
  //this time, shuffling is resulting in seg faults
  //printf("shuffling: \n");
  //shuffle(table, 5);
  //printf("shuffling: \n");
  //shuffle(table, 10);*/
  printf("------------------------------------------------------------\n");
  printf("Testing delete_song:\n");
  printf("deleting: 123 : random song \n");
  delete_song(table, "random song", "123");
  print_letter(table, "{");
  printf("deleting: eminem : when i'm gone \n");
  delete_song(table, "when i'm gone", "eminem");
  print_letter(table, "e");
  printf("deleting: artist that didn't exist : song that didn't exist \n");
  delete_song(table, "song that didn't exist", "artist that didn't exist");
  print_letter(table, "a");
  printf("------------------------------------------------------------\n");
  printf("Testing delete_all:\n");
  printf("deleting all: \n");
  delete_all(table);
  printf("library: \n");
  print_library(table);
  
  return 0;
}
