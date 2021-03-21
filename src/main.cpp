//Hélio Henrique Medeiros Silva and Maurício Martins Damasceno;
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct cliente
{
    long cpf;
    char nome[10];
    float saldoDevedor;
};
// vai precisar fazer uma funcao que calcula a quantidade de registros que existem no arquivo (eh uma operacao que repete muito!)

// isso aqui é só de teste (no caso a gente vai imprimir do arquivo) 
void exibeClientes(cliente* &clientes, int tamanho) {
    cliente clienteAuxiliar;
    fstream arquivo("dados.dat", ios::in|ios::ate); //abre o arquivo para leitura posicionando na ultima posicao
    int quantRegistros = arquivo.tellg()/sizeof(cliente);
    for(int i = 0; i < quantRegistros; i++) {
        arquivo.seekg(i*sizeof(cliente));
        arquivo.read((char*)&clienteAuxiliar, sizeof(cliente));
        cout<< clienteAuxiliar.cpf << " "
            << clienteAuxiliar.nome << " "
            << clienteAuxiliar.saldoDevedor << endl;
    }
}

// vai ter uma nova utilidade!!!
// realoca vetor clientes
void realocar(cliente* &clientes, int &tamanho, int &contador, bool limparMemoria) {
    if(!limparMemoria) {
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
    } else {
        delete[] clientes;
        contador = 0;
        tamanho = 1;
        clientes = new cliente[tamanho];
    }
}


//funcao que escreve os dados do vetor no arquivo
void salvarDados(cliente* &clientes, int &tamanho) {
    ofstream arquivo("dados.dat", ios::binary|ios::app);
    arquivo.write((const char*)(clientes), tamanho*sizeof(cliente));
    bool limparMemoria = true;
    int contador = tamanho-1;
    realocar(clientes, tamanho, contador, limparMemoria);
}

bool busca(long cpfCliente, int &posicaoCliente, cliente &clienteCadastrado) {
    fstream arquivo("dados.dat", ios::in|ios::ate); //abre o arquivo para leitura posicionando na ultima posicao
    int quantRegistros = arquivo.tellg()/sizeof(cliente);
    int i = 0;
    while(i < quantRegistros) {
        arquivo.seekg(i*sizeof(cliente));
        arquivo.read((char*)&clienteCadastrado, sizeof(cliente));
        if(clienteCadastrado.cpf == cpfCliente) {
            posicaoCliente = i;
            return true; //retorna true caso tenha encontrado. Quando encontrado ele já passa por referencia a posicao do cliente
        }  
        i++;
    }
    return false;
}

void cadastrarCliente(cliente* &clientes, int &tamanho, int &contador)
{   
    bool limparDados;
    // toda vez que for chamada a funcao cadastrar, será testado o tamanho com o contador
    if (tamanho == contador) {
        limparDados = false;
        realocar(clientes, tamanho, contador, limparDados);
    }

    cout << "cpf: ";
    cin >> clientes[contador].cpf;
    cout << "nome: ";
    cin >> clientes[contador].nome;
    clientes[contador].saldoDevedor = 0;
    contador += 1;
}

// funcao que passa a compra do usuario
void passarCompra(cliente* &clientes, int tamanho)
{
    cliente auxiliarCliente;
    int pagamento;
    float valorProduto;
    int i = 0;
    // float valorTotal = 0; //valor total da compra

    while (valorProduto != 0)
    {
        cout<< "informe o preco do produto separado por ponto flutuante. Caso nao haja mais produtos, digite 0."<<endl
            << ">";
        cin >> valorProduto;
        auxiliarCliente.saldoDevedor += valorProduto;
        i++;
    }

    cout << "O valor total da compra é de: " << auxiliarCliente.saldoDevedor << "." << endl
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
        long cpfCliente;
        int posicaoCliente;
        cout<< "o cliente é cadastrado? "<<endl
            << "1-sim"<<endl
            << "2-nao"<<endl;
        cin>> cadastradoOuNao;
        if (cadastradoOuNao >= 1 and cadastradoOuNao <= 2){
            if(cadastradoOuNao == 1) {
                cout<<"Digite o CPF do cliente: ";
                cin>>cpfCliente;
                if (busca(cpfCliente, posicaoCliente, auxiliarCliente)) { //vai retornar um true ou false

                    // isso vai ter que mudar pra uma funçao altera
                    // auxiliarCliente.saldoDevedor = 
                    // cout<<auxiliarCliente.nome<<endl;
                } else {
                    cout<<"O cliente não foi encontrado. Por favor, cadastre-o e passe a compra novamente!"<<endl;
                }
            } else {
                cout<<"Nao eh possivel comprar a prazo sem ser cadastrado. Por favor, cadastre o cliente e depois passe a compra novamente!"<<endl;
            }
        } else {
            cout << "[ERRO] digite um valor valido! (1 ou 2) " << endl;
            cin.clear();  //Limpa a flag de erro quando há falha no parse do valor entrado
            cin.ignore(); //Limpa o buffer
        }    
    }
}

