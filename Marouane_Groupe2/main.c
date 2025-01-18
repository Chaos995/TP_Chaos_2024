#include <stdio.h>
#include <string.h>
#include "bibliotheque.h"

int main(){

    int choice = user_choice();
    switch(choice){
        case 0:
            admin();
            break;
        case 1:
            user();
            break;
    }

    return 0;

}
