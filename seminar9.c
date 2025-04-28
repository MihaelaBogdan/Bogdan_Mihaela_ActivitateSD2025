#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

//creare structura pentru un nod dintr-un arbore binar de cautare
struct Nod {
	Masina info;
	Nod* st;
	Nod*  dr;
};
typedef struct Nod Nod;


Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret= atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}


Nod* adaugaMasinaInArbore(Nod* arbore, Masina masinaNoua) {
	//adauga o noua masina pe care o primim ca parametru in arbore,
	//astfel incat sa respecte princiippile de arbore binar de cautare
	//dupa o anumita cheie pe care o decideti - poate fi ID
	if (arbore != NULL) {
		if (arbore->info.id < masinaNoua.id) {
			arbore->dr = adaugaMasinaInArbore(arbore->dr, masinaNoua);
		}
		else {
			arbore->st = adaugaMasinaInArbore(arbore->st, masinaNoua);

		}
	}
	else {
		Nod* temp = (Nod*)malloc(sizeof(Nod));
		temp->info = masinaNoua;
		temp->dr = NULL;
		temp->st = NULL;
		arbore = temp;
	}
	return arbore;


}

void* citireArboreDeMasiniDinFisier(const char* numeFisier) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	//ATENTIE - la final inchidem fisierul/stream-ul
	Nod* radacina = NULL;
	if (numeFisier != NULL && strlen(numeFisier) != 0) {
		FILE* f = fopen(numeFisier, "r");
		if (f != NULL) {
			int dim = 0;
			fscanf(f, "%d", &dim);
			for (int i = 0; i < dim; i++) {
				Masina masina;
				masina = citireMasinaDinFisier(f);
				adaugaMasinaInArbore(&radacina, masina);

			}
		}
	}
	return radacina;

}

void afisareMasiniDinArboreInOrdine(Nod* arbore) {
	//afiseaza toate elemente de tip masina din arborele creat
	//prin apelarea functiei afisareMasina()
	//parcurgerea arborelui poate fi realizata in TREI moduri
	//folositi toate cele TREI moduri de parcurgere
	
            if (arbore != NULL) {
                // Parcurgere inordine (stânga, nod curent, dreapta)
                afisareMasiniDinArbore(arbore->st); // Parcurge subarborele stâng
                afisareMasina(arbore->info);       // Afișează mașina din nodul curent
                afisareMasiniDinArbore(arbore->dr); // Parcurge subarborele drept
            }
        }


	
void afisareMasiniDinArboreInPreOrdine(Nod* arbore) {
    if (arbore != NULL) {
        // Afișăm mașina din nodul curent
        afisareMasina(arbore->info);

        // Parcurgem subarborele stâng
        afisareMasiniDinArboreInPreOrdine(arbore->st);

        // Parcurgem subarborele drept
        afisareMasiniDinArboreInPreOrdine(arbore->dr);
    }
}


    void afisareMasiniDinArboreInPostOrdine(Nod* arbore) {
        if (arbore != NULL) {
            // Parcurgem subarborele stâng
            afisareMasiniDinArboreInPostOrdine(arbore->st);

            // Parcurgem subarborele drept
            afisareMasiniDinArboreInPostOrdine(arbore->dr);

            // Afișăm mașina din nodul curent
            afisareMasina(arbore->info);
        }
    }
    // Parcurgere postordine (stânga, dreapta, nod curent)


void dezalocareArboreDeMasini(Nod* arbore) {
    if (arbore != NULL) {
        // Dezalocăm subarborele stâng
        dezalocareArboreDeMasini(arbore->st);

        // Dezalocăm subarborele drept
        dezalocareArboreDeMasini(arbore->dr);

        // Dezalocăm câmpurile alocate dinamic din structura Masina
        free(arbore->info.model);
        free(arbore->info.numeSofer);

        // Dezalocăm nodul curent
        free(arbore);
    }
	
}   

Masina getMasinaByID(Nod* arbore,int id) {
	Masina m;
	if (arbore) {
		if (arbore->info.id < id) {
			return getMasinaByID(arbore->dr, id);

		}
		else {
			if (arbore->info.id > id) {
				return getMasinaByID(arbore->st, id);
			}

		}
	}
	else {
		Masina m;
		m.id = -1;
		m.numeSofer = NULL;
		m.nrUsi = 0;
		m.model = NULL;
		m.pret = 0;
		m.serie = 0;

	}
	

	return m;
}

