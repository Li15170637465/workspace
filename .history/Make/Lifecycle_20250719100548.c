#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

#define MAX_STATUS 10
#define MIN_STATUS 0

int cycleTimes = 0;
int healthStatus = 5;
int bedTime = 5;
int foodEnergy = 5;
int waterVolume = 5;
int toiletPlace = 5;
int airQuality = 5;
int clothingEnvironment = 5;

int win_time_rand(int min, int max) {
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    srand((unsigned int)(counter.QuadPart & 0xFFFFFFFF));
    return min + rand() % (max - min + 1);
}

void print_status() {
    printf("====================================\n");
    printf("Day: %d\n", cycleTimes);
    printf("Health      : %d\n", healthStatus);
    printf("Energy      : %d\n", foodEnergy);
    printf("Hydration   : %d\n", waterVolume);
    printf("Sleep       : %d\n", bedTime);
    printf("Air Quality : %d\n", airQuality);
    printf("Toilet      : %d\n", toiletPlace);
    printf("Warmth      : %d\n", clothingEnvironment);
    printf("====================================\n\n");
}

void clamp(int *value) {
    if (*value > MAX_STATUS) *value = MAX_STATUS;
    if (*value < MIN_STATUS) *value = MIN_STATUS;
}

void do_action(int choice) {
    switch(choice) {
        case 1: // Sleep
            printf("You chose to sleep. Zzz...\n");
            bedTime += 3; clamp(&bedTime);
            healthStatus += 1; clamp(&healthStatus);
            foodEnergy -= 1; clamp(&foodEnergy);
            waterVolume -= 1; clamp(&waterVolume);
            break;
        case 2: // Eat
            printf("You chose to eat. Yum!\n");
            foodEnergy += 3; clamp(&foodEnergy);
            healthStatus += 1; clamp(&healthStatus);
            toiletPlace += 1; clamp(&toiletPlace);
            break;
        case 3: // Breath
            printf("You take a deep breath of fresh air.\n");
            airQuality += 2; clamp(&airQuality);
            healthStatus += 1; clamp(&healthStatus);
            break;
        case 4: // Drink
            printf("You drank some water.\n");
            waterVolume += 3; clamp(&waterVolume);
            healthStatus += 1; clamp(&healthStatus);
            break;
        case 5: // Excretion
            printf("You went to the toilet.\n");
            toiletPlace = 0;
            healthStatus += 1; clamp(&healthStatus);
            break;
        case 6: // Warm
            printf("You put on warm clothes.\n");
            clothingEnvironment += 2; clamp(&clothingEnvironment);
            healthStatus += 1; clamp(&healthStatus);
            break;
        default:
            printf("Invalid action!\n");
    }
}

int check_gameover() {
    if (healthStatus <= MIN_STATUS) {
        printf("You have lost all health. Game Over!\n");
        return 1;
    }
    if (foodEnergy <= MIN_STATUS) {
        printf("You starved. Game Over!\n");
        return 1;
    }
    if (waterVolume <= MIN_STATUS) {
        printf("You died of thirst. Game Over!\n");
        return 1;
    }
    return 0;
}

int main() {
    int choice;
    while (1) {
        system("cls");
        time_t now;
        time(&now);
        printf("Current time: %s", ctime(&now));
        print_status();

        printf("Choose your action today:\n");
        printf("1. Sleep\n2. Eat\n3. Breath\n4. Drink\n5. Excretion\n6. Warm\n");
        printf("Or enter 0 for a random event!\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            choice = win_time_rand(1, 6);
            printf("Random event! You got: %d\n", choice);
            Sleep(1000);
        }

        do_action(choice);

        // 状态自然衰减
        foodEnergy -= 1; clamp(&foodEnergy);
        waterVolume -= 1; clamp(&waterVolume);
        bedTime -= 1; clamp(&bedTime);
        airQuality -= 1; clamp(&airQuality);
        clothingEnvironment -= 1; clamp(&clothingEnvironment);

        cycleTimes++;

        if (check_gameover()) break;

        printf("\nPress Enter to continue...\n");
        getchar(); getchar();
    }
    return 0;
}
