#include <iostream>
#include <string>

using namespace std; 

int main () 
{
	string *nome;
	int *idade;
	
	nome = new string;
	idade = new int;
	
	cin >> *nome;
	cin >> *idade;

	
	if (*idade >= 18)
		cout << *nome << " voce é maior de idade" << endl;
	else
		cout << *nome << " voce é menor de idade" << endl;
		
	return 0;
}
