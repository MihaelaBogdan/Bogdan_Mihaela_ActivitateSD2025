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


struct Nod {
	Masina info;
	struct Nod* next;
};
typedef struct Nod N;


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

void afisareListaMasini(N* nod) {
	
	while (nod) {
		afisareMasina(nod->info);
		nod = nod->next;

	}

}

void adaugaMasinaInLista(N** Lista, Masina masinaNoua) {
	N* nodNou;
	nodNou = (N*)malloc(sizeof(N));
	nodNou->info = masinaNoua;
	nodNou->next = NULL;

	if ((*Lista)==NULL)
	{
		(*Lista) = nodNou;


	}
	else {
		N* aux = (*Lista);
		while (aux->next) {
			aux = aux->next;

		}
		aux->next = nodNou;


	}

}

void adaugaLaInceputInLista(/*lista de masini*/ Masina masinaNoua) {
	//adauga la inceputul listei o noua masina pe care o primim ca parametru
}

void* citireListaMasiniDinFisier(const char* numeFisier) {
	FILE* f;
	f = fopen(numeFisier, "r");
	N* lista = NULL;

	while (!feof(f)) {
		Masina m;
		while (!feof(f)) {
			Masina m = citireMasinaDinFisier(f);
			adaugaMasinaInLista(&lista, m);
		}




	}
	fclose(f);
		return lista;

}

void dezalocareListaMasini(/*lista de masini*/) {
	//sunt dezalocate toate masinile si lista de elemente
}

float calculeazaPretMediu(/*lista de masini*/) {
	//calculeaza pretul mediu al masinilor din lista.
	return 0;
}

void stergeMasiniDinSeria(/*lista masini*/ char serieCautata) {
	//sterge toate masinile din lista care au seria primita ca parametru.
	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
}

float calculeazaPretulMasinilorUnuiSofer(/*lista masini*/ const char* numeSofer) {
	//calculeaza pretul tuturor masinilor unui sofer.
	return 0;
}

int main() {
	N* nod;
	nod = citireListaMasiniDinFisier("masini.txt");
	afisareListaMasini(nod);


	return 0;
}
