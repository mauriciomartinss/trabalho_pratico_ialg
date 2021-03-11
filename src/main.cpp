#include <iostream>
using namespace std;
//usei o pseudo código pra criar preencher os "objetos", mas acho que ao longo desenvolvimento vai precisar mudar kkkk
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
    produto produtos[];
    cliente clientes[100];
    string pagamento;
};

int menu_selecao()
{
    int acao;
    cout << "Escolha uma acao (digite apenas o numero): " << endl
         << "   1- Passar Compras" << endl
         << "   2- Exibir clientes cadastrados" << endl
         << "   3- cadastrar cliente" << endl
         << "   4- historico de compras" << endl
         << "   5- sair" << endl
         << "   >";
    cin >> acao;
    cout << endl;

    return acao;
}

int passar_Compra(compra historico[])
{
    compra compraAtual; //variavel que recebe tudo
    int i = 0;
    float valorTotal = 0;

    /*while (compraAtual.produto[i].qtd != 0)
    {
        cin >> compraAtual.id;
        while (compraAtual.produtos[i].qtd != 0)
        {
            cin >> compraAtual.produtos[i].qtd;
            if (compraAtual.produtos[i].qtd != 0)
            {
                cin >> compraAtual.produtos[i].valor;
            }
            cin >> compraAtual.pagamento; //nao terminei ainda, fiz algumas modificoes em duas estruturas
        }
        i++;
    }*/

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

            cout << compraAtual.produtos[i + 1].qtd << "Se nao deseja adicionar mais algum produto, digite 0";

            i++;
        }
    }

    cout << "O valor total da compra é de " << valorTotal << "." << endl
         <<
         //carrega as opcoes de pagamento disponiveis e faz um switch ou if para a resposta do usuario
         << endl;

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

int main()
{
    compra historico[10]; //o histórico já tava definido que seria no máximo dez, né?

    int acao;
    /*  mudei pra menu selecao (antes era exibir acoes) pq, além de mostrar as acoes, ele também retorna 
        um inteiro que recebeu de entrada como acao. daí achei que seria melhor mudar o nome. mas eu acho que
        a gente pode melhorar ainda mais esses nomes hueuheuheuhuhe
    */
    bool sair = false;
    while (!sair)
    {
        acao = menu_selecao();

        if (acao == 1) //Hélio: acho que seria melhor usar switch;
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
        else if (acao == 5)
        {
            sair = true;
        }
        else
        { //acho que assim eh melhor, se não for, depois muda :)
            cout << "[ERRO] digite um valor válido! (valores de 1 a 5). " << endl
                 << endl;
        }
    }

    return 0;
}