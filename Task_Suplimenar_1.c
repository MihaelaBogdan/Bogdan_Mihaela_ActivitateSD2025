#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int id;
    char* titlu;
    int nrPagini;
    float* pretPePagina; 
} Document;


Document citireDocument() {
    Document doc;
    printf("ID: ");
    scanf("%d", &doc.id);

    char buffer[100];
    printf("Titlu: ");
    scanf(" %[^\n]", buffer); 
    doc.titlu = (char*)malloc(strlen(buffer) + 1);
    strcpy(doc.titlu, buffer);

    printf("Numar pagini: ");
    scanf("%d", &doc.nrPagini);

    if (doc.nrPagini > 0) {
        doc.pretPePagina = (float*)malloc(sizeof(float) * doc.nrPagini);
        for (int i = 0; i < doc.nrPagini; i++) {
            printf("Pret pagina %d: ", i + 1);
            scanf("%f", &doc.pretPePagina[i]);
        }
    }
    else {
        doc.pretPePagina = NULL;
    }

    return doc;
}


void afisareDocument(Document doc) {
    printf("\nDocument:\n");
    printf("ID: %d\n", doc.id);
    printf("Titlu: %s\n", doc.titlu);
    printf("Numar pagini: %d\n", doc.nrPagini);
    printf("Preturi pe pagina: ");
    for (int i = 0; i < doc.nrPagini; i++) {
        printf("%.2f ", doc.pretPePagina[i]);
    }
    printf("\n");
}


float sumaPreturi(Document doc) {
    float suma = 0;
    for (int i = 0; i < doc.nrPagini; i++) {
        suma += doc.pretPePagina[i];
    }
    return suma;
}


void modificareTitlu(Document* doc, const char* nouTitlu) {
    if (doc->titlu) free(doc->titlu);
    doc->titlu = (char*)malloc(strlen(nouTitlu) + 1);
    strcpy(doc->titlu, nouTitlu);
}


void dezalocareDocument(Document* doc) {
    if (doc->titlu) free(doc->titlu);
    if (doc->pretPePagina) free(doc->pretPePagina);
}
