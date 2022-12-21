void printf();
void scanf();
int main()
{
    int x;
    int suma=0;
    do
    {
        printf("Ingrese un numero(si desea salir ingrese 0):\n");
        scanf("%d",&x);
        suma+=x;
    } 
    while ( x != 0);
    printf("\nLa suma es: %d\n", suma);
    return 0;
}
