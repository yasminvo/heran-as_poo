#include <iostream>
using namespace std;

class Conta{
    
    public:
      Conta(double saldo = 0);
      ~Conta ();
      void setSaldo(double vsaldo);
      double getSaldo () const;
      double getCadastro() const;
      void debitar (double valor);
      void creditar (double valor);
      void imprime ();


    private:
       const int cadastro;
       double saldo;   
       static int contador;
};

int Conta::contador = 0;

Conta::Conta (double vsaldo):cadastro(++contador){
     if (vsaldo>0)
      saldo = vsaldo;
}

Conta::~Conta(){

}

void Conta::setSaldo (double vsaldo){
    if (vsaldo>0)
      saldo = vsaldo;
}

double Conta::getSaldo () const{
    return saldo;
}

double Conta::getCadastro () const{
    return cadastro;
}

void Conta::debitar(double valor){
    if (valor>0 && saldo>valor)
     saldo = saldo - valor;
    
}

void Conta::creditar(double valor){
    if (valor>0)
     saldo = saldo + valor;
    
}

void Conta::imprime() const{
    cout << "Conta:" << getCadastro() << endl;
    cout << "Saldo:" << getSaldo() << endl;

}

class Poupanca : public Conta {

    public: 
      Poupanca (double saldo = 0, double porcent = 0);
      ~Poupanca ();
      double getJuros () const;
      double getPorcent () const;
      void setPorcent (double vporcent);
      void setJuros ();
      void imprime() const;  

    private:
      double porcent; //porcentagem de taxa de juros
      double juros;
};

Poupanca::Poupanca(double vsaldo, double vporcent) : Conta(vsaldo){

      setPorcent (vporcent);
      setJuros();

}

Poupanca::~Poupanca(){

}

void Poupanca::setPorcent(double vporcent){
    if (vporcent>=0)
        porcent = vporcent;
}

void Poupanca::setJuros(){
    
    juros = getSaldo()*getPorcent();
}

double Poupanca::getPorcent() const{
    return porcent;
}

double Poupanca::getJuros() const{
    return juros;
}

void Poupanca::imprime () const {
    Conta::imprime ();
    cout << "Juros = " << getJuros() << endl;

}

class contaCorrente : public Conta {
    public: 
      contaCorrente (int saldo = 0, double taxa = 0);
      ~contaCorrente();
      double getTaxa() const;
      void setTaxa(double vtaxa);
      void debitar(double valor);
      void creditar(double valor);
      void imprime () const;

    private:
      double taxa;
};

contaCorrente::contaCorrente (int vsaldo, double vtaxa): Conta (vsaldo){
    setTaxa(vtaxa);

}

contaCorrente::~contaCorrente(){

}

void contaCorrente::setTaxa(double vtaxa){
    if (vtaxa>0)
      taxa = vtaxa;
}

double contaCorrente::getTaxa() const{
    return taxa;
}
void contaCorrente::debitar (double valor){

  Conta::debitar(valor);
  setSaldo(getSaldo() - 2);    

}

void contaCorrente::creditar (double valor){

  Conta::creditar(valor);
  setSaldo(getSaldo() - 2);


}

void contaCorrente::imprime() const{
    Conta::imprime();
}

int main(){

Conta c1(2000);
c1.imprime();

cout << endl; 

Poupanca p1(2000, 0.2);
p1.imprime();

cout << endl; 

contaCorrente cc1 (2000, 2);
cc1.imprime();
cc1.creditar(200);
cc1.imprime();
cout << endl; 



}
