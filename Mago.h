#include <iostream>

using namespace std;

class Mago{
	
	public:
		Mago();
    		bool atacar();
    		bool defender();
	    	bool pegarItem();
	    
	private:
		string nome;
        	int forca = 0;
	    	int defesa = 162;
	    	int magia = 300;
	    	int defesaEspecial = 255;
	    	int velocidade = 228;
};

