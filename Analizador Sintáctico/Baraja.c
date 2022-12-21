#include<stdio.h>

int main()
{
	int i, posicion; 
	float auxiliar, Elementos, Indice[100];

	printf("El máximo de elementos a ingresar es 100.\n");
	printf("¿Cuantos numeros desea ingresar?: \n");
	scanf("%f", &Elementos);
	if(Elementos<=0)
	{
		printf("No puede introducir numeros menores o iguales a cero para crer un arreglo.\n");
	}

	for(i=0; i<Elementos; i++)
	{
		printf("Ingrese el dato: \n");
		scanf("%f", &Indice[i]);

		posicion=i;
		auxiliar=Indice[i]; 

		while(posicion>0 && Indice[posicion-1]>auxiliar) 
		{
			Indice[posicion]=Indice[posicion-1]; 
			posicion--; 
		}
		Indice[posicion]=auxiliar; 
	}

	printf("Los numeros de menor a mayor son: \n");
	for(i=0; i<Elementos; i++)
	{
		printf("Dato[%.2f]\n",Indice[i]);
	}
	printf("\n");

	printf("Los numeros de mayor a menor son: \n");
	for(i=Elementos; i>0; i--)
	{
		printf("Dato[%.2f]\n",Indice[i-1]);
	}
	printf("\n");

	return 0;
}