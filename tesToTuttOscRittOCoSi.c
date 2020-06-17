#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define L 500

int caratteri_intoccabili(char c);
char modifica_frase(char frase[], int freq);


int main(){
	char frase[L];
	char si;
	int freq;
	printf("Inserire una frase da mOdiFiCArE: ");
	fgets(frase, L, stdin);
	do{
		printf("Inserire la frequenza di cambiamento [1 = mai, 2 = 50%%, 3 = 33%%, ...]: ");
		scanf("%d", &freq);
	} while (freq <= 0);
	
	system("CLS");
	printf(" Frase inserita:\n ");
	fputs(frase, stdout);

	do{	// modifica finche' non piace all'utente
		modifica_frase(frase, freq);

		printf("\n Frase modificata (freq = %d):\n ", freq);
		fputs(frase, stdout);
		printf("\n\n");
		printf("Ti piace? [y/n]: ");
		scanf("\n%c", &si);
	} while (si != 'y');
	printf("\n Bene, arrivederci. ");
	system("PAUSE");

	return 0;
}

int caratteri_intoccabili(char c){
	// i, l sono difficili da distinguere quando I l.
	// inoltre non devo modificare i caratteri speciali
	int p;
	char caratteri[] = "iL";
	for(p=0; p<strlen(caratteri); p++){
		if(c == caratteri[p]){
			return 1;	// e' un carattere speciale
		}
	}
	return 0;
}

char modifica_frase(char frase[], int freq){
	srand(time(NULL));
	int offset, j;
	char c;
	for(j=0; j<strlen(frase); j++){
		c = frase[j];
		if(!caratteri_intoccabili(c)){
			offset=rand()%freq;
			if(c >= 'a' && c <= 'z' && offset == 1){	// se e' minuscola
				frase[j] -= 'a'-'A';
			}
			if(c >= 'A' && c <= 'Z' && offset == 1){	// se e' maiuscola
				frase[j] += 'a'-'A';
			}
		} // else il carattere speciale rimane invariato
	}
}
