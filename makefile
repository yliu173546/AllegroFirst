CC = g++ 
ALLEGRO = `pkg-config allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5 --cflags --libs`

test: main character
	$(CC) main.o character.o -o test $(ALLEGRO) 
main : main.cpp 
	$(CC) main.cpp -c $(ALLEGRO)
character : character.cpp
	$(CC) character.cpp -c $(ALLEGRO)
