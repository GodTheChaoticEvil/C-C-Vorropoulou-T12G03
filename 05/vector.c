#include <stdio.h>
#include <stdlib.h>

char **storage;
unsigned short capacity;

void vector(unsigned short size)
{
	storage = (char**)calloc(size, sizeof(char*)); //initialize storage
	if (storage == NULL) exit(1); //check if storage was initialised correctly
	capacity = size;  //initialized capacity
}

void push(char *string)
{
  int c = capacity;

  //loop over storage
	for (int i = 0; i < c; i++)
  {
    //insert string if storage is empty at i
		if (storage[i] == NULL)
    {
			storage[i] = string;
			return;
		}
	}
  
  char **old = storage; //make copy of storage pointer
	vector(2*c);  //create larger storage
  
  //copy elements from old to storage
  for (int i = 0; i < c; i++) storage[i] = old[i]; 
  storage[c] = string;  //insert string at first new index
  free(old);  //free up old memory
}

char* at(unsigned short index)
{
  //check if index is legal and return corresponding element (or NULL)
	if (index < capacity) return storage[index];
	return NULL;
}

void set(unsigned short index, char *string)
{
  //check if index is legal and set string at coresponding position
	if (index < capacity) storage[index] = string;
	return;
}

unsigned short size(void)
{
	unsigned short s = 0; //initialize temp. variable for size

  //loop over entire storage array
	for (int i = 0; i < capacity; i++)
  {
    //increment size if the current element exists
    if (storage[i] != NULL) s ++;
  }
	return s;
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
