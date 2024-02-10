#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

#define GARDEN_SIZE 5  
#define ZOMBIE_CHANCE 20  
#define PLANT_CHANCE 80  

typedef struct {
    int hasPlant;
    int hasZombie;
} GardenSlot;

void initializeGarden(GardenSlot garden[], int size) {
    for (int i = 0; i < size; i++) {
        garden[i].hasPlant = 0;
        garden[i].hasZombie = 0;
    }
}

void plantSeed(GardenSlot garden[], int slot) {
    if (garden[slot].hasZombie == 0) {
        garden[slot].hasPlant = 1;
        printf("Plant planted in slot %d\n", slot);
    }
    else {
        printf("Zombie already present in slot %d. Planting failed.\n", slot);
    }
}

void spawnZombie(GardenSlot garden[], int size) {
    srand((unsigned)time(NULL));
    int slot = rand() % size;
    if (garden[slot].hasPlant == 0) {
        garden[slot].hasZombie = 1;
        printf("Zombie spawned in slot %d\n", slot);
    }
    else {
        printf("Plant already present in slot %d. Zombie spawn failed.\n", slot);
    }
}

int main() {
    GardenSlot garden[GARDEN_SIZE];
    initializeGarden(garden, GARDEN_SIZE);

    int round = 1;
    while (1) {
        printf("Round %d:\n", round++);
        for (int i = 0; i < GARDEN_SIZE; i++) {
            if (garden[i].hasZombie) {
                printf("Slot %d: Zombie\n", i);
            }
            else if (garden[i].hasPlant) {
                printf("Slot %d: Plant\n", i);
            }
            else {
                printf("Slot %d: Empty\n", i);
            }
        }

        int choice = 0;
        printf("Enter 1 to plant a seed or 2 to let a zombie spawn: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            int slot;
            printf("Enter the slot number to plant the seed: ");
            scanf_s("%d", &slot);
            plantSeed(garden, slot);
        }
        else if (choice == 2) {
            spawnZombie(garden, GARDEN_SIZE);
        }
        else {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        printf("Press Enter to continue...\n");
        getchar();
        system("clear"); // Clear the console for the next round  
    }

    return 0;
}