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

//creare structura pentru un nod dintr-o lista dublu inlantuita
struct Nod {
	Masina info;
	struct Nod* prev;
	struct Nod* next;


};
typedef struct Nod Nod; //alias ca sa nu mai folosim struct Nod



//creare structura pentru Lista Dubla 
 struct ListaDubla {
	Nod* inceput;
	Nod* final;
};
 typedef  struct ListaDubla  Lista;



Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
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

void afisareListaMasiniDeLaInceput(Lista lis) {
	//afiseaza toate elemente de tip masina din lista dublu inlantuita
	//prin apelarea functiei afisareMasina()
	Nod* p = lis.inceput;
	while (p) {
		afisareMasina(p->info);
		p = p->next;


	}




}



void adaugaMasinaInLista(Lista* lis , Masina masinaNoua) {
	//adauga la final in lista primita o noua masina pe care o primim ca parametru
	

	Nod* nou= (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;
    nou->next = NULL;
	nou->prev =lis->final;
	if (lis->final != NULL) {
		lis->final->next = nou;
	}
	else {
		lis->inceput = nou;
	}
	lis->final = nou;
}

void adaugaLaInceputInLista( Masina masinaNoua) {
	//adauga la inceputul listei dublu inlantuite o noua masina pe care o primim ca parametru
	/*Nod* nodNou = (Nod*)malloc(sizeof(Nod));
	nodNou->info = masinaNoua;
	nodNou->prev = NULL;
	nodNou->next = lista->head;

	if (lista->head)
		lista->head->prev = nodNou;
	else
		lista->tail = nodNou;

	lista->head = nodNou;*/
}


Lista citireLDMasiniDinFisier(const char* numeFisier) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	//ATENTIE - la final inchidem fisierul/stream-ul
	FILE* f = fopen(numeFisier, "r");
	Lista lis;

	//Lista lis = { NULL,NULL };//LISTA TREBUIE OBLIGATIRU INITIALIZATA
	lis.final = NULL;
	lis.inceput = NULL;

	while (!feof(f)) {
		Masina m = citireMasinaDinFisier(f);
		adaugaMasinaInLista(&lis, m);
	}
	fclose(f);

	return lis;
}



//void dezalocareLDMasini(/*lista dubla de masini*/ ListaDubla* lista) {
//	//sunt dezalocate toate masinile si lista dublu inlantuita de elemente
//	Nod* current = lista->head;
//	while (current) {
//		free(current->info.model);
//		free(current->info.numeSofer);
//		Nod* temp = current;
//		current = current->next;
//		free(temp);
//	}
//	lista->head = NULL;
//	lista->tail = NULL;
//
//}
//
//float calculeazaPretMediu(/*lista de masini*/ListaDubla* lista) {
//	//calculeaza pretul mediu al masinilor din lista.
//	float total = 0;
//	int count = 0;
//	Nod* current = lista->head;
//	while (current) {
//		total += current->info.pret;
//		count++;
//		current = current->next;
//
//
//	}
//	return 0;
//}

//void stergeMasinaDupaID(ListaDubla* lista, int id) {
//	//sterge masina cu id-ul primit.
//	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
//	Nod* current = lista->head;
//	while (current) {
//		if (current->info.id == id) {
//			if (current->prev)
//				current->prev->next = current->next;
//			else
//				lista->head = current->next;
//
//			if (current->next)
//				current->next->prev = current->prev;
//			else
//				lista->tail = current->prev;
//
//			free(current->info.model);
//			free(current->info.numeSofer);
//			free(current);
//			return;
//		}
//		current = current->next;
//	}
//
//}
//
//char* getNumeSoferMasinaScumpa(ListaDubla*lista) {
//	//cauta masina cea mai scumpa si 
//	//returneaza numele soferului acestei maasini.
//	Nod* current = lista.head;
//	Masina* maxMasina = NULL;
//
//	while (current) {
//		if (!maxMasina || current->info.pret > maxMasina->pret) {
//			maxMasina = &current->info;
//		}
//		current = current->next;
//	}
//
//	if (maxMasina) {
//		char* rezultat = (char*)malloc(strlen(maxMasina->numeSofer) + 1);
//		strcpy(rezultat, maxMasina->numeSofer);
//		return rezultat;
//	}
//
//	return NULL;
//}



int main() {
	Lista lis;
	citireLDMasiniDinFisier("masini.txt");
	afisareListaMasiniDeLaInceput(lis);
	return 0;


  
	
}