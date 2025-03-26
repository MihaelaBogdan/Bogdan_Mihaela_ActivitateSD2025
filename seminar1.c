//#include<stdio.h>
//#include<stdlib.h>
//
//struct Masina {
//	int id;
//	int anFabricatie;
//	char* sofer;
//	float kilometriParcursi;
//	char initialaProducator;
//};
//
//struct Masina initializare(int id, int anFabricatie, char* sofer, float kilometriparcursi, char initialaProducator) {
//	struct Masina m;
//	m.id = id;
//	m.anFabricatie = anFabricatie;
//	m.sofer = (char*)malloc(strlen(sofer) + 1);//cast explicit
//	strcpy_s(m.sofer, strlen(sofer) + 1, sofer);
//	m.kilometriParcursi = m.kilometriParcursi;
//	m.initialaProducator = initialaProducator;
//
//	//initializare structura 
//	return m;
//}
//
//void afisare(struct Masina m) {
//	//afisarea tuturor atributelor.
//	printf("ID, %d\n", m.id);
//	printf("An fabricatie, %d\n", m.anFabricatie);
//	printf("Sofer, %s\n", m.sofer);
//	printf("KilomettriParcursi, %f\n", m.kilometriParcursi);
//	printf("Initiala, %c\n", m.initialaProducator);
//
//
//
//}
//
//void modifica_Sofer(struct Masina* m, const char* nouSofer) {
//	//modificarea unui atribut
//	if (strlen(nouSofer) > 2) {
//		if (m->sofer != NULL) {
//			free(m->sofer);
//
//		}
//		m->sofer = (char*)malloc(strlen(nouSofer) + 1);
//		strcpy_s(m->sofer, strlen(nouSofer) + 1, nouSofer);
//
//
//	}
//}
//
//void dezalocare(struct Masina* m) {
//	//dezalocare campuri alocate dinamic
//	if (m->sofer != NULL) {
//		free(m->sofer);
//		m->sofer = NULL;
//	}
//
//
//
//}
//
//int main() {
//	struct Masina masina;
//	masina = initializare(1, 2004, "Robert", 2000, 'P');//"P"
//	afisare(masina);
//	modifica_sofer(&masina, "Alex");
//	afisare(masina);
//	dezalocare(&masina);
//
//
//
//
//	return 0;
//}
////metoda primeste pointer la obiectul pe care il apelam, adresa adresa obiectului curent este tinuta in this