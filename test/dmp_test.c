#include "dmp_test.h"

int main(int argc, char **argv)
{
    dmp_diff *diff;
    
    char texte1[254];
    char texte2[254];
    
    FILE* fichier = NULL;
    fichier = fopen("test.txt", "r");
    
    FILE* fichiercomp = NULL;
    fichiercomp = fopen("test2.txt", "r"); 
    
    fread(texte1, sizeof(texte1), 1, fichier);
    fread(texte2, sizeof(texte2), 1, fichiercomp);
    
    printf("Diff en cours...\n");
    
    //dmp_diff_from_strs(&diff, NULL, "Apples are a fruit.", "Bananas are also fruit.");
    dmp_diff_new(&diff, NULL, texte1, strlen(texte1), texte2, strlen(texte2));
    dmp_diff_print_raw(stderr, diff);
	dmp_diff_free(diff);
    
    printf("\nDiff en cours...\n");
    
    return 0;
}
