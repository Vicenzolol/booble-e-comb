#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arquivo
{
    int id, numlangs;
    char nome[50], pais[30], natal[50], estado[50];

};


int main()
{
    int i=0;
    struct arquivo arq;
    char c[1000],a;

    FILE *fp = fopen("pantheon.tsv", "r");  FILE *fa = fopen("testePantheon.tsv", "w");

    fseek(fp, 240, SEEK_SET);

    while(!feof(fp))
    {
        fscanf(fp, "%d\t", &arq.id);

        fscanf(fp, "\t%[^\t]s\t",arq.nome);

        fscanf(fp, "\t%d\t", &arq.numlangs);

        fscanf(fp, "\t%s", arq.natal);

        a = getc(fp);   a = getc(fp);

        if(a == '\t')
        {
            if (i == 0)
            {
                fscanf(fp, "\t%[^\t]s\t", arq.pais);
            }
            else
            {
                fscanf(fp, "%[^\t]s", arq.pais);
            }
        }
        else
        {
            fscanf(fp, "\t%[^\t]s", arq.estado);
            if (i == 0)
            {
                fscanf(fp, "\t%[^\t]s\t", arq.pais);
            }
            else
            {
                fscanf(fp, "%[^\t]s", arq.pais);
            }
        }

        fgets(c, 1000, fp);

        fprintf(fa,"%d \t %s \t %s\n", arq.id, arq.nome, arq.pais);

        i++;
    }

    fclose(fp); fclose(fa);

    int tam = 20,j,qtdtroca=0;
    struct arquivo ar[tam],aux;

    fp = fopen("testePantheon.tsv", "r");

    i=0;

    while(!feof(fp) && i!=tam)
    {
        fscanf(fp, "\t%d\t", &ar[i].id);

        fscanf(fp, "\t%[^\t]s\t",ar[i].nome);

        fscanf(fp, "\t%[^\n]s",ar[i].pais);

        i++;
    }

    fclose(fp);

    for(i = 0; i < tam; i++)
    {
        for(j = i+1 ; j < tam; j++)
        {
            if(strcmp(ar[ i ].nome,ar[ j ].nome)==1)
            {
                aux = ar[i];
                ar[i] = ar[j];
                ar[j] = aux;
                qtdtroca++;
            }
        }
    }

    fp = fopen("orgbubblepantheon.tsv", "w");

    for(j = 0; j < tam; j++)
    {
        fprintf(fp,"%d %s %s\n", ar[j].id, ar[j].nome, ar[j].pais);
    }

    fclose(fp);

    printf("A quantidade de trocas foi de : %d",qtdtroca);

    return 0;
}
