#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"
#include "administration.h"

#define MAX_ANIMALS 100

void showAnimals(const ANIMAL* animalArray, int animalCount) {
    if (animalCount == 0) {
        printf("No animals in shelter.\n");
    } else {
        printf("Animals in shelter:\n");
        for (int i = 0; i < animalCount; ++i) {
            printf("%s - %d years old, Species: %d\n", animalArray[i].Name, animalArray[i].Age, animalArray[i].Species);
        }
    }
}

int main(void) {
    printf("PRC assignment 'Animal Shelter' (version april 2019)\n");

    ANIMAL animalArray[MAX_ANIMALS];
    int animalCount = 0;

    int choice = -1;
    while (choice != 0) {
        printf("\nMENU\n====\n");
        printf("1: Show Animals \n");
        printf("2: Add Animal \n");
        printf("3: Remove Animal \n");
        printf("4: Find Animal by name \n");
        printf("5: Sort Animals by Age \n");
        printf("6: Sort Animals by Name \n");
        printf("0: quit \n");

        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1: // Show Animals
                showAnimals(animalArray, animalCount);
                break;
            case 2: { // Add Animal
                if (animalCount >= MAX_ANIMALS) {
                    printf("Shelter is full. Cannot add more animals.\n");
                    break;
                }
                ANIMAL newAnimal;
                printf("Enter animal name: ");
                fgets(newAnimal.Name, MaxNameLength, stdin);
                newAnimal.Name[strcspn(newAnimal.Name, "\n")] = '\0'; // Remove newline character

                printf("Enter animal species (0: Cat, 1: Dog, 2: GuineaPig, 3: Parrot): ");
                int species;
                scanf("%d", &species);
                getchar(); // to consume the newline character
                newAnimal.Species = (SPECIES)species;

                printf("Enter animal age: ");
                scanf("%d", &newAnimal.Age);
                getchar(); // to consume the newline character

                addAnimal(&newAnimal, animalArray, animalCount);
                animalCount++;
                break;
            }
            case 3: { // Remove Animal
                char name[MaxNameLength];
                printf("Enter animal name to remove: ");
                fgets(name, MaxNameLength, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character

                int removedCount = removeAnimal(name, animalArray, animalCount);
                if (removedCount > 0) {
                    animalCount -= removedCount;
                    printf("%d animal(s) removed.\n", removedCount);
                } else {
                    printf("No animal found with the name '%s'.\n", name);
                }
                break;
            }
            case 4: { // Find Animal by name
                char name[MaxNameLength];
                printf("Enter animal name to find: ");
                fgets(name, MaxNameLength, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character

                ANIMAL foundAnimal;
                int found = findAnimalByName(name, animalArray, animalCount, &foundAnimal);
                if (found) {
                    printf("Found animal: %s - %d years old, Species: %d\n", foundAnimal.Name, foundAnimal.Age, foundAnimal.Species);
                } else {
                    printf("No animal found with the name '%s'.\n", name);
                }
                break;
            }
            case 5: // Sort Animals by Age
                sortAnimalsByAge(animalArray, animalCount);
                printf("Animals sorted by Age.\n");
                break;
            case 6: // Sort Animals by Name
                sortAnimalsByName(animalArray, animalCount);
                printf("Animals sorted by Name.\n");
                break;
            case 0:
                break;
            default:
                printf("ERROR: invalid choice: %d\n", choice);
                break;
        }
    }

    return 0;
}
