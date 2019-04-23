
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
list<Cliente> cliente;
list<Acervo> listaAcervo;
list<Locacao> listaLocacao;


// CLIENTE

void menuCliente(char mc){
  cout << " -> Menu clientes" << endl;
  cout << "1 - Adicionar cliente" << endl;
  cout << "2 - Alterar cliente" << endl;
  cout << "3 - Remover cliente" << endl;
  cout << "4 - Visualizar clientes" << endl;
  cout << "5 - Listar clientes" << endl;
  cin >> mc;

  if(mc == '1'){
    cadastroCliente(cliente);
  }else if(mc == '2'){
    alterarCliente(cliente);
  }else if(mc = '3'){
    excluirCliente(cliente);
  }else if(mc == '4'){
    imprimirCliente(cliente);
  }else if(mc == '5'){
    visualizaeCliente(cliente);
  }
}

int gerarCodigo(list<Cliente>& listaCliente){
  if(listaCliente.size() == 0) return 1;
  list<Cliente>::iterator i;
  int maior = 0;
  for(it = listaCliente.begin(); it != listaCliente.end(); i++){
    if(i->codigo > maior)maior = i->codigo;
  }
  return maior+1;
}


void imprimirCliente(list<Cliente>& listaCliente){

  list<Cliente>::iterator i;

  cout << "\n------ Lista de Informações do Cliente ------" << endl;

  for(i = l.begin(); i != l.end(); i++)
    cout << i->codigo << " - "
    << i->nome << " - "
    << i->idade << " - "
    << endl;

}

void cadastrarCliente(){
    Cliente cliente;

    cout << "Informe o codigo do Cliente : ";
    cliente.codigo = gerarCodigo(listaCliente);
    cout << "Infomer o nome do Cliente : ";
    cin >> cliente.nome;
    cout << "Informe o CPF do Cliente: ";
    cin >> cliente.idade;
    cout << "";
    listaCliente.push_back(cliente);
}

void excluirCliente(list<Cliente>& listaCliente){

    int codigo;
    list<Cliente>:: iterator i;

    std::cout << "Informe o codigo cliente a ser excluido : " << '\n';
    std::cin >> codigo;
    cout << endl;

    for(i = listaCliente.begin(); i != listaCliente.end(); i++){
      if(i->codigo == codigo){
        listaCliente.erase(i);
        break;
      }
    }

    std::cout << "Cliente Removido" << '\n';

}

void alterarCliente(list<Cliente>& listaCliente){

    int codigo;
    char c;
    list<Cliente>::iterator i;

    std::cout << "Informe o codigo do cliente a ser alterado : " << '\n';
    std::cin >> codigo;
    cout << endl;

    for(i = listaCliente.begin(); i != listaCliente.end(); i++){
      if(i->codigo == codigo){
    cout << it->codigo << " - "
        << i->nome << " - "
        << i->idade << " - "
        << endl;


        while(c != '0'){

          cout << "Selecione uma das opções abaixo:" << endl;
          cout << "1 - Alterar nome" << endl;
          cout << "2 - Alterar idade" << endl;
          cout << "0 - Finalizar alteração" << endl;
          cin >> c;

          if(c == '1'){
            cout << "Informe o novo Nome : " << '\n';
            cin.ignore();// limpa o caracter
            get.line(cin, i->nome);
          }else if(c == '2'){
            cout << "Informe a nova Idade" << '\n';
            cin.ignore();
            get.line(cin, i->idade);
          }else if(c == '0'){
            cout << "Alteração concluida" << endl;
            cout << i->codigo << " - "
                << i->nome << " - "
                << i->idade << endl;
          }
        }
        break
      }
    }

}


// ACERVO

void cadastrarAcervo(){
    Acervo acervo;

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
        cout << "Sair";
        cout << "Menu Cliente = 1";
        cout << "Menu Acervo = 2";
        cin >> opcao;
        cout << "" << endl;
        if(verificadorCliente == "1"){
            menuCliente();
            opcao++;
        }else if(verificadorAcervo == "2"){
          cadastroAcervo();
          opcao++;
        }
    } while (verificador != 0);



    cout << "Saindo ....";

  return 0;
}
