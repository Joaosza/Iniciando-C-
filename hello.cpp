#include<iostream>

//Comentario otario

using namespace std;

int main()
{

  int i;
  string s;
  cout << "Informe seu nome";
  getline(cin,s);


  cout << " Informe a sua idade " << s <<endl;
  cin >>i;

  if(i>=18){
    cout << s << " Maior de idade " <<endl;
  }else{
    cout << " Menor de idade" << s <<endl;
  }

  for(int i = 0; i <10; i++){
    std::cout << i+1 <<endl;
  }

  return 0;

}
