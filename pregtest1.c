#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Telefon {
	int id;
	int anFabricatie;
	char* producator;
	char initialaProducator;
	float baterie;

};
typedef struct Telefon Telefon;

struct Telefon initializare(int id, int anFabricatie, const char* producator, char initialaProducator, float baterie) {
	struct Telefon t;
	t.id = id;
	t.anFabricatie = anFabricatie;
	t.initialaProducator = initialaProducator;
	t.baterie = baterie;
	t.producator = (char*)malloc(sizeof(char) * strlen(producator) + 1);
	strcpy_s(t.producator, strlen(producator) + 1, producator);
	return t;

}
void afisare(struct Telefon t) {
	if (t.producator != NULL) {
		printf("%d, %d,%s,%c,%5.2f", t.id, t.anFabricatie, t.producator, t.initialaProducator, t.baterie);
	}

}
void afisareVector(struct Telefon* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisare(vector[i]);

	}
}
void dezalocare(struct Telefon** vector, int* nrElemente) {
	for (int i = 0; i < (*nrElemente); i++) {
		if ((*vector)[i].producator != NULL) {
			free((*vector)[i].producator);
		}
	}
	free(*vector);
	*vector = NULL;
	*nrElemente = 0;
}


int main() {
	struct Telefon* telefoane = NULL;
	int nrTelefoane = 3;
	telefoane = (struct Telefon*)malloc(sizeof(struct Telefon) * nrTelefoane);
	telefoane[0] = initializare(1, 256, "Samsung", 2000, 'S');
		telefoane[1] = initializare(2, 512, "Motorola", 1500, 'M');
		telefoane[2] = initializare(3, 256, "Apple", 2200, 'A');
	
		afisareVector(telefoane, nrTelefoane);
		dezalocare(&telefoane, &nrTelefoane);


		 
	}


