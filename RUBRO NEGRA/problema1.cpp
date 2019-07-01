#include <stdio.h>
#include <stdlib.h>
#include "problema1.h"



 void iniciarGrafo(Grafo x,int n){
    x->V = n;
    x->P = new int*[n];
    for (int i = 0; i < n; i++)
        x->P[i] = new int[n];
        for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            x->P[i][j] = 0;
        }
    }
 }

void deletarGrafo(Grafo x){
    for(int i = 0; i < x->V; i++){
        delete[] x->P[i];
    }
    delete[] x->P;
}

void corGrafo(Grafo G){
    int vetNum = G->V;
    string cor[vetNum];
    int i = 0;
	int j = 0;

    for(int i = 0; i < vetNum ; i++){
        cor[i]= "WHITE";
    }
        while(i<vetNum){
        if(cor[i] == "WHITE"){
                cor[i] = "RED";
        }
        while(j<vetNum){
            if(G->P[i][j] == 1 && cor[j] == "WHITE"){
                if(cor[i] == "RED"){
					cor[j] = "BLACK";}
                else{
                    cor[j] = "RED";}
                if(j == vetNum-1)break;}
            if(i != j && G->P[i][j] == 1 && cor[j] == cor[i]){
                 printf("NAO\n");
                 return;
            }
         j++;
        }
	i++;
    }

     printf("SIM\n");
    for(int y = 0; y < vetNum; y++){
        cout << "" << y <<" " << cor[y] << endl;
    }
    return;


}

 void buscarCiclos(Grafo G){
    int vetNum = G->V;
    bool ciclo = false;
    int cam[vetNum][vetNum];
      int i =0;
      int j =0;
      int x =0;

	while(i<vetNum){
		while(j<vetNum){
			cam[i][j] = 0;
                while(x<vetNum){
                cam[i][j] = (cam[i][j] + G->P[i][x] * G->P[x][j]);
                x++;
			}
			j++;
		}
        i++;
	}




	while(i<vetNum){
		while(j<vetNum){
            if( i != j && cam[i][j]==2){
                    ciclo = true;
            }
            j++;
        }
        i++;
	}
	if(ciclo){
		printf("SIM \n");
	}
    else{
		 printf("NAO \n");
	}
 }
void abrirArquivo(int op){
  FILE *arq;
                if(op == 1){
                     arq = fopen("grafo.txt", "rt");
                        }
                else if(op == 2){
                    arq = fopen("grafo2.txt", "rt");
                        }

              char Linha[6];
              char *resu;
              int i, vertn;

              i = 1;
              while (!feof(arq)){
                    resu = fgets(Linha, 6, arq);
                    if(i == 1 && strcmp(resu, "0") != 0){
                        Grafo G = new grafo();
                        vertn = *resu - '0';
                        iniciarGrafo(G, vertn);

                        while (strcmp(resu, "0 0\n") != 0){

                          resu = fgets(Linha, 6, arq);
                          if(strcmp(resu, "0 0\n") == 0)break;

                          int x = Linha[0] - '0';
                          int y = Linha[2] - '0';
                          G->P[x][y] = 1;

                          i = 0;
                        }
                        if(strcmp(resu, "0") == 0)break;
                        if(op == 1){
                            corGrafo(G);
                            deletarGrafo(G);
                        }
                        else if(op == 2){
                             buscarCiclos(G);
                            deletarGrafo(G);
                        }

                    }
                 i++;
              }

              fclose(arq);
}

