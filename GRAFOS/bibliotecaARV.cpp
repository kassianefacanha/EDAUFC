#include "bibliotecaARV.h"
#include <stdlib.h>
#include <stdio.h>


Apontador criaNodo ( int k, Apontador esq, Apontador dir, Apontador pai){
    Apontador p = (Apontador )malloc (sizeof (*p));
    p->chave = k;
    p->esq = esq;
    p->dir = dir;
    p->pai = pai;

}


void inicializa (void){
    nodonull = criaNodo (0, NULL, NULL, NULL);
    nodonull->cor = BLACK;
    raiz = nodonull;
}

Apontador rotEsq (Apontador r, Apontador p) {
    Apontador y = p->dir;
    p->dir = y->esq;
    if (y->esq != nodonull)
        y->esq->pai = p;
    y->pai = p->pai;
    if (p->pai == nodonull)
        r = y;
    else if (p == p->pai->esq)
        p->pai->esq = y;
    else
        p->pai->dir = y;
    y->esq = p;
    p->pai = y;
    return r;
}

Apontador rotDir (Apontador r, Apontador p) {
    Apontador y = p->esq;
    p->esq = y->dir;
    if (y->dir != nodonull)
        y->dir->pai = p;
    y->pai = p->pai;
    if (p->pai == nodonull)
        r = y;
    else if (p == p->pai->esq)
        p->pai->esq = y;
    else
        p->pai->dir = y;
    y->dir = p;
    p->pai = y;
    return r;
}

Apontador arrumaInsere ( Apontador r, Apontador p ){
    Apontador tio;
    while (p->pai->cor == RED ) {
        if (p->pai == p->pai->pai->esq) {
            tio = p->pai->pai->dir;
            if (tio->cor == RED) {
                p->pai->cor = BLACK;
                tio->cor = BLACK;
                p->pai->pai->cor = RED;
                p = p->pai->pai;
            }
            else {
                if (p == p->pai->dir){
                    p = p->pai;
                    r = rotEsq(r, p);
                }else {
                p->pai->cor = BLACK;
                p->pai->pai->cor = RED;
                r = rotDir(r, p->pai->pai ); }
            }
        }
        else{
            tio = p->pai->pai->esq;
            if (tio->cor == RED) {
                p->pai->cor = BLACK;
                tio->cor = BLACK;
                p->pai->pai->cor = RED;
                p = p->pai->pai;
            }
            else {
                if (p == p->pai->esq){
                    p = p->pai;
                    r = rotDir(r, p);
                }else {
                p->pai->cor = BLACK;
                p->pai->pai->cor = RED;
                r = rotEsq(r, p->pai->pai);}
            }
        }
    }
    r->cor = BLACK;
    return r;
}

Apontador insere (Apontador p, int k) {
    Apontador novo = criaNodo (k, nodonull, nodonull, nodonull);

    Apontador x = p;
    Apontador paix = nodonull;

    while (x != nodonull){
        paix = x;
        if (k < x->chave)
            x = x->esq;
        else
            x = x->dir;
    }
    novo->pai = paix;
    if (paix == nodonull)
        p = novo;
    else if (k < paix->chave)
        paix->esq = novo;
    else
        paix->dir = novo;
    novo->cor = RED;
    p =  arrumaInsere (p, novo);
    return p;
}

void imprimePreOrdem (Apontador p) {
    if (p == nodonull)
        return;
    if (p->cor == BLACK)
        printf ("Chave: %d | Cor: BLACK\n", p->chave);
    else
        printf ("Chave: %d | Cor: RED\n", p->chave);
    imprimePreOrdem (p->esq);
    imprimePreOrdem (p->dir);
}

Apontador sucessor (Apontador p) {
    Apontador aux;
    if (p->dir == nodonull)
        return nodonull;
    aux = p->dir;
    while (aux->esq != nodonull){
        aux = aux->esq;
    }
    return aux;
}

void arrumaRem (Apontador T, Apontador x) {
    Apontador w;
    while (x != T && x->cor == BLACK) {
        if (x == x->pai->esq) {
            w = x->pai->dir;
            if (w->cor == RED) {
                w->cor = BLACK;
                x->pai->cor = RED;
                rotEsq (T, x->pai);
                w = x->pai->dir;
            }
            if (w->esq->cor == BLACK && w->dir->cor == BLACK){
                w->cor = RED;
                x = x->pai;
            }
            else if (w->dir->cor == BLACK){
                w->esq->cor = BLACK;
                w->cor = RED;
                rotDir (T, w);
                w = x->pai->dir;
            }
            w->cor = x->pai->cor;
            x->pai->cor = BLACK;
            w->dir->cor = BLACK;
            rotEsq (T, x->pai);
            x = T;
        }
        else {
            w = x->pai->esq;
            if (w->cor == RED) {
                w->cor = BLACK;
                x->pai->cor = RED;
                rotDir (T, x->pai);
                w = x->pai->esq;
            }
            if (w->dir->cor == BLACK && w->esq->cor == BLACK){
                w->cor = RED;
                x = x->pai;
            }
            else if (w->esq->cor == BLACK){
                w->dir->cor = BLACK;
                w->cor = RED;
                rotEsq (T, w);
                w = x->pai->esq;
            }
            w->cor = x->pai->cor;
            x->pai->cor = BLACK;
            w->esq->cor = BLACK;
            rotDir (T, x->pai);
            x = T;
        }
    }
    x->cor = BLACK;
}

void aremove (Apontador r, Apontador nodok) {
    Apontador nodoRem, filho;
    if (nodok == nodonull)
        return;
    if (nodok->esq == nodonull || nodok->dir == nodonull)
        nodoRem = nodok;
    else
        nodoRem = sucessor (nodok);
    if (nodoRem->esq != nodonull)
        filho = nodoRem->esq;
    else
        filho = nodoRem->dir;
    filho->pai = nodoRem->pai;
    if (nodoRem->pai == nodonull)
        r = filho;
    else if (nodoRem == nodoRem->pai->esq)
        nodoRem->pai->esq = filho;
    else
        nodoRem->pai->dir = filho;
    if (nodok != nodoRem)
        nodok->chave = nodoRem->chave;
    if (nodoRem == raiz){
        raiz = nodonull;
        return;
    }
    free(nodoRem);
    if (nodoRem->cor == BLACK)
        arrumaRem (r, filho);
}



void destroi (Apontador p) {
    if (p == nodonull)
        return;
    destroi (p->esq);
    destroi (p->dir);
    free (p);
}

Apontador busca (Apontador p, int k) {
    if (p == nodonull)
        return nodonull;
    if (p->chave == k)
        return p;
    else if (k < p->chave)
        return busca (p->esq, k);
    else
        return busca (p->dir, k);
}
int height(Apontador p){
	if (p == nodonull) return -1;
	int altEsq = height(p->esq);
	int altDir = height(p->dir);
	return 1+(altEsq > altDir ? altEsq : altDir);
}

