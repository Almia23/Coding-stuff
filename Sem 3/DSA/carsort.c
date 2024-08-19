#include <stdio.h>
#include <string.h>

// Structure to store car information
struct Car {
    int modelYear;
    char carName[50];
    char brand[50];
    char variant[50];
    float exShowroomPrice;
};

// Function to perform a linear search by brand
void lSearchBrand(struct Car cars[], int n, const char searchBrand[]) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(cars[i].brand, searchBrand) == 0) {
            printf("Car Name: %s\n", cars[i].carName);
            printf("Brand: %s\n", cars[i].brand);
            printf("Model Year: %d\n", cars[i].modelYear);
            printf("Variant: %s\n", cars[i].variant);
            printf("Ex-Showroom Price: %.2f\n", cars[i].exShowroomPrice);
            printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Car with brand '%s' not found.\n", searchBrand);
    }
}

// Function to perform bubble sort by car name
void bSortName(struct Car cars[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(cars[j].carName, cars[j + 1].carName) > 0) {
                struct Car temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }
}

// Function to perform binary search by car name
void bSearchName(struct Car cars[], int n, const char searchName[]) {
    int left = 0;
    int right = n - 1;
    int found = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (strcmp(cars[mid].carName, searchName) == 0) {
            printf("Car Name: %s\n", cars[mid].carName);
            printf("Brand: %s\n", cars[mid].brand);
            printf("Model Year: %d\n", cars[mid].modelYear);
            printf("Variant: %s\n", cars[mid].variant);
            printf("Ex-Showroom Price: %.2f\n", cars[mid].exShowroomPrice);
            printf("\n");
            found = 1;
            break;
        } else if (strcmp(cars[mid].carName, searchName) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Car with name '%s' not found.\n", searchName);
    }
}

int main() {
    struct Car cars[4];

    char searchB[50];
    char searchN[50];
    for(int i=0; i<4; i++){
        printf("Enter car %d details (year,name,brand,variant,price): ",i+1);
        scanf("%d%s%s%s%f",&cars[i].modelYear,&cars[i].carName,&cars[i].brand,&cars[i].variant,&cars[i].exShowroomPrice);
    }
    printf("Enter the brand to search for: ");
    scanf("%s", searchB);

    printf("Cars by brand '%s':\n", searchB);
    lSearchBrand(cars, 4, searchB);

    printf("Cars sorted by name:\n");
    bSortName(cars, 4);
    for (int i = 0; i < 4; i++) {
        printf("Car Name: %s\n", cars[i].carName);
        printf("Brand: %s\n", cars[i].brand);
        printf("Model Year: %d\n", cars[i].modelYear);
        printf("Variant: %s\n", cars[i].variant);
        printf("Ex-Showroom Price: %.2f\n", cars[i].exShowroomPrice);
        printf("\n");
    }

    printf("Enter the car name to search for: ");
    scanf("%s", searchN);

    printf("Car by name '%s' (binary search):\n", searchN);
    bSearchName(cars, 4, searchN);

    return 0;
}
