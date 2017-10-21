typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node * next;
} song_node;

int list_len(song_node * current);

void print_node(song_node * node);

void print_list(song_node * current);

song_node * insert_front(song_node * front, char song_name[], char song_artist[]);
