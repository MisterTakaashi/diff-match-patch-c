#include "dmp_test.h"

int main(int argc, char **argv)
{
    dmp_diff *diff;
    FILE* fichier = NULL;
    fichier = fopen("test.txt", "w");
    
    printf("Diff en cours...\n");
    
    dmp_diff_from_strs(&diff, NULL, "Apples are a fruit.", "Bananas are also fruit.");
    dmp_diff_print_raw(fichier, diff);
	dmp_diff_free(diff);
    
    printf("\n\nDiff en cours...\n");
    
    return 0;
}
