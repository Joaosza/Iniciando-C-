#include <iostream>
#include <string>

using namespace std;

struct bixo_t {
	string nome;
	int idade;
};

int main ()
{
	bixo_t totoh;
	bixo_t *xaninho;
	
	xaninho = new bixo_t;
	
	totoh.nome = "totó";
	totoh.idade = 5;
	
	xaninho->nome = "xaninho";
	xaninho->idade = 2;
	
	cout << totoh.nome << endl;
	cout << xaninho->nome << endl;

	return 0;
}
