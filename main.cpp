#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#include"Personagem.h"
#include"Mago.h"
#include"Guerreiro.h"
#include"Data.h"

#include"Wizard.h"
#include"Sorcerer.h"
#include"Ranger.h"

using namespace std;

int main(int argc, char **argv){
	
	vector < Personagem * > personagens(3);
    
    personagens[0] = new Wizard("Gandalf", 1);
    personagens[1] = new Sorcerer("Soris", 1);
    personagens[2] = new Ranger("Auros", 1);
    
    for(int i = 0; i < 3; i++){
	
        personagens[i] -> verificarStatus();
        personagens[i] -> batalhar();
        personagens[i] -> atacar();
        personagens[i] -> defender();
        personagens[i] -> imprimirData();
									
        Mago *ptr1 = dynamic_cast <Mago *> (personagens[i]);
        if(ptr1 != 0){
            ptr1 -> aumentarMana();
        }

        Wizard *ptr2 = dynamic_cast <Wizard *> (personagens[i]);
        if(ptr2 != 0){
            ptr2 -> magiaElementar();
        }			

        Sorcerer *ptr3 = dynamic_cast <Sorcerer *> (personagens[i]);
        if(ptr3 != 0){
            ptr3 -> magiaNegra();
        }
        
        cout << endl << endl;
    }
    personagens.clear();
	return 0;
}