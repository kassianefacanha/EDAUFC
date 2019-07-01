#include "problema1.cpp"
//KASSIANE LOPES FAÇANHA
//373700 CIÊNCIA DA COMPUTAÇÃO

int menu(){
    int op;
    printf ("\n");
    printf ("Qual o seu problema?");
    printf ("\n");
    printf ("1 - Problema 1 \n");
    printf ("2 - Problema 2 \n");
    scanf ("%d", &op);
    return op;
    }
int main(){
    int op, chave;

    op = menu();
    while (op != 0) {
        switch (op) {
            case 1:
            abrirArquivo(op);
            break;
            case 2:
            abrirArquivo(op);
            break;
            case 3:
            printf ("Opção inválida");

            break;
            default:
            break;
        }
    }

}

