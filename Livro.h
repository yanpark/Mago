#include <iostream>

using namespace std;

#ifndef LIVRO_H
#define LIVRO_H

class Livro{
	
	public:
		Livro();
		int hpDoLivro();
        int magiaDoLivro();
		void print() const;
		
    protected:
        int hp;
		int magia;
};
#endif
