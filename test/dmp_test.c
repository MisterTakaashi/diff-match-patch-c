#include "dmp_test.h"

int main(int argc, char **argv)
{
    dmp_diff *diff;
    
    // Au dela de 100 caracteres, le diff plante lamentablement
    char texte1[100];
    char texte2[100];
    int i;
    
    FILE* fichier = NULL;
    fichier = fopen("test.txt", "r");
    
    FILE* fichiercomp = NULL;
    fichiercomp = fopen("test2.txt", "r");
    
    FILE* fichiersortie = NULL;
    fichiercomp = fopen("output.txt", "w+");

    printf("Diff en cours...\n");
    
    //fgets(texte1, 100, fichier);
    //fgets(texte2, 100, fichiercomp);
    
    for(i = 0; i<=2; i++){
        fread(texte1, sizeof(char)*75, 1, fichier);
        fread(texte2, sizeof(char)*75, 1, fichiercomp);//sizeof(texte2)
        
        //printf("\n%s\n\n", texte1);
        
        // dmp_diff_from_strs(&diff, NULL, "Apples are a fruit.", "Bananas are also fruit.");
        dmp_diff_new(&diff, NULL, texte1, strlen(texte1), texte2, strlen(texte2));
        dmp_diff_print_raw(fichiercomp, diff); //stderr pour ecran
        dmp_diff_free(diff);
        
        //long tailleFichier = ftell(fichier);
        //printf("\nPosition pointeur du premier fichier: %ld \n", tailleFichier);
    }
    
    printf("\nDiff terminé !\n");
    
    return 0;
}
