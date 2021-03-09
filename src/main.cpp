#include <iostream>
using namespace std;
//usei o pseudo código pra criar preencher os "objetos", mas acho que ao longo desenvolvimento vai precisar mudar kkkk
struct produto {
    int qtd;
    string nome;
    int id;
};
struct cliente {
    string nome;
    int cpf;
    int saldoDevedor;
    int id;
};
struct cartao {
    int n;
    string nome;
    int cvv;
};
struct compra {
    int id;
    // produto produtos[]; >>> eu acho que nóis pode tirar isso, eu acho que vai ficar complicado. mas é pq eu tô em dúvida também. uheuheuue
    cliente clientes[100];
    string pagamento;
};

int menu_selecao() {
    int acao;
    cout << "Escolha uma acao (digite apenas inteiros): " <<endl
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

int passar_Compra() {
    int teste = 0;
    return teste;
}

void exibir_Clientes() {
}

void cadastrar_Cliente() {
}

void exibeHistorico(compra historico[]) {
    int i = 0;
    while(i < 10 and historico[i].id != 0) {
        cout<<historico[i].id<<endl
            <<historico[i].clientes[i].id<<" "<<historico[i].clientes[i].saldoDevedor<<endl
            <<historico[i].pagamento<<endl;
        i++;
    }
    cout<<endl;
}

int main() {   
    compra historico[10]; //o histórico já tava definido que seria no máximo dez, né?


    int acao;
    /*  mudei pra menu selecao (antes era exibir acoes) pq, além de mostrar as acoes, ele também retorna 
        um inteiro que recebeu de entrada como acao. daí achei que seria melhor mudar o nome. mas eu acho que
        a gente pode melhorar ainda mais esses nomes hueuheuheuhuhe
    */ 
    bool sair = false;
    while(!sair) {
        acao = menu_selecao();
        if (acao == 1) {
            passar_Compra();
        } else if (acao == 2) {
            exibir_Clientes();
        } else if (acao == 3) {
            cadastrar_Cliente();
        } else if (acao == 4) {
            exibeHistorico(historico);
        } else if (acao == 5) {
            sair = true;
        } else { //acho que assim eh melhor, se não for, depois muda :)
            cout << "[ERRO] digite um valor válido! (valores de 1 a 5). " << endl << endl;
        }
    }
    
    return 0;
}