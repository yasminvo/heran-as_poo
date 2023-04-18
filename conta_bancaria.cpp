#include <iostream>
#include <math.h>
using namespace std;


class Conta {

    public:
        Conta(int _saldo = 0);
        ~Conta();
        void Debita(int valor_debitado);
        void Credita(int valor_creditado);
        int getSaldo() const;
        void setSaldo(int _saldo);



    private:
        int saldo;
        static int contador;


};

int Conta::contador = 0;

Conta::Conta(int _saldo) {
    if (_saldo>=0) {
        saldo = _saldo;
    }
    contador++;
    cout << "Conta: " << contador << endl;
    cout << "Saldo: " << saldo << endl;
    
}
Conta::~Conta() {
    cout << "A classe foi destruída com sucesso." << endl;
}

void Conta::Debita(int valor_debitado) {
    if (valor_debitado>=0) {
        saldo -= valor_debitado;
    }   
}
void Conta::Credita(int valor_creditado) {
    if (valor_creditado>=0) {
        saldo += valor_creditado;
    }
}

int Conta::getSaldo() const {
    return saldo;
}

void Conta::setSaldo(int _saldo) {
    if (_saldo>=0) {
        saldo = _saldo;
    }
}


class Poupanca : public Conta {

    public:
        Poupanca(int _saldo = 0, int _juros = 0);
        ~Poupanca();
        int getJurosAuferidos(int n_meses) const;



    private:
        int juros;

};

Poupanca::Poupanca( int _saldo, int _juros) : Conta(_saldo) {
    juros = _juros;
    cout << "Poupança com juros: " << juros << endl;
}

Poupanca::~Poupanca() {
    cout << "Classe destruída com sucesso." << endl;
}

int Poupanca::getJurosAuferidos(int n_meses) const {
    return pow(juros,n_meses);
}

class ContaCorrente : public Conta {

    public:
        ContaCorrente(int _saldo = 0, int _taxa = 0);
        ~ContaCorrente();
        int Debitar(int valor_debitado);
        int Creditar(int valor_creditado);
        void print() const;


    private:
        int taxa;
};

ContaCorrente::ContaCorrente(int _saldo, int _taxa):Conta(_saldo) {
    taxa = _taxa;
    cout << "A  taxa cobrada por transações em conta corrente é: " << taxa << endl;
}

ContaCorrente::~ContaCorrente() {
    cout << "A classe ContaCorrente foi destruída com sucesso." << endl;
}

int ContaCorrente::Debitar(int valor_debitado) {
    int _saldo;
    _saldo = getSaldo();
    _saldo -= valor_debitado;
    return _saldo;
}
int ContaCorrente::Creditar(int valor_creditado) {
    int _saldo;
    _saldo = getSaldo();
    _saldo -= valor_creditado;
    return _saldo;
}



int main() {
    Conta a1(1000);
    Poupanca b1(2000,2);
    ContaCorrente c1(3000,4);


    return 0;
}

