#include "dmp_test.h"

int main(int argc, char **argv)
{
    dmp_diff *diff;
    
    // Au dela de 100 caracteres, le diff plante lamentablement
    char texte1[100];
    char texte2[100];
    
    FILE* fichier = NULL;
    fichier = fopen("test.txt", "r");
    
    FILE* fichiercomp = NULL;
    fichiercomp = fopen("test2.txt", "r");

    printf("Diff en cours...\n");
    
    fgets(texte1, 100, fichier);
    fgets(texte2, 100, fichiercomp);
    
    //printf("\n%s\n\n", texte1);
    
    //fread(texte1, sizeof(texte1), 1, fichier);
    //fread(texte2, sizeof(texte2), 1, fichiercomp);
    
    //dmp_diff_from_strs(&diff, NULL, "Apples are a fruit.", "Bananas are also fruit.");
    dmp_diff_new(&diff, NULL, texte1, strlen(texte1), texte2, strlen(texte2));
    dmp_diff_print_raw(stderr, diff);
	dmp_diff_free(diff);
    
    long tailleFichier = ftell(fichier);
    printf("\nTaile du premier fichier: %ld \n", tailleFichier);
    
    printf("\nDiff terminé !\n");
    
    return 0;
}
