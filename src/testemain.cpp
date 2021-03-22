//Hélio Henrique Medeiros Silva and Maurício Martins Damasceno;
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

/*
excluir ta dando ruim;
alterar tbm;
saldo devedor nao ta pilhando valores, como deveria;
*/

struct cliente
{
    long cpf;
    char nome[20];
    float saldoDevedor = 0;
};

struct produto
{
    string nome;
    int qtd;
    float valor;
};

struct compra
{
    produto produtos[100];
    cliente clientes;
    int pagamento;
};
void exibeClientes(cliente *&clientes, int tamanho)
{
    cliente clienteAuxiliar;
    fstream arquivo("dados.dat", ios::in | ios::ate);
    int qtdRegistros = arquivo.tellg() / sizeof(cliente);
    for (int i = 0; i < qtdRegistros; i++)
    {
        arquivo.seekg(i * sizeof(cliente));
        arquivo.read((char *)&clienteAuxiliar, sizeof(cliente));
        cout << endl
             << "   " << clienteAuxiliar.cpf << "  "
             << clienteAuxiliar.nome << "  "
             << clienteAuxiliar.saldoDevedor << endl
             << endl;
    }
    arquivo.close();
}

void realocar(cliente *&clientes, int &tamanho, int &contador, bool limparMemoria)
{
    if (!limparMemoria)
    {
        cliente *auxiliarClientes = new cliente[tamanho];
        for (int i = 0; i < contador; i++)
        {
            auxiliarClientes[i] = clientes[i];
        }

        delete[] clientes;

        tamanho += 1;
        clientes = new cliente[tamanho];

        for (int i = 0; i < contador; i++)
        {
            clientes[i] = auxiliarClientes[i];
        }

        delete[] auxiliarClientes;
        auxiliarClientes = NULL;
    }
    else
    {
        delete[] clientes;
        contador = 0;
        tamanho = 1;
        clientes = new cliente[tamanho];
    }
}

void salvarDados(cliente *&clientes, int &tamanho)
{
    ofstream arquivo("dados.dat", ios::app);
    arquivo.write((const char *)(clientes), tamanho * sizeof(cliente));
    bool limparMemoria = true;
    int contador = tamanho - 1;
    realocar(clientes, tamanho, contador, limparMemoria);

    cout << endl
         << "Dados salvos com sucesso!" << endl
         << endl;
    arquivo.close();
}

bool busca(long cpfCliente, int &posicaoCliente, cliente &clienteCadastrado)
{
    fstream arquivo("dados.dat", ios::in | ios::ate);
    int qtdRegistros = arquivo.tellg() / sizeof(cliente);
    int i = 0;
    while (i < qtdRegistros)
    {
        arquivo.seekg(i * sizeof(cliente));
        arquivo.read((char *)&clienteCadastrado, sizeof(cliente));
        if (clienteCadastrado.cpf == cpfCliente)
        {
            posicaoCliente = i;
            arquivo.close();
            return true;
        }
        i++;
    }
    return false;
}

void cadastrarCliente(cliente *&clientes, int &tamanho, int &contador)
{
    bool limparDados = true;
    if (tamanho == contador)
    {
        limparDados = false;
        realocar(clientes, tamanho, contador, limparDados);
    }

    cout << "cpf: ";
    cin >> clientes[contador].cpf;
    cout << "nome(apenas o primeiro nome!): ";
    cin >> clientes[contador].nome;
    contador += 1;

    cout << endl
         << "   Processo finalizado! Favor, salve os dados para atualizar a lista de clientes" << endl
         << endl;
}

void exibirComprovante(compra compraAtual, float valorTotal)
{
    cout << endl
         << "|||||||||||||||||||||||||||||||||||" << endl
         << "O valor total da compra foi de: R$" << valorTotal << endl
         << endl;

    if (compraAtual.pagamento == 1)
    {
        cout << "Pagamento a vista";
    }
    else
    {
        cout << "Pagamento a prazo" << endl
             << "nome: " << compraAtual.clientes.nome << endl
             << "cpf: " << compraAtual.clientes.cpf;
    }

    cout << endl
         << "|||||||||||||||||||||||||||||||||||" << endl
         << endl;
}

