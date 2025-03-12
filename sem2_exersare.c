#include<stdio.h>
#include<malloc.h>

struct Telefon {
	int id;
	int RAM;
	char* producator;
	float pret;
	char serie;

};
struct Telefon initializare(int id, int RAM, const char* producator, float pret, char serie) {
	struct Telefon t;
	t.id = id;
	t.RAM = RAM;
	t.producator = (char*)malloc(sizeof(char) * (strlen(producator) + 1));
	strcpy_s(t.producator, strlen(producator + 1, producator));
	t.serie = serie;
	return t;

}
void afisare(struct Telefon t) {
	if (t.producator != NULL) {
		printf("Telefonul cu id-ul %d, are RAM %d, este produs de %s, are pretul de %5.2f si are seria %c", t.id, t.RAM, t.producator, t.pret, t.serie);

	}
}
void afisareVector(struct Telefon vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisare(vector[i]);

	}
}

int main() {
	struct Telefon* telefoane = NULL;//vector de telefoane
	int nrTelefoane = 4;
	telefoane = (struct Telefon*)malloc(sizeof(struct Telefon) * nrTelefoane);


}