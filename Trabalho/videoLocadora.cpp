#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <ctype.h>

#include <string.h>

#define TAM 30

struct ficha

{

int codigo;

char filme[TAM];

float duracao;

char categoria[TAM];

char status;

int ativo;

};

struct ficha dados;

FILE *arq;

char resp;

void AbrirArquivo(char filme[])

{

system("cls");

arq = fopen(filme, "rb+"); // associa ao arq fisico e, se arquivo nao existe, deve ser criado, rb = somente para leitura

if (arq == NULL) puts("NULL");

if (arq == NULL)

arq = fopen(filme, "wb+");// abre o arquivo depois - rb = escrita a partir do início do arquivo

puts("ARQUIVO ABERTO.");

//sleep(3000);

}

void FecharArquivo() {

system("cls");

fclose(arq);

puts("ARQUIVO FECHADO.");

//sleep(3000);

}

//Registra o filme no banco de dados

void RegistrarFilme() {

char opcao;

do {

//Faz inclusão dos dados para registra o filme

system("cls");

fseek(arq,0,SEEK_END); // procura de uma certa posição do arquivo - arq, 0 = qtd bytes para deslocamento do cursor

//seek_end - começa do final para o início

puts("** INCLUSAO DE FILME ***\n");

printf("Codigo ......:");

fflush(stdin);

scanf("%d",&dados.codigo);

printf("Filme ..:");

fflush(stdin);

gets(dados.filme);

printf("Duracao do filme..:");

fflush(stdin);

scanf("%f",&dados.duracao);

printf("Categoria..:");

fflush(stdin);

gets(dados.categoria);

printf("Status..:");

puts("D = Disponivel");

puts("L = Locado");

fflush(stdin);

dados.status = toupper(getchar());

if((dados.filme == "") || (dados.filme == NULL))// tratamento para nome em branco não funciona no dev C++

{

puts("REGISTRO RESTRINGIDO DEVIDO A DADOS ERRADOS INSERIDOS");

puts("Deixou o campo FILME em branco");

puts("Os dados nao foram registrados no sistema");

}

else if(dados.codigo == NULL)//tratamento para codigo em branco não funciona para no dev C++

{

puts("REGISTRO RESTRINGIDO DEVIDO A DADOS ERRADOS INSERIDOS");

puts("Deixou o campo FILME em branco");

puts("Os dados nao foram registrados no sistema");

}

//Tratamento do status, restringe o usuário a colocar diferente de D ou L

else if((dados.status == 'D') || (dados.status == 'L') /*&& (dados.filme != NULL) || (dados.codigo != NULL)*/)

{

dados.ativo = 1;// Ativo = 1 quer dizer que existe, por que na função de exclusão, usaremos exclusão lógica colocando ativo = 0

fwrite(&dados,sizeof(struct ficha),1,arq);// escreve todos os dados no arquivo

}

else

{

puts("REGISTRO RESTRINGIDO DEVIDO A DADOS ERRADOS INSERIDOS");

puts("Ou você inseriu Status digitado errado, Somente digite D = disponivel ou L = locado");

puts("Deixou alguns dos campos em branco");

puts("Os dados nao foram registrados no sistema");

}

// se for errado o status, ele não registra os dados e dá a opcao de fazer uma nova inclusão

if (ferror(arq))

puts("ERRO!!");

printf("\nDESEJA INCLUIR OUTRO FILME <S/N>? ");

fflush(stdin);

opcao = toupper(getchar());

} //fim primeiro Do

while (opcao == 'S');

}

//Busca filme pelo código e exibe seu status se está locado ou não

int Buscar(int codigo)

