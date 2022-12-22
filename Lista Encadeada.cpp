#include<iostream>
#include<new>
#include<string>
#include<stdlib.h>

using namespace std;


typedef struct NO{

    int RG;

    string nome;

    NO * prox;

}NO;

void inserir_inicio(NO *&, int *, string, int);
void inserir_fim(NO *&, int *, string, int);
void inserirpos(NO *&, int *, string, int, int);
void remover_inicio(NO *&, int *);
void remover_fim(NO *&, int *);
void remover_pos(NO *, int *, int);
string retorna_nome(NO *, int);
void ImprimeEncadeada(NO *, int);


int main(){

    int escolha;

    //tamanho da lista
    
    NO * inicio = NULL;
    
    int ListaTam = 0;

    do{

        cout << "\nTamanho da Lista: " << ListaTam;

        cout << "\n[1] - Inserir NO no inicio da lista\n";

        cout << "[2] - Inserir NO no fim da lista\n";

        cout << "[3] - Inserir NO na posicao N da lista\n";

        cout << "[4] - Remover NO no inicio da lista\n";

        cout << "[5] - Remover NO no fim da lista\n";

        cout << "[6] - Remover NO na posicao N da lista\n";

        cout << "[7] - Procurar NO com o campo RG\n";

        cout << "[8] - Imprimir lista\n";

        cout << "[9] - Sair\n";

        cout << "Escolhar um numero e pressione Enter:\n";

        cin >> escolha;  

        string nome;

        int RG;

        int pos;

        switch(escolha){

            case 1:
                
                cout << "Informe um Nome: \n";

                cin >> nome;

                cout << "Informe um RG: \n";

                cin >> RG;

                inserir_inicio(inicio, &ListaTam, nome, RG);

                break;
            case 2:

                cout << "Informe um Nome: \n";

                cin >> nome;

                cout << "Informe um RG: \n";

                cin >> RG;

                if(ListaTam == 0){

                    inserir_inicio(inicio, &ListaTam, nome, RG);

                }else{
                    
                    inserir_fim(inicio, &ListaTam, nome, RG);

                }

                break;
            case 3:

                cout << "Informe um Nome: \n";

                cin >> nome;

                cout << "Informe um RG: \n";

                cin >> RG;

                cout << "Informe uma posicao:\n(A primeira posicao eh 1)\n";

                cin >> pos;

                if(pos == 1){

                    inserir_inicio(inicio, &ListaTam, nome, RG);

                }else if(pos == ListaTam + 1){

                    inserir_fim(inicio, &ListaTam, nome, RG);

                }else{

                    inserirpos(inicio, &ListaTam, nome, RG, pos);

                }

                break;

            case 4:

                if(ListaTam == 0){

                    cout << "A lista ja esta vazia!\n";

                }else{

                    remover_inicio(inicio, &ListaTam);

                }
               
                break;
            case 5:

                if(ListaTam == 0){

                    cout << "Lista ja esta Vazia!\n";

                }else if(ListaTam == 1){

                    remover_inicio(inicio, &ListaTam);

                }else{

                    remover_fim(inicio, &ListaTam);

                }

                break;
            case 6:

                if(ListaTam == 0){

                    cout << "A lista ja esta vazia!\n";

                }else{

                    cout << "informe uma posicao a ser removida\n(A lista comeca com a posicao 1)\n";

                    cin >> pos;

                    if(pos == 1){

                        remover_inicio(inicio, &ListaTam);

                    }else if(pos == ListaTam){

                        remover_fim(inicio, &ListaTam);

                    }else{

                        remover_pos(inicio, &ListaTam, pos);

                    }
                }

                break;
            case 7:

                cout << "Informe o RG a ser buscado:\n";

                cin >> RG;

                cout << "Nome: " << retorna_nome(inicio, RG);
                
                cout << "\nRG: " << RG;
                break;
            case 8:

                cout << "Imprimindo...\n\n";

                ImprimeEncadeada(inicio, ListaTam);

                break;
            case 9:

                cout << "Saindo...\n";

                break;
        }
    }while(escolha < 9);

    
    return 0;
}

string retorna_nome(NO * inicio, int RG){

    NO * aux = inicio;

    while(aux != NULL){

        if(aux -> RG == RG){

            return aux -> nome;

        }

        aux = aux -> prox;

    }

    return "Nome nao encontrado";
}

void remover_pos(NO * inicio, int * tam, int pos){

    NO * aux = inicio;

    for(int i = 1; i < pos - 1; i++){

        aux = aux -> prox;

    }

    NO * aux2 = aux -> prox -> prox;

    aux -> prox = NULL;

    aux -> prox = aux2;

    *tam = *tam - 1;

}

void remover_fim(NO *&inicio, int *tam){

    NO * aux = inicio;

    for(int i = 1; i < *tam - 1; i++){

        aux = aux -> prox;

    }

    aux -> prox = NULL;

    *tam = *tam - 1;
}

void remover_inicio(NO *&inicio, int *tam){

    NO * aux = inicio;

    inicio = inicio -> prox;

    free(aux);

    *tam = *tam - 1;

}

void inserirpos(NO *&inicio, int * tam, string nome, int RG, int pos){

    NO * novo = new NO;

    novo -> nome = nome;

    novo -> RG  = RG;

    novo -> prox = NULL;

    NO * aux = inicio;

    for(int i = 1; i < pos - 1; i++){

        aux = aux -> prox;

    }

    novo -> prox = aux -> prox;

    aux -> prox = novo;

    *tam = *tam + 1;

}

void inserir_fim(NO *&inicio, int * tam, string nome, int RG){

    NO * novo = new NO;

    novo -> nome = nome;

    novo -> RG  = RG;

    novo -> prox = NULL;

    NO * aux = inicio;

    while(aux -> prox != NULL){

        aux = aux -> prox;

    };

    aux -> prox = novo;

    *tam = *tam + 1;
}
void inserir_inicio(NO *&inicio, int * tam, string nome, int RG){

    NO * novo = new NO;

    novo -> nome = nome;

    novo -> RG = RG;

    novo -> prox = inicio;

    inicio = novo;

    *tam = *tam + 1;
}

void ImprimeEncadeada(NO * inicio, int tam){

    if(tam == 0){

        cout << "Lista Vazia!";

        return;

    }

    NO * aux = inicio;

    int pos = 0; 

    while(aux != NULL){

        cout << "\n\nNome: " << aux -> nome;

        cout << "\nRG: " << aux -> RG;

        aux = aux -> prox;

        pos++;

    };

    free(aux);

}