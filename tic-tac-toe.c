#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//variaveis globais (review)
char jogo[3][3];
int nivel;

void inicializa_velha(){
    int l,c;
    //inicializa matriz vazia
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++)
            jogo[l][c] = ' ';
    }
};

void imprime_velha(){
    int l,c;
    //imprime jogo na tela
    system("cls");
    printf("\n\t 0   1   2\n\n");
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++){
            if(c ==0)
                printf("\t");
            printf(" %c ", jogo[l][c]);
            if(c < 2)
                printf("|");
            if(c == 2)
                printf("  %d", l);
        }
        if (l < 2)
            printf("\n\t-----------");
        printf("\n");
    }
};

int menu (){
    int i,opt;
    do{
        printf("Escolha a opcao:\n");
        printf("(1) Jogar contra computador!\n");
        printf("(2) Jogar contra outro usuario!\n");
        scanf("%d", &i);
    }while(i < 1 || i > 2);
    if (i == 1){
        do{
        printf("Escolha o nivel do computador!\n");
        printf("(1) BASICO\n");
        printf("(2) INTERMEDIARIO\n");
        printf("(3) AVANCADO\n");
        scanf("%d", &opt);
        }while(opt <1 || opt > 3);
        nivel = opt;
    }
    return i;
};

void escolha_simb(char *jog1, char *jog2 ){//review
    char letra1,letra2;

    printf("\nDefina quem e X ou O(letra)");
    printf("\nJogador 1 : ");
    scanf(" %c", &letra1);
        letra1 = toupper(letra1);
    printf("\nJogador 2 : ");
    scanf(" %c", &letra2);
        letra2 = toupper(letra2);
    *jog1 = letra1;
    *jog2 = letra2;
};

int jogada_usuario(int lin,int col, char jog){
    if (jogo[lin][col] == ' ' && lin >= 0 && lin < 3 && col >= 0 && col < 3){
        jogo[lin][col] = jog;
        return 0;
    };
    if (lin < 0 || lin > 2 || col < 0 || col > 2){
        return 1;
    }else {
        if (jogo[lin][col] != ' ')
            return 2;
    };
};

int verifica_ganhador(char jog) {
    int l,c,d,ds;
    l = ganhou_linhas();
    c = ganhou_colunas();
    d = ganhou_diagonal_principal();
    ds = ganhou_diagonal_secundaria();

    if(l ==1 || c ==1 || d ==1 || ds ==1)
        return 1;
    else
        return 0;
};

int ganhou_linhas() {
    int i,j, cont=1;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 2; j++){
            if(jogo[i][j] == jogo[i][j+1])
                cont++;
        }
        if(cont == 3)
            return 1;
        cont =1;
    }
    return 0;
};

int ganhou_colunas() {
    int i,j, cont=1;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 2; j++){
            if(jogo[j][i] == jogo[j+1][i])
                cont++;
        }
        if(cont == 3)
            return 1;
        cont =1;
    }
    return 0;
};

int ganhou_diagonal_principal() {
    int i, cont=1;
    for(i = 0; i < 2; i++){
        if(jogo[i][i] == jogo[i+1][i+1])
            cont++;
    }
    if(cont == 3)
        return 1;
    else
        return 0;
};

int ganhou_diagonal_secundaria() {
    int i, cont=1;
    for(i = 0; i < 2; i++){
        if(jogo[i][3-i-1] == jogo[i+1][3-i-2])
            cont++;
    }
    if(cont == 3)
        return 1;
    else
        return 0;
};

int lin_col(int *lin,int *col){
    int x, y;

    printf("\nDigite a linha que deseja jogar: ");
    scanf("%d", &x);
    printf("\nDigite a coluna que deseja jogar: ");
    scanf("%d", &y);

    *lin = x;
    *col = y;
};


int main () {
    int lin,col,vez=1,M,controle=1,ganhador=0;
    char letra,resp,jog1,jog2;

    inicializa_velha();
    imprime_velha();
    M = menu();
    if(M == 2)
        escolha_simb(&jog1, &jog2);
    do{
        do{
            if(vez == 1){
                printf("\nJogador %s\n",&jog1);
                lin_col(&lin,&col);
                jogada_usuario(lin,col,jog1);
                system("cls");
                vez=2;
            }else{
                printf("\nJogador % s\n",&jog2);
                lin_col(&lin,&col);
                jogada_usuario(lin,col,jog2);
                system("cls");
                vez=1;
            }
            imprime_velha();
            ganhador += verifica_ganhador(letra);
        }while(ganhador != 3);
        printf("\nDeseja jogar novamente? [S-N]\n");
        scanf("%c", &resp);
    }while(resp == 's');
    return 0;
}
