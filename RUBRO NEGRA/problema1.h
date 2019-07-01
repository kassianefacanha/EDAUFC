
#ifndef PROBLEMA1_H
#define PROBLEMA1_H
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

typedef struct grafo {
 int V;
 int **P;
 string cor;
 }grafo;

typedef grafo * Grafo;

 void iniciarGrafo(Grafo a,int n);
 void corGrafo(Grafo G);
 void deletarGrafo(Grafo a);
 void buscarCiclos(Grafo G);
 void abrirArquivo(int op);

#endif
