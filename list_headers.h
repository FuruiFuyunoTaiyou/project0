typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node * next;
} song_node;

int list_len(song_node * current);

void print_node(song_node * node);

void print_list(song_node * current);

song_node * insert_front(song_node * front, char song_name[], char song_artist[]);

int compare_artist(song_node * song_node1, song_node * song_node2);

int compare_name(song_node * song_node1, song_node * song_node2);

song_node * find_preceding(song_node * front, song_node * new_node);

song_node * insert_node_front(song_node * front, song_node * new_node);

song_node * insert_node_mid_end(song_node * preceding, song_node * new_node);

song_node * insert_ordered(song_node * front, char song_name[], char song_artist[]);

song_node * find_node(song_node * current, char song_name[], char song_artist[]);

song_node * first_song(song_node * current, char song_artist[]);

song_node * rand_node(song_node * front);

song_node * find_preceding_existing(song_node * current, song_node * node);

song_node * rm_node(song_node * front, char song_name[], char song_artist[]);

song_node * free_list(song_node * current);

