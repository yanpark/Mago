#include <stdio.h>
#include <stdlib.h>

void Cabecalho();
void Vetor(int n, int *p);

int main(void){
	int n,;
	int *p;
	
	Cabecalho();
	Vetor(n,p);
	
	printf("\n\n");
	system("pause");
	return 0;
}

void Vetor(int n, int *p){
	int i=0;	

	printf("Informe N elementos: ");
	scanf("%d", &n);
	system("cls");
	p = (int *) calloc(n, sizeof(int));
	Cabecalho();	
	while(i<n){
		printf("Informe o valor da posicao p[%d]: ", i);
		scanf("%d", &p[i]);
		i++;
	}
	system("cls");
	Cabecalho();
    i=0;	
	while(i<n){
		printf(" %d", p[i]);
		i++;
	}
	free(p);
}