{

int nreg = -1;

rewind(arq); //posiciona na primeira estrutura do arquivo

fread(&dados,sizeof(struct ficha),1,arq);//&dados aponta a estrutura a ser lida

//sizeof()o tamanho do arquivo, 1 quantidade de buscas, arq = arquivo

if (!ferror(arq))// se não retorna erro se der erro, entra no if

while (!feof(arq))//feof informa se chegou ao fim do arquivo, se for diferente entra no while

{

nreg++;

if ((dados.codigo) == codigo) // compara se o filme digitado tem na lista, se tem ele busca, ao invés de usar == tem que usar =

return(nreg);

fread(&dados,sizeof(struct ficha),1,arq); //fread, retorna um número inteiro correspondente a quantidade de bytes lidos

}

else

puts("ERROR!!");

return(-1);

}

int BuscarPalavra(char categoria[TAM])// função de busca para buscar filme por categoria

{

int nreg = -1;

rewind(arq); //posiciona na primeira estrutura do arquivo

fread(&dados,sizeof(struct ficha),1,arq);//&dados aponta a estrutura a ser lida

//sizeof()o tamanho do arquivo, 1 quantidade de buscas, arq = arquivo

if (!ferror(arq))// se não retorna erro se der erro, entra no if

while (!feof(arq))//feof informa se chegou ao fim do arquivo, se for diferente entra no while

{

nreg++;

if (strcmp(dados.categoria, categoria) == 0) // compara se o filme digitado tem na lista, se tem ele busca, ao invés de usar == tem que usar =

return(nreg);

fread(&dados,sizeof(struct ficha),1,arq); //executa a leitura do arquivo

}

else

puts("ERROR!!");

return(-1);

}

void Locar() {

int codigo;

int nreg;

system("cls");

puts("** LOCAR FILME ***\n");

printf("Digite o codigo do filme para registrar a locacao ......:");

fflush(stdin);

scanf("%d",&codigo);

nreg = Buscar(codigo);

if ( nreg >=0 ) // se a busca for maior do que 0 ele achou e apresentará os dados achados e mudará o status automaticamente

{

if(dados.status != 'L')

{

//printf("num %d\n",nreg);

printf("Status ..: %c\n",dados.status);
a
fflush(stdin);

dados.status = 'L';

printf("Novo Status..= %c: \n", dados.status);

puts("Status L = locado\n");

// Posiciona novamente o cursor sobre o registro desejado.

fseek(arq,sizeof(struct ficha) * nreg, SEEK_SET);//seek_set começa da posição corrente

fwrite(&dados, sizeof(dados), 1, arq);//escreve os novos dados no arquivo

if (!ferror(arq))//se não der erro

{

puts("");

puts("LOCACAO REALIZADA");

}

else

{

puts("ERROR!!");

}

}//fim if que filtra se nao esta locado

else

{

puts("");

puts("Filme ja se encontra em status L = Locado");

puts("Clique em enter para voltar ao menu principal");

}

system("pause");

}

else

puts("FILME NAO ESTA CADASTRADO OU NAO ESTA DISPONIVEL");

fflush(stdin);

getchar();

}

void DevolucaoFilme() {

int codigo;

int nreg;

system("cls");

puts("** DEVOLUCAO DO FILME ***\n");

printf("Digite o codigo do filme para registar a devolucao......:");

fflush(stdin);

scanf("%d",&codigo);

nreg = Buscar(codigo);

if ( nreg >=0 ) //if principal de busca se tem na lista o codigo digitado

{

if(dados.status != 'D')

{//if que filtra quem nao esta disponivel para devolver

//printf("num %d\n",nreg);

printf("Status ..: %c\n",dados.status);

fflush(stdin);

dados.status = 'D';

printf("Novo Status..: %c -> Disponivel\n", dados.status);

puts("");

// Posiciona novamente o cursor sobre o registro desejado.

fseek(arq,sizeof(struct ficha) * nreg, SEEK_SET);// seek_set procura da posição corrente o cursor

fwrite(&dados, sizeof(dados), 1, arq);

if (!ferror(arq))

{

puts("DEVOLUCAO REALIZADA");

}

else

{

puts("ERROR!!");

}

}//fim if que filtra que nao esta devolvido para mudar o status

else

{

puts("");

puts("Filme ja se encontra em status D = Disponivel ou Devolvido");

puts("Clique em enter para voltar ao menu principal");

}

system("pause");

}//fim if principal de busca se tem na lista o codigo digitado

else

{

puts("FILME NAO ESTA CADASTRADO OU NAO ESTA DISPONIVEL");

fflush(stdin);

getchar();

}

}

