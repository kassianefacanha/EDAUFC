

#ifndef BIBLIOTECAARV_H
#define BIBLIOTECAARV_H
#include<stdio.h>
#include<stdlib.h>

enum Cor {RED, BLACK};
typedef enum Cor TipoCor;
typedef struct No *Apontador;
typedef struct No {
    int chave;
    TipoCor cor;
    Apontador pai;
    Apontador esq, dir;
}No;

Apontador raiz, nodonull;

Apontador criaNodo (int k, Apontador esq, Apontador dir, Apontador pai);

void inicializa (void);

Apontador rotEsq (Apontador r, Apontador p);

Apontador rotDir (Apontador r, Apontador p);

Apontador  arrumaInsere ( Apontador r, Apontador p );

Apontador insere (Apontador p, int k);

void imprimePreOrdem (Apontador p);

Apontador sucessor (Apontador p);

void arrumaRem (Apontador T, Apontador x);

void aremove (Apontador r, Apontador nodok);

void destroi (Apontador p);

Apontador busca (Apontador p, int k);

int height(Apontador p);

#endif

