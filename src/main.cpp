#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
//Hélio Henrique Medeiros Silva and Maurício Martins Damasceno;

struct cliente
{
    long int cpf;
    string nome;
    float saldoDevedor;
    float valorCompras;
    
};
// isso aqui é só de teste (no caso a gente vai imprimir do arquivo)
void imprimeVetor(cliente* clientes, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout<< clientes[i].cpf << " "
            << clientes[i].nome << " "
            << clientes[i].saldoDevedor << endl;

    }
}

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

// realoca vetor clientes
void realoca(cliente* &clientes, int &tamanho, int &contador) {
    cliente* auxiliarClientes = new cliente[tamanho];
    for(int i = 0; i < contador; i++) {
        auxiliarClientes[i] = clientes[i];
    }

    delete[] clientes;
    
    tamanho += 1;
    clientes = new cliente[tamanho];
    
    for(int i = 0; i < contador; i++) {
        clientes[i] = auxiliarClientes[i];
    }
    
    delete[] auxiliarClientes;
    auxiliarClientes = NULL;
}

void cadastrarCliente(cliente* &clientes, int &tamanho, int &contador)
{   
    // toda vez que for chamada a funcao cadastrar, será testado o tamanho com o contador
    if (tamanho == contador) {
        realoca(clientes, tamanho, contador);
    }

    cout << "cpf: ";
    cin >> clientes[contador].cpf;
    cout << "nome: ";
    cin >> clientes[contador].nome;
    clientes[contador].saldoDevedor = 0;
    contador += 1;
}

void passarCompra(cliente* &clientes, int tamanho)
{
    cliente auxiliarCliente;
    int pagamento;
    float valorProduto;
    int i = 0;
    float valorTotal = 0; //valor total da compra

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

// pra buscar as pessoas, a gente vai usar o cpf, pois é a unica caracteristica que não repete
void quitarDivida()
{
    // vai procurar no arquivo 
}

void removerClientes()
{
    // vai procurar no arquivo pra remover os campos
}

void alterarCliente()
{
    // a gente vai precisar achar no arquivo, depois alterar o campo
}

void exibirClientes(cliente* &clientes, int &tamanho, int &contador)
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
                    cadastrarCliente(clientes, tamanho, contador);
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

void verificar(int acao, cliente* &clientes, int &tamanho, int &contador)
{

    if (acao == 1)
    {
        passarCompra(clientes, tamanho);
    }
    else if (acao == 2)
    {
        imprimeVetor(clientes, tamanho);
        exibirClientes(clientes, tamanho, contador);
    }
    else if (acao == 3)
    {
        cadastrarCliente(clientes, tamanho, contador);
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
void salvarDados(cliente* &clientes, int &tamanho) {
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
    int contador = 0; //vezes que foi adionado um elemento no vetor (quando os clientes forem salvos ele eh resetado)
    int acao;
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
                verificar(acao, clientes, tamanho, contador);
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