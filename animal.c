#pragma pack(1)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"

struct animal_tag {
    short int id;
    char name[20];
    char species[35];
    char size;
    short int age;
};

void toString(FILE* theFilePtr) {
    int count = 0;
    while(!feof(theFilePtr)) {
        if (count % 80 == 0) {
            printf("\n");
        }
        char temp;
        fread(&temp, 1, 1, theFilePtr);
        if (temp > 32 && temp < 127){
            printf("%c", temp);
        } else {
            printf(" ");
        }
        count++;
	}
}
void updateAnimal(FILE* theFilePtr) {
    short int ID;
	int maxId;
	fseek(theFilePtr, 0, SEEK_END);
	maxId = (ftell(theFilePtr))/(sizeof(struct animal_tag));
	rewind(theFilePtr);
	printf("%d", maxId);
    Animal thing = malloc(sizeof(struct animal_tag));
	if (thing == NULL) {
		printf("memory could not be allocated correctly.");
	}
    printf("Please enter an animal ID.");
    scanf("%hd", &ID);
	while(ID < 0 || ID > maxId) {
		printf("Invalid ID.\n");
    	printf("Please enter an animal ID.");
    	scanf("%hd", &ID);	
	}
	ID--;
	thing->id = ID;

	while(getchar() != '\n') {;}
    fseek(theFilePtr, (ID * sizeof(struct animal_tag)) + sizeof(short int), SEEK_SET);
    printf("Update the animal's name.");
    scanf("%s", thing->name);
	while(getchar() != '\n') {;}
    printf("Update the animal's species.");
    scanf("%s", thing->species);
	while(getchar() != '\n') {;}
    printf("Update the animal's size.");
    scanf("%c", &(thing->size));
	while(getchar() != '\n') {;}
    printf("Update the animal's age.");
    scanf("%hd", &(thing->age));
	while(getchar() != '\n') {;}

    fwrite(thing, sizeof(struct animal_tag), 1, theFilePtr);
    
    printf("%hd %s %s %c %hd\n", thing->id, thing->name, thing->species, thing->size, thing->age);
    
    free(thing);
}

