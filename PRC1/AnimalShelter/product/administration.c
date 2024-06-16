#include <stdio.h>
#include <string.h>
#include "administration.h"

int addAnimal(const ANIMAL* animalPtr, ANIMAL* animalArray, int position) {
    if (position < 0) {
        return -1; // Error: Invalid position
    }
    
    // Copy animalPtr into animalArray at position
    memcpy(&animalArray[position], animalPtr, sizeof(ANIMAL));
    
    return 0; // Success
}

int removeAnimal(const char* name, ANIMAL* animalArray, int number) {
    int count = 0;
    int i, j;
    
    for (i = 0; i < number; ++i) {
        if (strcmp(animalArray[i].Name, name) == 0) {
            // Shift elements to fill the gap
            for (j = i; j < number - 1; ++j) {
                animalArray[j] = animalArray[j + 1];
            }
            --number;
            --i; // Check the current index again after shifting
            ++count; // Increment count of removed animals
        }
    }
    
    return count;
}

int sortAnimalsByAge(ANIMAL* animalArray, int animalArrayLength) {
    int i, j;
    for (i = 0; i < animalArrayLength - 1; ++i) {
        for (j = 0; j < animalArrayLength - i - 1; ++j) {
            // Compare current and next animal's ages
            if (animalArray[j].Age > animalArray[j + 1].Age) {
                // Swap animals if they are out of order
                ANIMAL temp;
                memcpy(&temp, &animalArray[j], sizeof(ANIMAL));
                memcpy(&animalArray[j], &animalArray[j + 1], sizeof(ANIMAL));
                memcpy(&animalArray[j + 1], &temp, sizeof(ANIMAL));
            }
        }
    }
    
    return 0; // Success
}


int sortAnimalsByName(ANIMAL* animalArray, int animalArrayLength) {
    int i, j;
    for (i = 0; i < animalArrayLength - 1; ++i) {
        for (j = 0; j < animalArrayLength - i - 1; ++j) {
            // Compare current and next animal's names
            if (strcmp(animalArray[j].Name, animalArray[j + 1].Name) > 0) {
                // Swap animals if they are out of order
                ANIMAL temp;
                memcpy(&temp, &animalArray[j], sizeof(ANIMAL));
                memcpy(&animalArray[j], &animalArray[j + 1], sizeof(ANIMAL));
                memcpy(&animalArray[j + 1], &temp, sizeof(ANIMAL));
            }
        }
    }
    
    return 0; // Success
}


int findAnimalByName(const char* name, const ANIMAL* animalArray, int animalArrayLength, ANIMAL* animalPtr) {
    int i;
    for (i = 0; i < animalArrayLength; ++i) {
        if (strcmp(animalArray[i].Name, name) == 0) {
            // Copy found animal into animalPtr
            memcpy(animalPtr, &animalArray[i], sizeof(ANIMAL));
            return 1; // Found
        }
    }
    return 0; // Not found
}
