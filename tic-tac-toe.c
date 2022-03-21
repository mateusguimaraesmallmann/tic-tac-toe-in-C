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


int main () {
    int lin,col, M;
    char letra,jogador1,jogador2;

    inicializa_velha();

    imprime_velha();

    M = menu();

    if(M == 2)
        escolha_simb(&jogador1, &jogador2);

    printf("\nJOGADOR TESTE 1 : %c", jogador1);
    printf("\nJOGADOR TESTE 2 : %c", jogador2);

    printf("\nDigite a linha que deseja jogar: ");
    scanf("%d", &lin);
    printf("\nDigite a linha que deseja jogar: ");
    scanf("%d", &col);
    printf("\nDigite X ou O(letra): ");
    scanf(" %c", &letra);
    letra = toupper(letra);

    jogada_usuario(lin,col,letra);

    return 0;
}