void passarCompra(cliente *&clientes, int tamanho, int contador)
{
    cliente auxiliarCliente;

    compra compraAtual;

    int i = 0;

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
            cout << endl
                 << "nome do produto: ";
            cin >> compraAtual.produtos[i].nome;
            cout << endl
                 << "preco unitario: ";
            cin >> compraAtual.produtos[i].valor;

            valorTotal = valorTotal + (compraAtual.produtos[i].valor * compraAtual.produtos[i].qtd);

            cout << endl
                 << "Informe a quantidade do produto. Se nao deseja adicionar mais algum produto, digite 0: ";

            cin >> compraAtual.produtos[i + 1].qtd;

            i++;
        }
    }

    cout << endl
         << "O valor total da compra é de: R$" << valorTotal << "." << endl
         << endl;

    while (compraAtual.pagamento != 1 and compraAtual.pagamento != 2)
    {
        cout << "Qual a forma de pagamento? " << endl
             << "   1- A vista" << endl
             << "   2- A prazo" << endl
             << "   >";

        cin >> compraAtual.pagamento;

        if (compraAtual.pagamento != 1 and compraAtual.pagamento != 2)
        {
            cout << "   [ERRO] digite um valor valido!";
        }
    }

    int verificaCadastro;

    if (compraAtual.pagamento == 1)
    {
        exibirComprovante(compraAtual, valorTotal);

        cout << endl;
    }
    else if (compraAtual.pagamento == 2)
    {
        long cpfCliente;
        int posicaoCliente;

        while (verificaCadastro != 1 and verificaCadastro != 2)
        {
            cout << "o cliente é cadastrado? " << endl
                 << "   1-sim" << endl
                 << "   2-nao" << endl
                 << "   > ";
            cin >> verificaCadastro;

            if (verificaCadastro != 1 and verificaCadastro != 2)
            {
                cout << "   [ERRO] digite um valor valido! (1 ou 2) " << endl;
            }
        }
        if (verificaCadastro == 1)
        {
            cout << "   Digite o CPF do cliente: ";
            cin >> cpfCliente;
            if (busca(cpfCliente, posicaoCliente, auxiliarCliente))
            {
                auxiliarCliente.saldoDevedor = auxiliarCliente.saldoDevedor + valorTotal;
                compraAtual.clientes = auxiliarCliente;

                exibirComprovante(compraAtual, valorTotal);
            }
            else
            {
                cout << "   Cliente nao encontrado, favor cadastre-o e passe as compras novamente" << endl;
            }
        }
        else
        {
            cout << "   Favor cadastre o cliente e passe as compras novamente" << endl;
        }

        cin.clear();
        cin.ignore();
    }
}

void interfaceCliente()
{
    cout << "   1- Cadastrar cliente" << endl
         << "   2- Excluir cliente" << endl
         << "   3- Alterar dado de cliente" << endl
         << "   4- quitar divida" << endl
         << "   5- Retornar ao menu principal" << endl
         << "   >  ";
}

void quitarDivida()
{
    cliente clientes;
    long cpfCliente;
    cout << "   Digite o cpf do cliente a ser excluido: ";
    cin >> cpfCliente;
    cout << endl;
    int posicaoCliente;
    fstream arquivo("dados.dat", ios::in);
    if (busca(cpfCliente, posicaoCliente, clientes))
    {
        cout << "   Processo finalizado! Favor, salve os dados para atualizar a lista de clientes" << endl
             << endl;
        arquivo.seekg(0, ios::end);
    }
    arquivo.close();
}