void ExcluirFilme() {

char opcao;

int codigo;

int nreg;

system("cls");

puts("** EXCLUSAO DE FILME ***");

printf("Codigo do filme......:");

fflush(stdin);

scanf("%d",&codigo);

nreg = Buscar(codigo);

if ( nreg >=0 ) {

printf("num %d\n",nreg);

printf("Nome do filme..: %s\n",dados.filme);

printf("CONFIRMA EXCLUSAO DO FILME <S/N>?");

fflush(stdin);

opcao = toupper(getchar());

if (opcao == 'S') {

fseek(arq,sizeof(struct ficha) * nreg, SEEK_SET);//procura os dados da posição corrente (seek_set)

// Exclusão Lógica

dados.ativo = 0;// quando ativo = 0, ele é excluído logicamente

fwrite(&dados, sizeof(dados), 1, arq);//registra novos dados

if (!ferror(arq))

puts("FILME EXCLUIDO.");

else

puts("ERRO!!");

}

}

else

puts("FILME NAO ENCONTRADO.");

fflush(stdin);

getchar();

}

void ConsultarFilme(){

int codigo;

int nreg;

system("cls");

puts("** CONSULTA DE FILMES ***\n");

printf("Codigo do Filme ......:");

fflush(stdin);

scanf("%d",&codigo);

nreg = Buscar(codigo);

if ( nreg >= 0 ) // se não atingou -1, ele achou um codigo correspondente, e imprimirá o conteúdo, usado pelo função buscar

{

if(dados.status == 'D')

{

printf("num %d\n",nreg);

printf("Codigo: %d\n Filme ..: %s\n Categoria: %s\n Duracao: %.2f Hs \n Status: %c -> Disponivel\n", dados.codigo, dados.filme, dados.categoria, dados.duracao, dados.status);

}

else

{

printf("num %d\n",nreg);

printf("Codigo: %d\n Filme ..: %s\n Categoria: %s\n Duracao: %.2f Hs \n Status: %c -> Locado\n", dados.codigo, dados.filme, dados.categoria, dados.duracao, dados.status);

}

}

else

puts("FILME NAO ENCONTRADO.");

fflush(stdin);

getchar();

}

void listarCategorias()

{

//Funcao que mostra categorias, sendo usadas como funcao estava dando erro, logo colocamos todo o codigo aqui dentro da funcao ListarFilmeCategoria

rewind(arq); //posiciona na primeira linha do arquivo // inicia funcao mostra categoria

fread(&dados,sizeof(struct ficha),1,arq); //le os dados

puts("Categorias registradas para fazer a busca");

puts("");

if (!ferror(arq)) //se não der erro pela função ferror

while (!feof(arq)) //feof informa se chegou ao fim do arquivo, se for diferente entra continua no loop do while

{

if (dados.ativo)// o if identifica se o valor é verdadeiro automaticamente que é 1, se 1 ele existe, se 0,

//não existe, na função de exclusão, ter filmes que estarão com ativo = 0 e não aparecerão na listagem

printf("%s \n",dados.categoria);

fread(&dados,sizeof(struct ficha),1,arq); //le os dados selecionados

}

else

{

puts("ERROR!!");

fflush(stdin);

getchar();

}

puts("");

//Fim funcao mostra categorias

}

void ListarFilme()

