#include<stdio.h>
#include<stdlib.h>

struct Telefon {
	int id;
	int lot;
	char* model;
	int baterie;
	char initialaProducator;
	
};

struct Telefon initializare(int id, int lot, char* model, int baterie, char initialaProducator) {
	struct Telefon t;
	t.id = id;
	t.lot = lot;
	t.baterie = baterie;
	t.model = (char*)malloc(strlen(model) + 1);
	strcpy_s(t.model, strlen(model) + 1, model);
	t.initialaProducator = initialaProducator;



	//initializare structura 
	return t;
}

void afisare(struct Telefon t) {
	printf("Id %d\n", t.id);
	printf("Lot %d\n", t.lot);
	printf("model %s\n", t.model);
	printf("baterie %d\n", t.baterie);
	printf("initiala %c\n", t.initialaProducator);

	//afisarea tuturor atributelor.
}

void modifica_Atribut(struct Telefon* t,const char* modelnou) {
	//modificarea unui atribut
	if (strlen(modelnou) > 2) {
		if (t->model != NULL) {
			free(t->model);

		}
		t->model = (char*)malloc(strlen(modelnou) + 1);
		strcpy_s(t->model, strlen(modelnou) + 1, modelnou);

	}


}

void dezalocare(struct Telefon* t) {
	//dezalocare campuri alocate dinamic
	if (t->model != NULL) {
		free(t->model);
		t->model = NULL;

	}

}

int main() {
	struct Telefon telefon;
	telefon = initializare(1, 2002, "Galaxy", 30, 'S');
	afisare(telefon);
	modifica_Atribut(&telefon, "Fold");
	afisare(telefon);
	dezalocare(&telefon);



	return 0;
}