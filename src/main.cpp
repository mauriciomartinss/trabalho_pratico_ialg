#include <iostream>
using namespace std;
//Hélio Henrique Medeiros Silva and Maurício Martins Damasceno;

struct produto
{
    string nome;
    int qtd;
    float valor;
};
struct cliente
{
    string nome;
    int cpf;
    int saldoDevedor;
    int id;
};
struct cartao
{
    int n;
    string nome;
    int cvv;
};

struct compra
{
    int id;
    produto produtos[100];
    cliente clientes[100];
    string pagamento;
};

void menuSelecao(int &acao)
{
    cout << "Escolha uma acao (digite apenas o numero): " << endl
         << "   1- Passar Compras" << endl
         << "   2- Exibir clientes cadastrados" << endl
         << "   3- cadastrar cliente" << endl
         << "   4- historico de compras" << endl
         << "   5- sair" << endl
         << "   >";

    cin >> acao;
}

int passar_Compra()
{
    compra compraAtual; //variavel que recebe tudo
    int i = 0;
    float valorTotal = 0;
    cout << "Informe a quantidade de um tipo de produto.  "
         << "Se nao deseja adicionar mais produto, digite 0";
    cin >> compraAtual.produtos[0].qtd;

    if (compraAtual.produtos[0].qtd <= 0)
    {
        //encerra a função;
    }
    else
    {
        while (compraAtual.produtos[i].qtd >= 0)
        {
            cout << "nome do produto: ";
            cin >> compraAtual.produtos[i].nome;
            cout << endl
                 << "preco unitario: ";
            cin >> compraAtual.produtos[i].valor;

            valorTotal = valorTotal + (compraAtual.produtos[i].valor * compraAtual.produtos[i].qtd);

            cout << "Informe a quantidade do produto. Se nao deseja adicionar mais algum produto, digite 0";

            cin >> compraAtual.produtos[i + 1].qtd;

            i++;
        }
    }

    cout << "O valor total da compra é de " << valorTotal << "." << endl
         <<
        //carrega as opcoes de pagamento disponiveis e faz um switch ou if para a resposta do usuario
        endl;

    int teste = 0;
    return teste;
}

void exibir_Clientes()
{
}

void cadastrar_Cliente()
{
}

void exibeHistorico(compra historico[])
{
    /*int i = 0;
    while (i < 10 and historico[i].id != 0)
    {
        cout << historico[i].id << endl
             << historico[i].clientes[i].id << " " << historico[i].clientes[i].saldoDevedor << endl
             << historico[i].pagamento << endl;
        i++;
    }
    cout << endl;*/
}

int main()
{
    compra historico[10]; //o histórico já tava definido que seria no máximo dez, né?

    int acao = 0;

    menuSelecao(acao);

    while (acao >= 1 and acao < 5) //tem que arrumar depois
    {
        menuSelecao(acao);
        if (acao == 1)
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
        else if (acao == 4)
        {
            exibeHistorico(historico);
        }
        else
        {
            menuSelecao(acao);
            cout << "[ERRO] digite um valor válido! (valores de 1 a 5). " << endl
                 << endl;
        }
    }

    return 0;
}