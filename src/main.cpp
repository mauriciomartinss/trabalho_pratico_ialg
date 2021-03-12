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
         << "   > ";

    cin >> acao;
}
//comeco passar
void passar_Compra()
{
    compra compraAtual; //variavel que recebe tudo
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
         << "1- cartao" << endl
         << "2- dinheiro" << endl
         << "3- à prazo" << endl;
    cin >> pagamento;

    if (pagamento == 1)
    {
        cout << "1- à vista" << endl
             << "parcelado" << endl;
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
        //arquivo com lista de clientes;
        //  verifica_cliente();
        //  senao
        //  cadastrar_cliente();
    }
}

/*void exibir_clientes()
{
}

void cadastrar_cliente()
{
}
*/
void exibeHistorico(compra historico[])
{
    int i = 0;
    while (i < 10 and historico[i].id != 0)
    {
        cout << historico[i].id << endl
             << historico[i].clientes[i].id << " " << historico[i].clientes[i].saldoDevedor << endl
             << historico[i].pagamento << endl;
        i++;
    }
    cout << endl;
}

void verifica(int acao)
{
    if (acao == 1)
    {
        passar_Compra();
    }
    else if (acao == 2)
    {
        cout << "exibir_cliente" << endl;
        //exibir_Clientes();
    }
    else if (acao == 3)
    {
        cout << "cadastra cliente" << endl;
        //cadastrar_Cliente();
    }
    else if (acao == 4)
    {
        cout << "exibe historico"
             << " " << acao << endl;
        //exibeHistorico(historico);
    }
    else
    {
        //acho que assim eh melhor, se não for, depois muda :)
        cout << "[ERRO] digite um valor válido! (valores de 1 a 5). " << endl
             << endl;
    }
}

int main()
{
    int acao;
    bool sair = false;
    while (!sair)
    { //responsavel pelo menu
        menuSelecao(acao);
        if (acao == 5)
        {
            sair = true;
        }
        else
        {
            verifica(acao);
        }
    }
    return 0;
}