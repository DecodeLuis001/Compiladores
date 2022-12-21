void printf();
void scanf();
int main()
{
    int n,i,facto=1;
    printf("Programa que hace el factorial de un numero n\n");
    printf("Ingrese un numero n:\n");
    scanf("%i",&n);

    for(i=1;i<=n;i++)
    {
        facto*=i;
    }
    printf("El factorial de %i es: %i\n\n",n,facto);

    return 0;
}
