#include <stdio.h>
int Mass(int i,int j)
{
    return 0;
}
int isEnd (int v)
{
    return 0;
}
void main(){
    FILE *f, *fo;
    int n,i,a,b;
    int *m [10][10];
    for (i=0;i<10;i++)//пустой массив из нулей
        for (int j=0;j<10;j++)
            m[i][j]=0;
    fo=fopen("output.txt","w");
    f=fopen("input.txt","r");

    while (!feof(f))
    {

        fscanf(f,"%i",&n);
        fscanf(f,"%i%i",&a,&b);
        while (a!=-1)//заполнение массива
        {
            m[a-1][b-1]=1;
            fscanf(f,"%i%i",&a,&b);
        }
        /*fprintf(fo, "%c", c );*/
    }
    /*for (i=0;i<n;i++)//вывод результата
    {
        for (int j = 0; j < n; j++)
            fprintf(fo,"%i ", m[i][j]);
        fprintf(fo,"\n");
    }*/

    fclose(f);
    fclose(fo);
}