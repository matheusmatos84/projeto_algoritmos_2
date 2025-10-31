#include <iostream>
#include <string>

#define N 5

int pos = 0;

using namespace std;

struct Usuario{
    int Nmatricula;
    string nome;
    string tipo;
};

struct Livro{
    int codigoL;
    int matriculaUsuario;
    string tituloLivro;
    string autor;
    string edicao;
};

void mostrarMenu() {
    cout << "---------------- MENU DA BIBLIOTECA ----------------" << endl;
    cout << "1 - Cadastrar usuario." << endl;
    cout << "2 - Cadastrar livro." << endl;
    cout << "3 - Listar usuarios." << endl;
    cout << "4 - Listar livros." << endl;
    cout << "5 - Buscar livros por usuario." << endl;
    cout << "6 - Relatorio geral." << endl;
    cout << "7 - Sair." << endl;
    cout << "Digite sua opcao: ";
}

void mostrarUsuario(Usuario vet[]){
    for(int i = 0; i < pos; i++){
        cout << "----- MOSTRAR USUARIO -----" << endl;

        cout << "Matricula Informada: " << vet[i].Nmatricula << endl;
        cout << "Nome informado: " << vet[i].nome << endl;
        cout << "Tipo Informado: " << vet[i].tipo << endl;
    }
}

void mostrarLivro(Livro vet[]){
    for(int i = 0; i < pos; i++){
        cout << "----- MOSTRAR LIVRO -----" << endl;

        cout << "Codigo do Livro Informado: " << vet[i].codigoL << endl;
        cout << "Titulo do Livro Informado: " << vet[i].tituloLivro << endl;
        cout << "Autor Informado: " << vet[i].autor << endl;
        cout << "Edicao Informada: " << vet[i].edicao << endl;
    }
}

void cadastrarUsuario(Usuario *u){
    cout << "----- CADASTRAR USUARIO -----" << endl;

    cout << "Digite o numero de matricula: ";
    cin >> u -> Nmatricula;
    cout << "Digite o nome do usuario: ";
    cin.ignore();
    getline(cin, u -> nome);
    cout << "Digite o tipo(Aluno ou Professor): ";
    getline(cin, u -> tipo);

}

void cadastrarLivro(Livro *l){
    cout << "----- CADASTRAR LIVRO -----" << endl;

    cout << "Digite o codigo do livro: ";
    cin >> l -> codigoL;
    cout << "Digite o titulo do livro: ";
    cin.ignore();
    getline(cin, l -> tituloLivro);
    cout << "Digite o nome do autor: ";
    getline(cin, l -> autor);
    cout << "Digite a edicao do livro: ";
    cin >> l -> edicao;

}

void ListarUsuario(Usuario vet[], Usuario u) {
    if (pos < N)
        vet[pos++] = u;
    else
        cout << "Lista cheia. Usuario nao adicionado." << endl;
}

void ListarLivro(Livro vet[], Livro l) {
    if (pos < N)
        vet[pos++] = l;
    else
        cout << "Lista cheia. Livro nao adicionado." << endl;
}

void BuscarLivros(Livro vet[]){
    int matr;
    cout << "Digite a matricula: ";
    cin >> matr;

    for(int i = 0; i < pos; i++){
        if(vet[i].matriculaUsuario == matr){
            cout << "Usuario que emprestou(Por Matricula): " << vet[i].matriculaUsuario << endl;
            cout << "Livro emprestado(Por Titulo): " << vet[i].tituloLivro << endl;
        }
        else{
            cout << "Matricula invalida!" << endl;
            cout << "Tente novamente: ";
            cin >> matr;
        }
    }
}

int main(){
    Usuario esteUsuario;
    Usuario vetorUsuario[N];

    Livro esteLivro;
    Livro vetorLivro[N];
    Livro vetorBuscar[N];
    int opcao;

    mostrarMenu();
    cin >> opcao;
    while(opcao != 7){
        switch(opcao){
            case 1:
                cadastrarUsuario(&esteUsuario);
                ListarUsuario(vetorUsuario, esteUsuario);
                break;
            case 2:
                cadastrarLivro(&esteLivro);
                ListarLivro(vetorLivro, esteLivro);
                break;
            case 3:
                mostrarUsuario(vetorUsuario);
                break;
            case 4:
                mostrarLivro(vetorLivro);
                break;
            case 5:
                BuscarLivros(vetorBuscar);
                break;
            default:
                break;
        }
        mostrarMenu();
        cin >> opcao;
    }

    return 0;
}
