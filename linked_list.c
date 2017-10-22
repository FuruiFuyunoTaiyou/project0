#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
  if(node){
    printf("%s : %s", node->artist, node->name);
  }
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
    printf("]\n");
  }
}

song_node * insert_front(song_node * front, char song_name[], char song_artist[]){
  song_node * new_front = (song_node *)calloc(1, sizeof(song_node *));
  strcpy(new_front->name, song_name);
  strcpy(new_front->artist, song_artist);
  new_front->next = front;
  return new_front;
}

int compare_artist(song_node * song_node1, song_node * song_node2){
  return strcmp(song_node1->artist, song_node2->artist);
}

int compare_name(song_node * song_node1, song_node * song_node2){
  return strcmp(song_node1->name, song_node2->name);
}

song_node * find_preceding(song_node * front, song_node * new_node){
  if(front == NULL || compare_artist(new_node, front) < 0){
    return NULL;
  }else{
    song_node * preceding = front;
    while(preceding->next){
      if(compare_artist(new_node, preceding->next) < 0){
	return preceding;
      }else if(compare_artist(new_node, preceding->next) == 0){
	if(compare_name(new_node, preceding->next) < 0){
	  return preceding;
	}
      }
      preceding = preceding->next;
    }
    return preceding;
  }
}

song_node * insert_node_front(song_node * front, song_node * new_node){
  new_node->next = front;
  return new_node;
}

song_node * insert_node_mid_end(song_node * preceding, song_node * new_node){
  new_node->next = preceding->next;
  preceding->next = new_node;
  return preceding; //this info is not that helpful
}

song_node * insert_ordered(song_node * front, char song_name[], char song_artist[]){
  song_node * new_node = (song_node *)calloc(1, sizeof(song_node *));
  strcpy(new_node->name, song_name);
  strcpy(new_node->artist, song_artist);
  song_node * preceding = find_preceding(front, new_node);
  if(preceding){
    insert_node_mid_end(preceding, new_node);
  }else{
    front = insert_node_front(front, new_node);
  }
  return front;
}

song_node * find_node(song_node * current, char song_name[], char song_artist[]){
  while(current){
    if(strcmp(current->name, song_name) + strcmp(current->artist, song_artist) == 0){
      return current;
    }
    current = current->next;
  }
  return NULL;
}

song_node * first_song(song_node * current, char song_artist[]){
  while(current){
    if(strcmp(current->artist, song_artist) == 0){
      return current;
    }
    current = current->next;
  }
  return NULL;
}

song_node * rand_node(song_node * front){
  srand(time(NULL));
  int rand_index = rand() % list_len(front);
  while(rand_index > 0){
    rand_index--;
    front = front->next;
  }
  return front;
}

song_node * find_preceding_existing(song_node * current, song_node * node){
  if(current == node){
    return NULL;
  }else{
    while(current->next){
      if(current->next == node){
	return current;
      }
      current = current->next;
    }
    return NULL;
  }
}

song_node * rm_node(song_node * front, char song_name[], char song_artist[]){
  song_node * node = find_node(front, song_name, song_artist);
  if(node){
    song_node * preceding = find_preceding_existing(front, node);
    if(preceding){
      preceding->next = node->next;
    }else{
      front = node->next;
    }
    free(node);
  }
  return front;
}

song_node * free_list(song_node * current){
  if(current){
    song_node * next = current->next;
    while(next){
      free(current);
      current = next;
      next = current->next;
    }
    free(current);
    return next;
  }else{
    return current;
  }
}
