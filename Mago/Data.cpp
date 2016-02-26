#include <iostream>
#include <iomanip>
#include "Data.h"

using namespace std;

Data::Data(int dia, int mes, int ano){
	
	if(mes>0 && mes<13){
        this->mes=mes;
    }
    else{
        this->mes=1;
	}
	this->ano=ano;
	dia=checarDia(dia);
    this->dia=dia;
}

int Data::checarDia(int dia) const{
	
	static const int diasPorMes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(dia>0 && dia <= diasPorMes[mes]){
		return dia;
	}
		
	if(mes==2 && dia==29 && (ano%400==0 || (ano%4==0 && ano%100!=0))){// test bissextile year
		return dia;
	}
	
	cout << "\n\nDia invalido";
	return 1;
}

void Data::print() const{
    
	cout << setw(38) << "Data de Formacao Magica " << setw(3) << dia << "/" << mes << "/" << ano << endl << endl;
}
