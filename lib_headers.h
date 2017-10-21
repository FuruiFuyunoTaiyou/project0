int find_index(char artist_name[]);

void print_letter(song_node * table[], char c[]);

void print_library(song_node * table[]);

void add_song(song_node * table[], char song_name[], char artist_name[]);

song_node * find_song(song_node * table[], char song_name[], char artist_name[]);

song_node * find_artist(song_node * table[], char artist_name[]);



void shuffle(song_node * table[], int amt);

void delete_song(song_node * table[], char song_name[], char artist_name[]);

void delete_all(song_node * table[]);
