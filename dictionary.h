/*
 Struct di tipo Dictionary

 Com'è composta?
 Sarà composta dai seguenti elementi:
  -char word[20] -> array di caratteri con dimensione massima pari a 20, che rappresenta la parola del dizionario.
  -char description[200] -> array di caratteri con dimensione massima pari a 200, che rappresenta la descrizione della parola.
  -synonyms[5][20] -> matrice di caratteri , che fa riferimento ai 5 sinonimi per parola con dimensione massima pari a 20.
 */

typedef struct {
    char word[20];
    char description[200];
    char synonyms[5][20];
} Dictionary;

/*
[choose_operations]: {

     Cosa fa?
     In base alla scelta dell'utente svolge varie operazioni;

     (inputs) -> {
       Dictionary * = Passo l'indirizzo di memoria della struct [dictionary[100]];
       int *dim = Passo il puntatore dell'indirizzo di memoria della variabile dim;
     }

     (Output) -> {
       Esegue quella determinata funzione scelta dall'utente;
       Non ritorna niente poichè non c'è nè alcun bisogno;
     }
   }
 */
void choose_operations(Dictionary *, int *dim, int *choice);

/*
[check_equal_words]: {

     Cosa fa?
     Controlla se il dizionario sia vuoto;

     (inputs) -> {
       Dictionary * = Passo l'indirizzo di memoria della struct [dictionary[100]];
       int *dim = Passo il puntatore dell'indirizzo di memoria della variabile dim;
     }

     (Output) -> {
      Ritorna un valore compreso tra 0 o 1 , nel caso in cui sia 1 allora vuol dire che il dizionario e vuoto;
     }
   }
 */
int check_equal_words(Dictionary * , int *dim , char word[20] , char description[200] , char synonyms[5][20]);


/*
[check_empty_dictionary]: {

    Cosa fa?
    Controlla se il dizionario sia vuoto;

    (inputs) -> {
        Dictionary * = Passo l'indirizzo di memoria della struct [dictionary[100]];
        int *dim = Passo il puntatore dell'indirizzo di memoria della variabile dim;
    }

    (Output) -> {
        Ritorna un valore compreso tra 0 o 1 , nel caso in cui sia 1 allora vuol dire che il dizionario e vuoto;
    }
}
*/
int check_empty_dictionary(int *dim);


/*
[printFormat]: {
     Cosa fa?
     Stampa "----------------------------------------------------------------------\n" ;
 }
 */
void printFormat();


/*
[printDictionary]: {

     Cosa fa?
     Stampa tutti gli elementi presenti nella struct //dictionary[100]\\ ovvero il dizionario effettivo;

     (inputs) -> {
       Dictionary * = Passo l'indirizzo di memoria della struct [dictionary[100]];
       int *dim = Passo il puntatore dell'indirizzo di memoria della variabile dim;
     }

     (Output) -> {
       Stampa tutti gli elementi presenti nel dizionario ovvero nella struct;
       Non ritorna niente poichè non c'è nè alcun bisogno;
     }
   }
 */
void printDictionary(Dictionary *, int *dim);


/*
[sortDictionary]: {

     Cosa fa?
     Ordina attraverso l'algoritmo del bubble sorting in ordine alfabetico il dizionario;

     (inputs) -> {
       Dictionary * = Passo l'indirizzo di memoria della struct [dictionary[100]];
       int *dim = Passo il puntatore dell'indirizzo di memoria della variabile dim;
     }

     (Output) -> {
       Attraverso il puntatore della struct //dictionary[100]\\ ordina la struct in ordine alfabetico;
     }

   }
 */
void sortDictionary(Dictionary *, int *dim);


/*
[insertWord]: {

     Cosa fa?
     Inserisce una nuova parola in input dall'utente all'interno del dizionario;

     (inputs) -> {
       Dictionary * = Passo l'indirizzo di memoria della struct [dictionary[100]];
       int *dim = Passo il puntatore dell'indirizzo di memoria della variabile dim;
     }

     (Output) -> {
       Attraverso il puntatore della struct //dictionary[100]\\ aggiunge la nuova parola;
     }

   }
 */
void insertWord(Dictionary *, int *dim);


/*
[searchWord]: {

     Cosa fa?
     Cerca una parola in input dall'untente;

     (inputs) -> {
       Dictionary * = Passo l'indirizzo di memoria della struct [dictionary[100]];
       char word[20] = Parola da cercare nel dizionario passata per valore;
       int *dim = Passo il puntatore dell'indirizzo di memoria della variabile dim;
     }

     (Output) -> {
       Cerca la parola in input dall'utente, in caso in cui sia trovata stampa la parola
       con la sua descrizione e sinonimi;
     }

   }
 */
void searchWord(Dictionary *, int *dim);

