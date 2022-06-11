/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main (argc, argv)
    int argc;
    char *argv[];
    {
        //inicializar c como char c
        int c, i, inword;
        FILE *fp;
        //Falta inicializar long linect = 0, wordct = 0, charct = 0;
        long linect, wordct, charct;
        // Se deben inicializar en 0
        long tlinect = 1, twordct = 1, tcharct = 1;
        i = 1;
        do { 
            if (argc > 1 && (fp=fopen(argv[i], "r")) == NULL) {
                fprintf (stdout, "can't open %s\n", argv[i]);
                exit (1);
            }
            //Inicializacion incorrecta: linect = 0, wordct = 0, charct = 0;
            linect = wordct = charct = 0;
            //inword debería ser 1 para que no entre a la condición de else if
            inword = 0;
            while ((c = getc(fp)) != EOF) {
                ++charct;
                if (c == '\n')
                    ++linect;

                if (c == ' ' || c == '\t' || c == '\n')
                    inword = 0;
                else if (inword == 0) {
                    inword = 1; 
                    ++wordct; 
                } 
            }
            printf("%7ld %7ld %7ld", linect, wordct, charct);
            if (argc > 1)
                printf(" %s\n", *argv);
            else
                printf("\n");
            fclose(fp);
            tlinect += linect;
            twordct += wordct;
            tcharct += charct; 
        } while (++i <= argc);
        if (argc > 1)
            //El total de lineas no es la variable que suma todas las de los archivos
            printf("%7ld %7ld %7ld total\n", linect, twordct, tcharct);
        exit(0); 
}