void removerCliente()
{
    cliente clienteSeraExcluido;
    long cpfCliente;
    cout << "   Digite o cpf do cliente a ser excluido: "
         << "   >  ";
    cin >> cpfCliente;
    cout << endl;
    int posicaoCliente = 0;
    if (busca(cpfCliente, posicaoCliente, clienteSeraExcluido))
    {
        cout << "   Processo finalizado! Favor, salve os dados para atualizar a lista de clientes" << endl
             << endl;
        fstream arquivo("dados.dat", ios::in|ios::out);
        arquivo.seekg(0, ios::end);
        int qtdRegistros = arquivo.tellg() / sizeof(cliente);

        for (int i = posicaoCliente + 1; i < qtdRegistros; i++)
        {
            arquivo.seekp((i)*sizeof(cliente));
            arquivo.read((char *)(&clienteSeraExcluido), sizeof(cliente));
            arquivo.seekp((i - 1) * sizeof(cliente));
            arquivo.write((char *)(&clienteSeraExcluido), sizeof(cliente));
        }
        arquivo.close();
    }
    else
    {
        cout << "   cliente não encontrado." << endl;
    }
}

void alterarCliente()
{
    int cont = 0;
    char nome_trocado[20];
    cout << "   Nome do  cliente: ";
    cin >> nome_trocado;

    cliente substituto;

    cout << endl
         << "   Novo nome(apenas o primeiro nome!): ";
    cin >> substituto.nome;
    cout << endl
         << "   Novo cpf: ";
    cin >> substituto.cpf;

    bool naoAchou = 1;

    cliente clientes;

    fstream arquivo("dados.dat", ios::in|ios::out);
    arquivo.seekg(0, ios::end);
    int qtdRegistros = arquivo.tellg() / sizeof(cliente);

    while ((cont < qtdRegistros) and (naoAchou))
    {
        arquivo.seekp(cont * sizeof(cliente));
        arquivo.read((char *)&clientes, sizeof(cliente));
        if (strcmp(clientes.nome, nome_trocado) == 0)
        {
            arquivo.seekp((cont) * sizeof(cliente));
            arquivo.write((char *)&substituto, sizeof(cliente));
            naoAchou = 0;
        }
        cont++;
    }
}

void menuCliente(cliente *&clientes, int &tamanho, int &contador)
{
    bool sair = false;
    int opcaoCliente;
    while (!sair)
    {
        interfaceCliente();
        cin >> opcaoCliente;
        if (opcaoCliente >= 1 and opcaoCliente <= 5)
        {
            if (opcaoCliente == 5)
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
                    removerCliente();
                }
                else if (opcaoCliente == 3)
                {
                    alterarCliente();
                }
                else if (opcaoCliente == 4)
                {
                    quitarDivida();
                }
            }
        }
        else
        {
            cout << "   [ERRO] digite um valor valido! (valores de 1 a 5). " << endl;
            cin.clear();
            cin.ignore();
        }
    }
}

void verificar(int acao, cliente *&clientes, int &tamanho, int &contador)
{
    if (acao == 1)
    {
        passarCompra(clientes, tamanho, contador);
    }
    else if (acao == 2)
    {
        exibeClientes(clientes, tamanho);
        menuCliente(clientes, tamanho, contador);
    }
    else if (acao == 3)
    {
        cadastrarCliente(clientes, tamanho, contador);
    }
    else if (acao == 4)
    {
        salvarDados(clientes, tamanho);
    }
}

void menuSelecao()
{
    cout << "Escolha uma acao (digite apenas um numero): " << endl
         << "   1- Passar Compras" << endl
         << "   2- Exibir clientes cadastrados" << endl
         << "   3- Cadastrar cliente" << endl
         << "   4- Salvar novas operacoes" << endl
         << "   5- Sair" << endl
         << "   > ";
}

int main()
{
    int tamanho = 1;
    cliente *clientes = new cliente[tamanho];
    int contador = 0;
    int acao;
    bool sair = false;

    cout << endl
         << endl
         << "APOS QUALQUER ALTERACAO NOS ARQUIVOS, E NECESSARIO QUE SEJA SALVO, SELECIONANDO A OPCAO 4 NO MENU PRINCIPAL !" << endl
         << endl;

    while (!sair)
    {
        menuSelecao();
        cin >> acao;
        if (acao >= 1 and acao <= 6)
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
            cout << "   [ERRO] digite um valor valido! (valores de 1 a 5). " << endl;
            cin.clear();
            cin.ignore();
        }
    }

    if (contador != 0)
    {
        salvarDados(clientes, tamanho);
    }

    return 0;
}