// funcao imprime a interface da secao de cadastro
void interfaceCliente()
{
    cout << "   1- Cadastrar cliente" << endl
         << "   2- Excluir cliente" << endl
         << "   3- Alterar dado de cliente" << endl
         << "   4- Retornar ao menu principal" << endl
         << "   > ";
}

// isso tambem faz parte de alterar o campo do usuário
// pra buscar as pessoas, a gente vai usar o cpf, pois é a unica caracteristica que não repete
void quitarDivida()
{
    // vai chamar busca;
    // vai achar posição;
    // vai chamar o altera;
    // atribui o valor zero;
}

// eh o ultimo slide sobre arquivos binários
void removerCliente(fstream &arquivo)
{  
    cliente clienteSeraExcluido;
    long cpfCliente;
    cout<<"Digite o cpf do cliente a ser excluido: "
        <<">  ";
    cin>>cpfCliente;
    cout<<endl;
    int posicaoCliente;
    if(busca(cpfCliente, posicaoCliente, clienteSeraExcluido)) { //se o resultado de busca for verdadeiro, o cliente existe
        cout<<clienteSeraExcluido.cpf <<" "
            <<clienteSeraExcluido.nome << " "
            <<clienteSeraExcluido.saldoDevedor<<endl;
        // arquivo.seekg(0, ios::end);
        int quantRegistros = arquivo.tellg()/sizeof(cliente);
        
        for (int i = posicaoCliente + 1; i < quantRegistros; i++){
            arquivo.seekp((i)*sizeof(cliente));
            arquivo.read((char*)(&clienteSeraExcluido), sizeof(cliente));
            arquivo.seekp((i-1)*sizeof(cliente)); 
            arquivo.write((char*)(&clienteSeraExcluido), sizeof(cliente));  
        }    
     } else {
         cout<<"cliente não encontrado."<<endl;
     }
}

    // vai procurar no arquivo pra remover os campos


// tem no slide
// void alterarCliente()
// {
//     fstream arquivo("dados.dat", ios::in|ios::out|ios::app); //abre o arquivo para ser modificado
//     arquivo.seekp((posicaoCliente)*sizeof(cliente)); 
//     arquivo.write((char*) &auxiliarCliente.saldoDevedor, sizeof(18));
//     arquivo.seekg(posicaoCliente*sizeof(cliente));
//     arquivo.read((char*) &auxiliarCliente, sizeof(cliente));
//     cout<<auxiliarCliente.cpf<<" ";
//     cout<<auxiliarCliente.nome<<" ";
//     cout<<auxiliarCliente.saldoDevedor<<endl;
//     // a gente vai precisar achar no arquivo, depois alterar o campo
// }

// vou ter que mexer aqui para ver qual eh a real importancia dessa funcao

// funcao que contém o menu para selecionar uma ação em relação a exibição, alteração ou exclusão
void menuCliente(cliente* &clientes, int &tamanho, int &contador)
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
                    fstream arquivo("dados.dat", ios::in|ios::ate|ios::out); //abre o arquivo para manipulacao
                    removerCliente(arquivo);
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

// funcao que verifica qual foi a acao escolhida pelo usuário
void verificar(int acao, cliente* &clientes, int &tamanho, int &contador)
{
    if (acao == 1)
    {
        passarCompra(clientes, tamanho);
    }
    else if (acao == 2)
    {
        exibeClientes(clientes, tamanho); //isso eh soh pra testes!! ()
        menuCliente(clientes, tamanho, contador);
    }
    else if (acao == 3)
    {
        cadastrarCliente(clientes, tamanho, contador);
    }
    else if (acao == 4)
    {
        // quitarDivida();
    }
    else {
        salvarDados(clientes, tamanho);
    }
}

// funcao que imprime a interface para mostrar as primeiras acoes
void menuSelecao()
{
    cout << "Escolha uma acao (digite apenas um numero): " << endl
         << "   1- Passar Compras" << endl
         << "   2- Exibir clientes cadastrados" << endl
         << "   3- Cadastrar cliente" << endl
         << "   4- Quitar Divida" <<endl
         << "   5- Salvar novos cadastrados" <<endl
         << "   6- Sair" << endl
         << "   > ";
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
        if (acao >= 1 and acao <= 6)
        {
            if (acao == 6)
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

    if (contador != 0) {
        salvarDados(clientes, tamanho);
    }

    return 0;
}