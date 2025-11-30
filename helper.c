#include "helper.h"
int dhundoKitabIDSe(Kitab *shelf,int targetID){
    // Linear search standard tarike se
    for(int i=0;i<bookCount;i++){
        // Pointer arrow operator use kiya hai CO1 ke liye
        if((shelf+i)->id==targetID){
            return i; // Mil gaya, index return karo
        }
    }
    return -1; // Nahi mila, -1 return karo
}
void searchByName(Kitab *shelf){
    char query[50];
    fflush(stdin);
    printf("\nSearch query (Title/Author): ");
    fgets(query,sizeof(query),stdin);
  
    int found=0;
    printf("\nSearch Results:\n");
    for(int i=0;i<bookCount;i++){
        Kitab *k=(shelf+i);
        // Strstr use kar rahe substring dhundne ke liye
        // Case sensitive hai par chalta hai project ke liye
        if(strstr(k->naam,query) || strstr(k->likhneWala,query)){
            printf(">> FOUND: [ID: %d] %s by %s\n",k->id,k->naam,k->likhneWala);
            found=1;
        }
    }
    if(!found){
        printf(">> Kuch nahi mila bhai. Spelling check kar lo.\n");
    }
}
