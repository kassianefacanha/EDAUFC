#include "problema1.cpp"
//KASSIANE LOPES FA�ANHA
//373700 CI�NCIA DA COMPUTA��O

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
            printf ("Op��o inv�lida");

            break;
            default:
            break;
        }
    }

}

