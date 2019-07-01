#include "bibliotecaARV.cpp"
//KASSIANE LOPES FAÇANHA
//373700 CIÊNCIA DA COMPUTAÇÃO
int menu(){
    int op;
 printf ("Arvore Rubro Negra\n");
    printf ("1 - Inserir \n");
    printf ("2 - Remover \n");
    printf ("3 - Imprimir em pre ordem  \n");
    printf ("4 - Calcular a altura \n");
    printf ("\n Digite o numero da funcao: ");
    scanf ("%d", &op);
    return op;
    }
int main(){
    int op, chave;
    Apontador aux;

    inicializa();
    system ("cls");
    op = menu();
    while (op != 0) {
        switch (op) {
            case 1:
                printf ("\n Digite o valor da chave que deseja \n\n inserir na arvore RN:\n ");
                scanf ("%d", &chave);
                raiz =  insere (raiz, chave);
                printf ("\n A chave foi inserida com sucesso!\n");
                 if (chave == 000)
                     op = menu();
            break;
            case 2:
                printf ("\n Digite o valor da chave que deseja\n\n remover da arvore RN:\n ");
                scanf ("%d", &chave);
                aux = busca (raiz, chave);
                aremove (raiz, aux);
                if (aux != nodonull){
                    printf ("\n A chave foi removida com sucesso!\n\n");
                     op = menu();
                    }
                else{
                    printf ("\n Esta chave nao existe.\n\n");
                     op = menu();
                }
            break;
            case 3:
                if (raiz != nodonull) {
                    imprimePreOrdem (raiz);
                     op = menu();
                      }
                else{
                    printf ("\n A arvore esta vazia.\n\n");
                    op = menu();
                    }

            break;
            case 4:
                   // Apontador p = chave;
                	//printf("Altura: %d\n", height(p));
            break;
            default:
            break;
        }
    }
    destroi (raiz);
    destroi (nodonull);
}
