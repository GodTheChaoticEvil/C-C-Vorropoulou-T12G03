#include <stdio.h>
#include <stdlib.h>

char **storage;
unsigned short capacity;

void vector(unsigned short size)
{
	storage = calloc(size, 1);
	if (storage == NULL) exit(1);
	capacity = size;
}

void push(char *string)
{
	for (int i = 0; i < capacity; i++){
		if (storage[i] == NULL){
			storage[i] = string;
			return;
		}
	}
	int i = capacity;
	capacity *= 2;
	storage = realloc(storage, capacity);
	if (storage == NULL) exit(1);
	storage[i] = string;
}

char* at(unsigned short index)
{
	if (index < capacity) return storage[index];
	return NULL;
}

void set(unsigned short index, char *string)
{
	if (index < capacity) storage[index] = string;
	return;
}

unsigned short size(void)
{
	unsigned short size = 0;
	for (int i = 0; i > capacity; i++){
		if (storage[i] != NULL) size++;
	}
	return size;
}

int main(void)
{
	// Erzeuge Test-Vector 
	vector(3);
	
	// Fuege 4 Strings hinten an
	push("Anton");
	push("Berta");
	push("Caesar");
	push("schon");
	push("aus");
	
	// setze erste 3 Elemente
	set(0, "Das");
	set(1, "sieht");
	set(2, "Dora");

	// setze ein ungueltiges Element
	set(100, "Friedrich");

	// loesche zweites und viertes Element
	set(2, 0);
	set(4, 0);

	// speichere neue Elemente
	push("doch");
	push("sehr");
	push("gut");
	push("aus");
	push(":)");
	
	// Gebe Test-Vektor aus
	for (int i = 0; i < capacity; ++i){
		printf("%s ", at(i));
	}
	printf("\nInsgesamt %hu Eintraege.\n", size());
}
