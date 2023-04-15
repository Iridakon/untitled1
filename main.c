#include <stdio.h>
#include <stdlib.h>
#define size 10
//---------проверяем, ведут ли в вершину какие-либо пути----------
int isEnd (int v,int**m)
{
    for (int i=0;i<size;i++)//вывод результата
        if (m[i][v]==1) return 0;
    return 1;
}
int doroga (int v,int**m)
{
    if (isEnd(v,m)) return 1;
    else
    {
        int s=0;
        for (int i=0; i < size; i++)
            if (m[i][v]==1)
            s += doroga(i, m);
        return s;
    }
}
void pr(int n, int**m, FILE *fo )
{
    for (int i=0;i<n;i++)//вывод результата
    {
        for (int j = 0; j < n; j++)
            fprintf(fo,"%i ", m[i][j]);
        fprintf(fo,"\n");
    }
}
void pr_in_cons(int n, int**m )
{
    for (int i=0;i<n;i++)//вывод результата
    {
        for (int j = 0; j < n; j++)
            printf("%i ", m[i][j]);
        printf("\n");
    }
}

void main(){
    FILE *f, *fo;
    //---------создаем массив----------
    int **m=(int**)malloc(size*sizeof(int*));
    for (int i=0;i<size;i++){
        m[i]=(int*)malloc(size*sizeof(int*));
    }
    //---------заполняем нулями----------
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            m[i][j]=0;
        }
    }
    fo=fopen("output.txt","w");
    f=fopen("input.txt","r");
    int n,b,c,i,j;
    while (!feof(f))
    {

        fscanf(f,"%i",&n);
        fscanf(f,"%i%i",&c,&b);
        while (c!=-1)//заполнение массива
        {
            m[c-1][b-1]=1;
            fscanf(f,"%i%i",&c,&b);
        }

    }
    printf("%i ", doroga(4,m));



    fclose(f);
    fclose(fo);
}