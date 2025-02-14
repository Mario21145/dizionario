#include "dictionary.h"
#include <stdio.h>
#include <string.h>

//Implementazione choose_operations
void choose_operations(Dictionary *dictionary, int *dim, int *choice) {
    printf("|---------------------------------------------|\n");
    printf("| Benvenuto nel dizionario di lingua italiana |\n");
    printf("|---------------------------------------------|\n");
    printf("\n");

    int current_choice = 0;
    printf("Inserire quale operazione effettuare\n");
    printf("1. Ordinare il dizionario \n");
    printf("2. Inserire una parola\n");
    printf("3. Cercare una parola\n");
    printf("4. Stampare il dizionario\n");
    printf("5. Esci dal dizionario\n");
    printf("\n");
    scanf("%d", &current_choice);

    *choice = current_choice;

    switch (*choice) {
        case 1:
            sortDictionary(dictionary, dim);
            break;
        case 2:
             insertWord(dictionary , dim);
            break;
        case 3:
            searchWord(dictionary, dim);
            break;
        case 4:
            printDictionary(dictionary , dim);
            break;
        default: printf("Uscendo...\n");
    }
}

//Implementazione check_equal_words
int check_equal_words(Dictionary *dictionary , int *dim , char word[20] , char description[200] , char synonyms[5][20]) {
    if (*dim != 0) {
        for (int i = 0; i < *dim ; i++) {
            Dictionary elem = dictionary[i];
            if (strcmp(elem.word , word) == 0 && strcmp(elem.description , description) == 0) {
                for (int j = 0 ; j < 5 ; j++) {
                    if (strcmp(elem.synonyms[j] , synonyms[j]) == 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

//Implementazione check_empty_dictionary
int check_empty_dictionary(int *dim) {
    if (*dim == 0 || *dim < 0) {
        return 1;
    }
    return 0;
}


//Implementazione printFormat
void printFormat() {
    printf("\n");
    printf("|----------------------------------------------------------------------|\n");
    printf("\n");
}



//Implementazione searchWord
void printDictionary(Dictionary *dictionary, int *dim) {
    printFormat();
    printf("[printDictionary]\n");
    printFormat();
    if (check_empty_dictionary(dim) != 1) {
        for (int i = 0; i < *dim; i++) {
            printf("Parola -> [%s]\n ", dictionary[i].word);
            printf("Descrizione -> [%s]\n ", dictionary[i].description);
            for (int j = 0; j < 5; j++) {
                printf("Sinonimo[%d] -> [%s]\n ", j + 1, dictionary[i].synonyms[j]);
            }
            printFormat();
        }
    } else {
        printFormat();
        printf("Dizionario vuoto inserire una parola \n");
        printFormat();
    }
}

//Implementazione sortDictionary
void sortDictionary(Dictionary *dictionary, int *dim) {
    printFormat();
    printf("[sortDictionary]\n");
    printFormat();
    if (check_empty_dictionary(dim) != 1) {
        printFormat();
        printf("Ordinando...\n");
        for (int i = 0; i < *dim - 1; i++) {
            for (int j = 0; j < *dim - i - 1; j++) {
                if (strcmp(dictionary[j].word, dictionary[j + 1].word) > 0) {
                    Dictionary temp = dictionary[j];
                    dictionary[j] = dictionary[j + 1];
                    dictionary[j + 1] = temp;
                }
            }
        }
        printFormat();
    } else {
        printFormat();
        printf("Dizionario vuoto inserire una parola\n");
        printFormat();
    }
}

//Implementazione insertWord
void insertWord(Dictionary *dictionary, int *dim) {
    printFormat();
    printf("[insertWord]\n");
    printFormat();
    printf("Parole massime[100] , Parole presenti[%d]\n", *dim);

    int num = 0;
    printf("Quante parole vuoi inserire? \n");
    scanf("%d", &num);
    getchar();

    if (*dim + num <= 100) {
        for (int i = 0; i < num; i++) {
            char word[20] = " ";
            char description[200] = " ";
            char synonyms[5][20] = {};

            printf("Inserire la parola numero[%d]: \n", i + 1);
            fgets(word, sizeof(word), stdin);
            word[strcspn(word, "\n")] = '\0';

            printf("Inserire la descrizione della parola[%s]: \n", word);
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = '\0';

            for (int j = 0; j < 5; j++) {
                printf("Inserire il sinonimo numero[%d] della parola[%s]: \n", j + 1, word);
                fgets(synonyms[j], sizeof(synonyms[j]), stdin);
                synonyms[j][strcspn(synonyms[j], "\n")] = '\0';
            }


            if (check_equal_words(dictionary, dim, word, description, synonyms) != 1) {
                strcpy(dictionary[*dim].word, word);
                strcpy(dictionary[*dim].description, description);
                for (int k = 0; k < 5; k++) {
                    strcpy(dictionary[*dim].synonyms[k], synonyms[k]);
                }
                (*dim)++;

                printFormat();
                printf("Parola inserita con successo\n");

            } else {
                printFormat();
                printf("Parola gia' presente\n");
                printFormat();
            }
        }
        char choice_ord[2] = "";
        printf("Vuoi ordinare il dizionario? [SI][NO] \n");
        scanf("%s", choice_ord);
        if (strcmp(choice_ord, "SI") == 0) {
            sortDictionary(dictionary, dim);
        }
        printFormat();
    } else {
        printFormat();
        printf("Limite massimo raggiunto\n");
        printf("Inserire al massimo [%d] parola/e \n", 100 - *dim);
        printFormat();
    }
}

//Implementazione searchWord
void searchWord(Dictionary *dictionary, int *dim) {
    printFormat();
    printf("[searchWord]\n");
    printFormat();
    char word[20] = "";
    printf("Che parola vuoi cercare?\n");
    scanf("%s", word);

    if (check_empty_dictionary(dim) != 1) {
        for (int i = 0; i < *dim; i++) {
            if (strcmp(dictionary[i].word, word) == 0) {
                printFormat();
                printf("Parola trovata\n");
                printFormat();

                printf("Parola -> [%s]\n", dictionary[i].word);
                printf("Descrizione -> [%s]\n", dictionary[i].description);
                for (int j = 0; j < 5; j++) {
                    printf("Sinonimo[%d] -> [%s]\n", j + 1, dictionary[i].synonyms[j]);
                }
                return;
            }
        }
        printFormat();
        printf("Parola non trovata\n");
        printFormat();
    } else {
        printFormat();
        printf("Dizionario vuoto inserire una parola\n");
        printFormat();
    }
}
