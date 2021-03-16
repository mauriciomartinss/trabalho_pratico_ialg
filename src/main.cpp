#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
//Hélio Henrique Medeiros Silva and Maurício Martins Damasceno;

struct cliente
{
    string nome;
    int cpf;
    float saldoDevedor;
    float valorCompras;
    
};

// ######################
// aqui eu só coloquei a estrutura (copiei do slide de buscas). a gente tem que ver como 
// vai procurar em um arquivo
bool busca(cliente* clientes, int cpfCliente, int &posicaoCliente) {
//     int K, N = 10; precisa implementar com o arquivo depois
//     int V[N];
//     int i, posicao = -1;
//     for (i = 0; i < N; i++) cin >> V[i];
//     cin >> K;
//     while ((i < N) and (V[i] < K))
//    	 i++;
//     if ((i != N) and (V[i] == K)) {
//    	 posicao = i;
    //    } else {
    //        return false
    //    }
    return true;
}

void cadastrarCliente(cliente &dados)
{
    cout << "nome: " << endl;
    cin >> dados.nome;
    cout << "cpf: " << endl;
    cin >> dados.cpf;
    dados.saldoDevedor = 0;
    dados.valorCompras = 0;
}

void passarCompra(cliente* clientes, int tamanho)
{
    // compra compraAtual; //variavel que recebe tudo
    cliente auxiliarCliente;
    int pagamento;
    // teste:
    float valorProduto;
    int i = 0;
    float valorTotal = 0; //valor total da compra
    // fim teste;

    while (valorProduto != 0)
    {
            cout << "informe o preco do produto separado por ponto flutuante. Caso nao haja mais produtos, digite 0."<<endl
                 << ">";
            cin >> valorProduto;
            valorTotal += valorProduto;
            i++;
    }

    cout << "O valor total da compra é de " << auxiliarCliente.saldoDevedor << "." << endl
         << "Qual a forma de pagamento? " << endl
         << "1- À vista" << endl
         << "2- À prazo" << endl;
    cin >> pagamento;

    //  arquivo com lista de clientes;
    //  verifica_cliente();
    //  senao
    //  cadastrar_cliente();
    int cadastradoOuNao;
    if (pagamento == 1)
    {
        cout<<"Processo finalizado";
    }
    else if (pagamento == 2)
    {
        int cpfCliente;
        int posicaoCliente;
        cout<< "o cliente é cadastrado? "<<endl
            << "1-sim"<<endl
            << "2-nao"<<endl;
        cin>> cadastradoOuNao;
        bool sair = false;
        while(!sair) {
            if (cadastradoOuNao >= 1 and cadastradoOuNao <= 2){
            if(cadastradoOuNao == 1) {
                cout<<"Digite o CPF do cliente: ";
                cin>>cpfCliente;
                if (busca(clientes, cpfCliente, posicaoCliente)) { //vai retornar um true
                    clientes[posicaoCliente].saldoDevedor += auxiliarCliente.saldoDevedor;
                } else {
                    cout<<"Nao eh possivel passar a prazo sem ser cadastrado. Por favor, cadastre o cliente e depois passe a compra novamente!"<<endl;
                    sair = true;
                }
            } else {
                cout<<"Nao eh possivel passar a prazo sem ser cadastrado. Por favor, cadastre o cliente e depois passe a compra novamente!"<<endl;
                sair = true;
            }
            } else {
                cout << "[ERRO] digite um valor valido! (1 ou 2) " << endl;
                cin.clear();  //Limpa a flag de erro quando há falha no parse do valor entrado
                cin.ignore(); //Limpa o buffer
            }    
        }
        
    }
}

void interfaceCliente()
{
    cout << "   1- Cadastrar cliente" << endl
         << "   2- Excluir cliente" << endl
         << "   3- Alterar dado de cliente" << endl
         << "   4- Retornar ao menu principal" << endl
         << "   > ";
}

void cadastrarCliente(cliente* clientes, int tamanho)
{
    cliente clientes[tamanho-1];
    cout << "nome: " << endl;
    cin >> clientes[tamanho-1].nome;
    cout << "cpf: " << endl;
    cin >> clientes[tamanho-1].cpf;
    clientes[tamanho-1].saldoDevedor = 0;
    clientes[tamanho-1].valorCompras = 0;
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

void exibirClientes(cliente* clientes, int tamanho)
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
                    cadastrarCliente(clientes, tamanho);
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

void verificar(int acao, cliente* clientes, int tamanho)
{

    if (acao == 1)
    {
        passarCompra(clientes, tamanho);
    }
    else if (acao == 2)
    {
        exibirClientes(clientes, tamanho);
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

void menuSelecao()
{
    cout << "Escolha uma acao (digite apenas um numero): " << endl
         << "   1- Passar Compras" << endl
         << "   2- Exibir clientes cadastrados" << endl
         << "   3- Cadastrar cliente" << endl
         << "   4- Quitar Divida" <<endl
         << "   5- Sair" << endl
         << "   > ";
}

// #####################################################################
// aqui foi o último lugar que eu mexi
void salvarDados(cliente* clientes, int tamanho) {
    // como tá tudo em string ou inteiro, a gente precisa passar pra char;
    ofstream arquivo("dados.dat", ios::binary);
    char caractere[1];

    //escreve o nome
    for(int i = 0; i < tamanho; i++) {
        for (int j = 0; j < (clientes[i].nome).size(); i++) {
            caractere[0] = clientes[i].nome[j];
            arquivo.write(caractere,1);
        }
    }

}

int main()
{
    int tamanho = 1;
    cliente* clientes = new cliente[tamanho];
    // carregarClientes(clientes, tamanho); talvez a gente não precise colocar na memoria mesmo
    int acao = 0;
    bool sair = false;

    while (!sair)
    {
        menuSelecao();
        cin >> acao;
        if (acao >= 1 and acao <= 5)
        {
            if (acao == 5)
            {
                sair = true;
            }
            else
            {
                verificar(acao, clientes, tamanho);
            }
        }
        else
        {
            cout << "[ERRO] digite um valor valido! (valores de 1 a 5). " << endl;
            cin.clear();  //Limpa a flag de erro quando há falha no parse do valor entrado
            cin.ignore(); //Limpa o buffer
        }

    } //fim do while

    salvarDados(clientes, tamanho);

    return 0;
}