int determinaNumarNoduri(Nod* arbore) {  
// Calculeaza numarul total de noduri din arborele binar de cautare  
if (arbore) {  
	// Numarul total de noduri este suma nodurilor din subarborele stang,  
	// nodurile din subarborele drept si nodul curent  
	return 1 + determinaNumarNoduri(arbore->st) + determinaNumarNoduri(arbore->dr);  
}  
return 0;  
}

int calculeazaInaltimeArbore(Nod* arbore) {  
   // Verificăm dacă arborele este gol  
   if (arbore == NULL) {  
       return 0;  
   }  

   // Calculăm înălțimea subarborelui stâng  
   int inaltimeStanga = calculeazaInaltimeArbore(arbore->st);  

   // Calculăm înălțimea subarborelui drept  
   int inaltimeDreapta = calculeazaInaltimeArbore(arbore->dr);  

   // Înălțimea arborelui este maximul dintre cele două înălțimi + 1 (pentru nodul curent)  
   return 1 + (inaltimeStanga > inaltimeDreapta ? inaltimeStanga : inaltimeDreapta);  
}

float calculeazaPretTotal(Nod* arbore) {  
   // Calculeaza pretul total al masinilor din arbore  
   if (arbore == NULL) {  
       return 0;  
   }  

   // Pretul total este suma pretului masinii curente si preturile din subarbori  
   return arbore->info.pret + calculeazaPretTotal(arbore->st) + calculeazaPretTotal(arbore->dr);  
}  

float calculeazaPretulMasinilorUnuiSofer(Nod* arbore, const char* numeSofer) {  
   // Calculeaza pretul total al masinilor unui sofer specific  
   if (arbore == NULL) {  
       return 0;  
   }  

   float pretSofer = 0;  

   // Verificam daca masina curenta apartine soferului specificat  
   if (strcmp(arbore->info.numeSofer, numeSofer) == 0) {  
       pretSofer = arbore->info.pret;  
   }  

   // Suma preturilor masinilor din subarbori care apartin aceluiasi sofer  
   return pretSofer + calculeazaPretulMasinilorUnuiSofer(arbore->st, numeSofer) + calculeazaPretulMasinilorUnuiSofer(arbore->dr, numeSofer);  
}

int main() {
    Nod* arbore = NULL;

    // Citim arborele din fișier
    arbore = citireArboreDeMasiniDinFisier("masini.txt");
    if (arbore == NULL) {
        printf("Eroare: Nu s-a putut citi arborele din fisier sau fisierul este gol.\n");
        return -1;
    }

    // Afișăm mașinile din arbore în toate cele trei moduri de parcurgere
    printf("Afisare masini in ordine (inordine):\n");
    afisareMasiniDinArboreInOrdine(arbore);

    printf("\nAfisare masini in preordine:\n");
    afisareMasiniDinArboreInPreOrdine(arbore);

    printf("\nAfisare masini in postordine:\n");
    afisareMasiniDinArboreInPostOrdine(arbore);

    // Exemplu: Căutăm o mașină după ID
    int idCautat = 2; // ID-ul pe care dorim să-l căutăm
    Masina masinaGasita = getMasinaByID(arbore, idCautat);
    if (masinaGasita.id != -1) {
        printf("\nMasina cu ID-ul %d a fost gasita:\n", idCautat);
        afisareMasina(masinaGasita);
    } else {
        printf("\nMasina cu ID-ul %d nu a fost gasita.\n", idCautat);
    }

    // Exemplu: Calculăm statistici
    int numarNoduri = determinaNumarNoduri(arbore);
    printf("\nNumarul total de masini din arbore: %d\n", numarNoduri);

    int inaltimeArbore = calculeazaInaltimeArbore(arbore);
    printf("Inaltimea arborelui: %d\n", inaltimeArbore);

    float pretTotal = calculeazaPretTotal(arbore);
    printf("Pretul total al masinilor din arbore: %.2f\n", pretTotal);

    // Exemplu: Calculăm prețul total al mașinilor unui șofer specific
    const char* numeSofer = "Ion Popescu";
    float pretSofer = calculeazaPretulMasinilorUnuiSofer(arbore, numeSofer);
    printf("Pretul total al masinilor soferului %s: %.2f\n", numeSofer, pretSofer);

    // Dezalocăm memoria utilizată de arbore
    dezalocareArboreDeMasini(arbore);

    return 0;
}