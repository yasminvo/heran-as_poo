#include <iostream>
using namespace std;


class Conta {

    public:
        Conta(float _saldo = 0);
        ~Conta();
        void Debitar(float x);
        void Creditar(float x);
        void PrintConta() const;
        float GetSaldo() const;
        void SetSaldo(float _saldo);


    private:
        float saldo;


};

Conta::Conta(float _saldo) {
    SetSaldo(_saldo);
}
Conta::~Conta() {
    cout << "A classe conta foi destruída" << endl;
}
void Conta::Creditar(float x) {
    saldo += x;
}
void Conta::Debitar(float x) {
    saldo -= x;
}
void Conta::PrintConta() const {
    cout << "Saldo: " << saldo << endl;
}
float Conta::GetSaldo() const {
    return saldo;
}
void Conta::SetSaldo(float _saldo) {
    saldo = _saldo;
}

class Poupanca : public Conta {

    public:
        Poupanca(float _saldo, float _juros = 1);
        ~Poupanca();
        float Get_Juros_Auferidos();
        void PrintPoupanca();

    private:
        float juros;

};

Poupanca::Poupanca(float _saldo, float _juros):Conta(_saldo) {
    juros = _juros;
}
Poupanca::~Poupanca() {
    cout << "A classe Poupança foi destruída" << endl;
}
float Poupanca::Get_Juros_Auferidos() {
    return GetSaldo()*juros/100;
}
void Poupanca::PrintPoupanca() {
    cout << "Juros: " << juros << endl;
    cout << "Juros aplicados no saldo: " << Poupanca::Get_Juros_Auferidos() << endl;
}

class ContaCorrente : public Conta {

    public:
        ContaCorrente(float _saldo, float _taxa = 0);
        ~ContaCorrente();
        void Debitar_ContaCorrente();
        void Creditar_ContaCorrente();
        void PrintContaCorrente() const;

    private:
        float taxa;

};

ContaCorrente::ContaCorrente(float _saldo,float _taxa):Conta(_saldo) {
    taxa = _taxa;
}
ContaCorrente::~ContaCorrente() {
    cout << "A classe ContaCorrente foi destruída" << endl;
}
void ContaCorrente::Creditar_ContaCorrente() {
    float saldo_atual;
    saldo_atual = GetSaldo() + taxa;
    SetSaldo(saldo_atual);
}
void ContaCorrente::Debitar_ContaCorrente() {
    float saldo_atual;
    saldo_atual = GetSaldo() - taxa;
    SetSaldo(saldo_atual);
}
void ContaCorrente::PrintContaCorrente() const {
    cout << "Taxa: " << taxa << endl;
}

int main() {
    
    Poupanca yasmin(1300,10);

    yasmin.PrintConta();
    yasmin.PrintPoupanca();

    ContaCorrente victoria(2000,200);
    victoria.PrintConta();
    victoria.PrintContaCorrente();
    victoria.Creditar_ContaCorrente();
    victoria.PrintConta();
    victoria.Debitar_ContaCorrente();
    victoria.PrintConta();   




    return 0;
}

