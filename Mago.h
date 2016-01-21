#ifndef MAGO_H
#define MAGO_H
#include <iostream.h>

class Mago{
	
	private:
    		int magiadeFogo = 250;
    		int magiadeRaio = 300;
		int magiadeAgua = 170;
		int magiadeAr = 240;
		int magiadeGelo = 220;
		int magiadeTerra = 190;
		int magiadeTrevas = 380;
	
	public:
    		void atacar();
    		void defender();
    		void invocar();
};
