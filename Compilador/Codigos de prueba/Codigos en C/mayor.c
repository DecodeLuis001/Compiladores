void printf();
/*void scanf();*/

int main(int argc) 
{
    double n1, n2, n3;
    printf("Ingrese tres numeros diferentes: ");
    /*scanf("%lf %lf %lf", &n1, &n2, &n3);*/

    /* si n1 es el mas grande */
    if (n1 >= n2 && n1 >= n3)
    printf("%.2f es el numero mas grande.", n1);

    /* si n2 es el mas grande */
    if (n2 >= n1 && n2 >= n3)
    printf("%.2f es el numero mas grande.", n2);

    /* si n3 es el mas grande */
    if (n3 >= n1 && n3 >= n2)
    printf("%.2f es el numero mas grande.", n3);

    return 0;
}
