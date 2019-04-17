
#include <iostream>
#include <list>
#include <iterator>
#include <string>

using namespace std;


struct cadastroCliente { 

    int id;
    string nome;
    string idade;

};
struct cadastroAcervo {
    int id;
    string nome;
    int preco;
    int qtde_estoque;
};

// está lista armazena os dados
list<cadastroCliente> listaCliente;
list<cadastroAcervo> listaAcervo:


void imprimirCliente(list<prod>& l){

  list<prod>::iterator i;

  cout << "\n------ Lista de Informações do Cliente ------" << endl;

  for(i = l.begin(); i != l.end(); i++)
    cout << i->id << " - "
    << i->nome << " - "
    << i->idade << " - "
    << endl;

}

void cadastrarCliene(){
    cadastroCliente cliente;

    cout << "Informe o codigo do Filme : ";
    cin >> cliente.id;
    cout << "Infomer o nome do Cliente : ";
    cin >> cliente.nome;
    cout << "Informe o CPF do Cliente: ";
    cin >> cliente.idade;
    cout << "";
    listaCliente.push_back(cliente);
}

void cadastrarAcervo(){
    cadastroAcervo acervo;

    cout << "Informe o codigo do Filme : ";
    cin >> acervo.id;
    cout << "Informe o nome do filme : ";
    cin >> acervo.nome;
    cout << "Informe o Preço do filme : ";
    cin >> acervo.preco;
    cout << "Informe a Quantidade de Estoque : ";
    cin >> acervo.qtde_estoque;
    listaAcervo.push_back(acervo);

}

int main ()
{
    string verificadorCliente;
    string verificadorAcervo;
    int opcao = 0;


    do{
        cout << "Deseja cadastrar algum Cliente? = 1 ";
        cout << "Deseja Excluir algum Cliente? = 1 ";
        cout << "Deseja Visualizar algum Cliente? = 1 ";
        cin >> opcao;
        cout << "" << endl;
        if(verificadorCliente == "1"){
            cadastrarCliente();
            opcao++;
        }else if(verificadorAcervo == "2"){
          cadastroAcervo();
          opcao++;
        }
    } while (verificador != 0);



    cout << "Saindo ....";

  return 0;
}
