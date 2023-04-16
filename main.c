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
//---------количество дорог----------
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
//---------путь из а в б----------
int path (int a,int b,int**m,int not[])
{

    if (a==b) {printf("%i ", a); return 1;}
    else
    {
        not[b]=1;
        for (int i=1; i < size; i++)
            if ((m[i][b]==1)&&(not[i]==0))
                if (path(a,i,m,not))
                {printf("%i ", b);
                    i=size;
                    return 1;
                }
    }
    not[b]=0;
    return 0;
}
//---------печатаем марицу смежности----------
void pr(int n, int**m, FILE *fo )
{
    for (int i=1;i<=n;i++)//вывод результата
    {
        for (int j = 1; j <= n; j++)
            fprintf(fo,"%i ", m[i][j]);
        fprintf(fo,"\n");
    }
}
void pr_in_cons(int n, int**m )
{
    for (int i=1;i<=n;i++)//вывод результата
    {
        for (int j = 1; j <= n; j++)
            printf("%i ", m[i][j]);
        printf("\n");
    }
}

void main(){
    FILE *f, *fo;
    int not[size];
    for (int i=0;i<size;i++){
        not[i]=0;
    }
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
    f=fopen("input2.txt","r");
    int n,b,c,a,d;
    //---------считываем из файла инфу----------
    while (!feof(f))
    {

        fscanf(f,"%i",&n);
        fscanf(f,"%i%i",&a,&b);
        while (a!=-1)//заполнение массива
        {
            m[a][b]=1;
            fscanf(f,"%i%i",&a,&b);
        }
        fscanf(f,"%i%i",&a,&b);
        while (a!=-1)//удаление граней
        {
            m[a][b]=0;
            fscanf(f,"%i%i",&a,&b);
        }

    }

    pr_in_cons(n,m);
    c=4; d=6;
    if (!path(c,d,m,not)) printf("NO WAY");

    fclose(f);
    fclose(fo);
}