//Cosa fa questo programma?
//Questo programma ha lo scopo di simulare un dizionario consultabile dall'utente attraverso
//la ricerca, la stampa e la sua visualizzazione;

#include "dictionary.h"

int main(void) {
    int dim = 0;
    int choice = 0;
    Dictionary dictionary[100] = {};

    do {
        choose_operations(dictionary, &dim, &choice);
    } while (choice != 5);

    return 0;
}