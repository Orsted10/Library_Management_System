#include "common.h"
#include "godam.h"
#include "len_den.h"
#include "helper.h"
// Main entry point
// Return type int hai standard follow karne ke liye
int main(){
    // Array of structures declaration - CO2/CO3 covered
    // Stack pe memory le rahe, heap ka jhanjhat nahi chahiye abhi
    Kitab libraryShelf[MAX_KITABS];
    // Setup initial data
    setupLibrary(libraryShelf);
    int choice;
    int chaltaRahe=1; // Flag loop ke liye
    while(chaltaRahe){
        printf("\n=== DESI LIBRARY MANAGEMENT ===\n");
        printf("1. Kitab List Dekho\n");
        printf("2. Nayi Kitab Add Karo\n");
        printf("3. Kitab Issue Karo\n");
        printf("4. Kitab Return Karo\n");
        printf("5. Search Karo\n");
        printf("6. Exit (Bhago)\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        // Switch case menu driven logic
        switch(choice){
            case 1:
                sabDikhao(libraryShelf);
                break;
            case 2:
                nayiKitabDalo(libraryShelf);
                break;
            case 3:
                kitabUthao(libraryShelf);
                break;
            case 4:
                kitabWapasKaro(libraryShelf);
                break;
            case 5:
                searchByName(libraryShelf);
                break;
            case 6:
                printf("Chalo bye! Padhai likhai karo.\n");
                chaltaRahe=0;
                break;
            default:
                printf("Galat button dabaya bhai. 1 se 6 ke beech me daalo.\n");
        }
    }
    return 0;
}
