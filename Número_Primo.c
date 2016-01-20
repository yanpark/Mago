#include <stdio.h>
#include <stdlib.h>

int NumPrimo(int valor);

int main(void){
	int valor;
	
	NumPrimo(valor);
	
	system("pause");
	return 0;
}

int NumPrimo(int valor){
	int cont=1, i=2;
	
	printf("Informe um valor: ");
	scanf("%d", &valor);
	while(i<=valor/2){
		if(valor%i>0){
			cont=1;
		}
		else{
			cont=0;
			break;
		}
		i++;
	}
	if(cont==0){
		printf("\nEsse numero nao eh primo\n\n");
	}
	else printf("\nEsse numero eh primo\n\n");
}
