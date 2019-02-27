#include <iostream>
#include <string>

using namespace std;

int main()
{
  string * nome;
  int * idade;

  nome = new string;
  idade = new int;

  cin >> *nome;
  cin >> *idade;

  if(*idade >= 18)
    cout << *nome << "Maior de Idade" << endl;
  else
    cout << *nome << "Maior de Idade"  << endl;

  return 0;
}
