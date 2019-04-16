
#include <iostream>
#include <list>
#include <iterator>
#include <string>

using namespace std;


struct cadastroCliente { //struct esta as variaveis dos dados do cliente
    int id;
    string nome;
    string cpf;
    string rg;
    int qtde_comprado;
};
struct cadastroAcervo { //struct esta as variaveis dos dados do Acervo
    int id;
    string nome;
    string cpf;
    string rg;
    string endereco;
    string telefone;
    int qtde;
};



list<cadastroCliente> listainformacoes; // está lista armazena os dados do produto


void mostrarResultado(list<prod>& l){

  list<prod>::iterator i;

  cout << "\n------ Lista de Informações do Cliente ------" << endl;

  for(i = l.begin(); i != l.end(); i++)
    cout << i->id << " - "
    << i->nome << " - "
    << i->cpf << " - "
    << i->rg << " - "
    << i->qtde_comprado << " - "
    
    << endl;


}

void cadastrar(){
    cadastroCliente cliente;

    cout << "insira o codigo do produto: ";
    cin >> produto.id;
    cout << "insira o nome do produto: ";
    cin >> produto.nome;
    cout << "insira o preço do produto: ";
    cin >> produto.preco;
    cout << "insira a quantidade do produto: ";
    cin >> produto.qtde;
    cout << "";
    listainformacoes.push_back(produto);
}

int main ()
{
    string verificador;//
    int cont = 0;

    do{
        cout << "Deseja cadastrar algum Cliente?: ";
        cin >> verificador;
        cout << "" << endl;
        if(verificador == "sim"){
            cadastrar();
            cont++;
        }
    } while (verificador == "sim");

    if(cont > 0)
        imprimir(listainformacoes);

    cout << "Saindo ....";

  return 0;
}
