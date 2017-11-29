#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "animal.h"


int main() {
    FILE* filePtr;
    filePtr = fopen("animals.dat", "rb+");
    if (filePtr == NULL) {
        printf("The file could not be reached.");
        return -1;
    }
    int input = -1;
    while(input != 0) {
        printf("Please enter a number between 1 and 5 for operations and 0 to exit\n");
        scanf("%d", &input);
        while(getchar() != '\n') {;}
        while(input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 0) {
            printf("The input is not correct, please enter 1, 2, 3, 4, or 5\n");
            scanf("%d", &input);
            while(getchar() != '\n') {;}
        } 
        printf("%d\n", input);
        if (input == 1) {
            toString(filePtr);
        } else if (input == 4) {
            updateAnimal(filePtr);
        }   
        rewind(filePtr);
    }
    printf("YEEAAAAAH BOUIIIIIII\n");
	fclose(filePtr);    
	return 1;
}






