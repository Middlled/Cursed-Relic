#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

    cout << "Ola mundo!" << endl;

    int idade;
    double salario, altura;
    char genero;
    string nome;

    idade = 20;
    salario = 5800.5;
    altura = 1.63;
    genero = 'F';
    nome = "Maria Silva";

    cout << fixed << setprecision(2);
    cout << "Idade = " << idade << endl;
    cout << "Salario = " << salario << endl;
    cout << "Altura = " << altura << endl;
    cout << "Genero = " << genero << endl;
    cout << "Nome = " << nome << endl;
    cout << "A funcionaria " << nome << ", sexo " << genero << ", ganha " << salario << " e tem " << idade << " anos." << endl;



    return 0;
}