{

system("cls");

puts("***** LISTA DE FILMES*****\n");

rewind(arq); //posiciona na primeira linha do arquivo

fread(&dados,sizeof(struct ficha),1,arq); //le os dados

if (!ferror(arq)) //se não der erro pela função ferror

while (!feof(arq)) //feof informa se chegou ao fim do arquivo, se for diferente entra continua no loop do while

{

if (dados.ativo)// o if identifica se o valor é verdadeiro automaticamente que é 1, se 1 ele existe, se 0,

//não existe, na função de exclusão, ter filmes que estarão com ativo = 0 e não aparecerão na listagem

printf("Codigo: %d \n Filme: %s: \n Duracao: %.2lf hs\n Categoria: %s\n Status: %c\n Ativo: %d \n\n",dados.codigo,dados.filme,dados.duracao,dados.categoria,dados.status,dados.ativo);

fread(&dados,sizeof(struct ficha),1,arq); //le os dados selecionados

}

else

puts("ERROR!!");

fflush(stdin);

getchar();

}

void ListarFilmeCategoria()

{

char categoria[TAM];// variavel categoria para comparar durante a busca e imprimir caso seja condizente

system("cls");//limpa a tela do menu

puts("***** LISTA DE FILMES POR CATEGORIA*****\n");

// listarCategorias();

listarCategorias();//Funcao lista categorias registradas para facilitar a busca

puts("Digite a categoria de filmes");

scanf("%s",&categoria);

rewind(arq); //posiciona na primeira linha do arquivo, para começar a busca do começo

fread(&dados,sizeof(struct ficha),1,arq);

if (!ferror(arq)) // se for diferente de erro da função ferror

while (!feof(arq)) //feof informa se chegou ao fim do arquivo, se for diferente entra continua no loop do while

{

if (strcmp(dados.categoria, categoria) == 0)// comparando pelo strcmp se for igual, imprime os dados da struct que o cursor está buscando dados

printf("Codigo: %d \n Filme: %s: \n Duracao: %.2lf hs\n Categoria: %s\n Status: %c\n Ativo: %d \n\n",dados.codigo,dados.filme,dados.duracao,dados.categoria,dados.status,dados.ativo);

fread(&dados,sizeof(struct ficha),1,arq); //fread, retorna um número inteiro correspondente a quantidade de bytes lidos

}

else

puts("ERROR!!");

fflush(stdin);

getchar();

}

void Menu() {

system("cls");

puts("***** PROGRAMA DE CONTROLE DE LOCADORA *****\n");

puts("1. Inclusao Filmes");

puts("2. Consulta Filmes por codigo");

puts("3. Locar um Filme.");

puts("4. Devolver um Filme.");

puts("5. Excluir Filme");

puts("6. Listar Filmes");

puts("7. Listar Filmes por categoria");

puts("0. Sair\n");

}

void opções() {

int opcao;

do {

Menu();

printf("Selecione uma opcao: ");

scanf("%d", &opcao);

switch(opcao)

//usando switch case, chamamos as funções de acordo com as opções escolhidas

{

case 1: RegistrarFilme(); break;

case 2: ConsultarFilme(); break;

case 3: Locar(); break;

case 4: DevolucaoFilme(); break;

case 5: ExcluirFilme(); break;

case 6: ListarFilme(); break;

case 7: ListarFilmeCategoria(); break;

case 0: puts("Programa finalizado"); break;

default:

puts("Opcao Invalida");

}

} while (opcao != 0);

//sleep(3000);

}

/*

AbrirArquivo(char filme[])

FecharArquivo()

RegistrarFilme()

Buscar(int codigo)

AlterarStatus()

DevolucaoFilme()

ExcluirFilme()

ListarFilme()

*/

main()

{

system("cls");

AbrirArquivo("FILMES.DAT");//dentro da função AbrirArquivo colocaremos o nome do arquivo, no caso foi FILMES.DAT e deve ter a extensão .DAT

opções();

FecharArquivo();

system("pause");

}
