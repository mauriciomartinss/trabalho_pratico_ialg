#include <iostream>
using namespace std;

int exibir_Acoes()
{
    int acao;

    cout << "1- Passar Compras" << endl
         << "2- Exibir clientes cadastrados" << endl
         << "3- cadastrar cliente" << endl
         << "4-historico de compras" << endl;

    cin >> acao;

    return acao;
}

int passar_Compra()
{
}

void exibir_Clientes()
{
}

void cadastrar_Cliente()
{
}

void historico()
{
}

int main()
{

    int acao = exibir_Acoes();

    if (acao < 1 or acao > 4)
    {
        cout << "Insira um valor valido" << endl;
    }
    else if (acao == 1)
    {
        passar_Compra();
    }
    else if (acao == 2)
    {
        exibir_Clientes();
    }
    else if (acao == 3)
    {
        cadastrar_Cliente();
    }
    else
    {
        historico();
    }

    return 0;
}