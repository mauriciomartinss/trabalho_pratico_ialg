#include <iostream>
#include <fstream>
#include <string>
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
    int valorCompras;
};
struct compra
{
    produto produtos[100];
    cliente clientes;
    string pagamento;
};

//void menuSelecao(int &acao)

void menuSelecao()
{
    cout << "Escolha uma acao (digite apenas o numero): " << endl
         << "   1- Passar Compras" << endl
         << "   2- Exibir clientes cadastrados" << endl
         << "   3- cadastrar cliente" << endl
         << "   4- sair" << endl
         << "   > ";
    // cin >> acao;
}

void passarCompra()
{
    compra compraAtual; //variavel que recebe tudo
    cliente cliente_atual;
    int i = 0, pagamento, pgtCartao, valorRecebido, troco;
    float valorTotal = 0;

    cout << "Informe a quantidade de um tipo de produto: ";

    cin >> compraAtual.produtos[0].qtd;

    if (compraAtual.produtos[0].qtd <= 0)
    {
        return;
    }
    else
    {
        while (compraAtual.produtos[i].qtd > 0)
        {
            cout << "nome do produto: ";
            cin >> compraAtual.produtos[i].nome;
            cout << endl
                 << "preco unitario: ";
            cin >> compraAtual.produtos[i].valor;

            valorTotal = valorTotal + (compraAtual.produtos[i].valor * compraAtual.produtos[i].qtd);

            cout << "Informe a quantidade do produto. Se nao deseja adicionar mais algum produto, digite 0: ";

            cin >> compraAtual.produtos[i + 1].qtd;

            i++;
        }
    }

    cout << "O valor total da compra é de " << valorTotal << "." << endl
         << "Qual a forma de pagamento? " << endl
         << "1- Cartao" << endl
         << "2- Dinheiro" << endl
         << "3- À prazo" << endl;
    cin >> pagamento;

    //  arquivo com lista de clientes;
    //  verifica_cliente();
    //  senao
    //  cadastrar_cliente();

    if (pagamento == 1)
    {
        cout << "1- À vista" << endl
             << "2- Parcelado" << endl;
        cin >> pgtCartao;

        if (pgtCartao == 1)
        {
            cout << "Confirmado";
        }
        else if (pgtCartao == 2)
        {
            cout << "quantas vezes?" << endl
                 << "Confirmado";
        }
    }
    else if (pagamento == 2)
    {
        cout << "valor recebido: ";
        cin >> valorRecebido;
        troco = valorRecebido - valorTotal;

        cout << endl
             << "troco: " << troco << endl;
    }
    else if (pagamento == 3)
    {
        //clienteAtual.saldoDevedor = clienteAtual.saldoDevedor+valorTotal;
    }
}

void interfaceCliente()
{
    cout << "   1- Cadastrar cliente" << endl
         << "   2- Excluir cliente" << endl
         << "   3- Alterar dado de cliente" << endl
         << "   4- Retornar ao menu principal" << endl
         << "   >";
}

void carregarClientes()
{
    ifstream cli("clientes.dat", ios::binary);
}

void cadastrarCliente(cliente &dados)
{
    cout << "nome: " << endl;
    cin >> dados.nome;
    cout << "cpf: " << endl;
    cin >> dados.cpf;
}

void quitarDivida()
{
}

void removerClientes()
{
}

void alterarCliente()
{
}

void exibirClientes()
{
    bool sair = false;
    int opcaoCliente;

    while (!sair)
    {
        interfaceCliente();
        cin >> opcaoCliente;
        if (opcaoCliente >= 1 and opcaoCliente <= 4)
        {
            if (opcaoCliente == 4)
            {
                sair = true;
            }
            else
            {
                if (opcaoCliente == 1)
                {
                    //cadastrarCliente();
                }
                else if (opcaoCliente == 2)
                {
                    //removerClientes();
                }
                else if (opcaoCliente == 3)
                {
                    //alterarCliente();
                }
            }
        }
        else
        {
            cout << "[ERRO] digite um valor valido! (valores de 1 a 4). " << endl;
            cin.clear();  //Limpa a flag de erro quando há falha no parse do valor entrado
            cin.ignore(); //Limpa o buffer
        }
    }
}

void verificar(int acao)
{

    if (acao == 1)
    {
        passarCompra();
    }
    else if (acao == 2)
    {
        exibirClientes();
    }
    else if (acao == 3)
    {

        // cadastrarCliente();
    }
    else
    {
        // quitarDivida();
    }
}

int main()
{
    int acao = 0;
    bool sair = false;

    while (!sair)
    {
        menuSelecao();
        cin >> acao;
        cout << acao << endl;
        if (acao >= 1 and acao <= 5)
        {
            if (acao == 5)
            {
                sair = true;
            }
            else
            {
                verificar(acao);
            }
        }
        else
        {
            cout << "[ERRO] digite um valor valido! (valores de 1 a 5). " << endl;
            cin.clear();  //Limpa a flag de erro quando há falha no parse do valor entrado
            cin.ignore(); //Limpa o buffer
        }

    } //fim do while

    return 0;
}