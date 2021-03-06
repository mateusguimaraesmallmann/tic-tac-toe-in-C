#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

// variaveis globais
char jogo[3][3];
int nivel, verif = 0;

void inicializa_velha()
{
    int l, c;
    // inicializa matriz vazia
    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
            jogo[l][c] = ' ';
    }
}

void imprime_velha()
{
    int l, c;
    // imprime jogo na tela
    system("cls");
    printf("\n\t 0   1   2\n\n");
    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            if (c == 0)
                printf("\t");
            printf(" %c ", jogo[l][c]);
            if (c < 2)
                printf("|");
            if (c == 2)
                printf("  %d", l);
        }
        if (l < 2)
            printf("\n\t-----------");
        printf("\n");
    }
}

int menu()
{
    int i, opt;
    do
    {
        printf("Escolha a opcao:\n");
        printf("(1) Jogar contra computador!\n");
        printf("(2) Jogar contra outro usuario!\n");
        scanf("%d", &i);
    } while (i < 1 || i > 2);
    if (i == 1)
    {
        do
        {
            printf("Escolha o nivel do computador!\n");
            printf("(1) BASICO\n");
            printf("(2) INTERMEDIARIO\n");
            printf("(3) AVANCADO\n");
            scanf("%d", &opt);
        } while (opt < 1 || opt > 3);
        nivel = opt;
    }
    return i;
}

void escolha_simb(char *jog1, char *jog2)
{ 
    char letra1, letra2;

    printf("\nDefina quem e X ou O(letra)");
    printf("\nJogador 1 : ");
    scanf(" %c", &letra1);
    letra1 = toupper(letra1);
    printf("\nJogador 2 : ");
    scanf(" %c", &letra2);
    letra2 = toupper(letra2);
    *jog1 = letra1;
    *jog2 = letra2;
}

int jogada_usuario(int lin, int col, char jog)
{
    if (jogo[lin][col] == ' ' && lin >= 0 && lin < 3 && col >= 0 && col < 3)
    {
        jogo[lin][col] = jog;
        return 0;
    }
    if (lin < 0 || lin > 2 && col < 0 || col > 2)
    {
        return 1;
    }
    else
    {
        if (jogo[lin][col] != ' ')
            return 2;
    }
}

int ganhou_linhas(char jog)
{
    if (jogo[0][0] == jog && jogo[0][1] == jog && jogo[0][2] == jog || jogo[1][0] == jog && jogo[1][1] == jog && jogo[1][2] == jog ||
        jogo[2][0] == jog && jogo[2][1] == jog && jogo[2][2] == jog)
    {
        return 1;
    }
    else
        return 0;
}

bool ganhou_colunas(char jog)
{
    if (jogo[0][0] == jog && jogo[1][0] == jog && jogo[2][0] == jog || jogo[0][1] == jog && jogo[1][1] == jog && jogo[2][1] == jog ||
        jogo[0][2] == jog && jogo[1][2] == jog && jogo[2][2] == jog)
    {
        return true;
    }
    else
        return false;
}

bool ganhou_diagonal_principal(char jog)
{
    if (jogo[0][0] == jog && jogo[1][1] == jog && jogo[2][2] == jog)
    {
        return true;
    }
    else
        return false;
}

bool ganhou_diagonal_secundaria(char jog)
{
    if (jogo[0][2] == jog && jogo[1][1] == jog && jogo[2][0] == jog)
    {
        return true;
    }
    else
        return false;
}

int verifica_ganhador(char jog)
{
    if (ganhou_linhas(jog))
        verif = 1;
    if (ganhou_colunas(jog))
        verif = 1;
    if (ganhou_diagonal_principal(jog))
        verif = 1;
    if (ganhou_diagonal_secundaria(jog))
        verif = 1;
    if (verif == 1)
        return 1;
    else
        return 0;
}

int lin_col(int *lin, int *col)
{
    int x, y;

    printf("\nDigite a linha que deseja jogar: ");
    scanf("%d", &x);
    printf("\nDigite a coluna que deseja jogar: ");
    scanf("%d", &y);

    *lin = x;
    *col = y;
}

void jogada_computador(char jog, int nivel)
{
    if (nivel == 1)
        jogada_basica(jog);
    if (nivel == 2)
        jogada_intermediaria(jog);
    if (nivel == 3)
        jogada_avancado(jog);
}

void jogada_basica(char jog)
{
    int l, c, x = 0;

    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            if (jogo[l][c] == ' ')
            {
                jogo[l][c] = jog;
                x = 1;
                break;
            }
        }
        if (x == 1)
            break;
    }
}

void jogada_intermediaria(char jog)
{
    int l, c;

    srand(time(NULL));
    do
    {
        l = rand() % 3;
        c = rand() % 3;
    } while (jogo[l][c] != ' ');
    jogo[l][c] = jog;
}

void jogada_avancado(char jog)
{
    int l, c;
    // linha 0
    if (jogo[0][0] == jog && jogo[0][1] == jog)
        jogo[0][2] = jog;
    if (jogo[0][0] == jog && jogo[0][2] == jog)
        jogo[0][1] = jog;
    if (jogo[0][2] == jog && jogo[0][1] == jog)
        jogo[0][0] = jog;
    // linha 1
    if (jogo[1][0] == jog && jogo[1][1] == jog)
        jogo[1][2] = jog;
    if (jogo[1][0] == jog && jogo[1][2] == jog)
        jogo[1][1] = jog;
    if (jogo[1][2] == jog && jogo[1][1] == jog)
        jogo[1][0] = jog;
    // linha 2
    if (jogo[2][0] == jog && jogo[2][1] == jog)
        jogo[2][2] = jog;
    if (jogo[2][0] == jog && jogo[2][2] == jog)
        jogo[2][1] = jog;
    if (jogo[2][2] == jog && jogo[2][1] == jog)
        jogo[2][0] = jog;
    // coluna 1
    if (jogo[0][0] == jog && jogo[1][0] == jog)
        jogo[2][0] = jog;
    if (jogo[0][0] == jog && jogo[2][0] == jog)
        jogo[1][0] = jog;
    if (jogo[2][0] == jog && jogo[1][0] == jog)
        jogo[0][0] = jog;
    // coluna 2
    if (jogo[0][1] == jog && jogo[1][1] == jog)
        jogo[2][1] = jog;
    if (jogo[2][1] == jog && jogo[0][1] == jog)
        jogo[1][1] = jog;
    if (jogo[2][1] == jog && jogo[1][1] == jog)
        jogo[0][1] = jog;
    // coluna 3
    if (jogo[0][2] == jog && jogo[1][2] == jog)
        jogo[2][2] = jog;
    if (jogo[2][2] == jog && jogo[0][2] == jog)
        jogo[1][2] = jog;
    if (jogo[2][2] == jog && jogo[1][2] == jog)
        jogo[0][2] = jog;
    // Diagonal Principal
    if (jogo[0][0] == jog && jogo[1][1] == jog)
        jogo[2][2] = jog;
    if (jogo[0][0] == jog && jogo[2][2] == jog)
        jogo[1][1] = jog;
    if (jogo[2][2] == jog && jogo[1][1] == jog)
        jogo[0][0] = jog;
    // Diagonal Secundaria
    if (jogo[0][2] == jog && jogo[1][1] == jog)
        jogo[2][0] = jog;
    if (jogo[0][2] == jog && jogo[2][0] == jog)
        jogo[1][1] = jog;
    if (jogo[2][0] == jog && jogo[1][1] == jog)
        jogo[0][2] = jog;

    srand(time(NULL));
    do
    {
        l = rand() % 3;
        c = rand() % 3;
    } while (jogo[l][c] != ' ');
    jogo[l][c] = jog;
}

int main()
{
    int lin, col, jogadas = 9, vez = 1, men, gc = 0, ganhador = 0, valjog;
    char resp, jog1, jog2;
    bool controle = true;

    do
    {
        inicializa_velha();
        imprime_velha();
        men = menu();
        escolha_simb(&jog1, &jog2);
        system("cls");
        imprime_velha();
        do
        {
            // jogada com computador
            if (men == 1)
            {
                if (vez == 1)
                {
                    printf("\nJogador %c\n", jog1);
                    do
                    {
                        lin_col(&lin, &col);
                        valjog = jogada_usuario(lin, col, jog1);
                        if (valjog != 0)
                        {
                            printf("\nJogada invalida...");
                            sleep(1);
                            system("cls");
                            imprime_velha();
                            printf("\nJogador %c\n", jog1);
                        }
                    } while (valjog != 0);
                    ganhador = verifica_ganhador(jog1);
                    jogadas--;
                    vez = 2;
                    gc = 1;
                }
                else if (vez == 2)
                {
                    printf("\nComputador...jogando");
                    sleep(2);
                    jogada_computador(jog2, nivel);
                    jogadas--;
                    vez = 1;
                    ganhador = verifica_ganhador(jog2);
                    gc = 2;
                }
            }
            // jogada com outro usuario
            if (men == 2)
            {
                if (vez == 1)
                {
                    printf("\nJogador %c\n", jog1);
                    do
                    {
                        lin_col(&lin, &col);
                        valjog = jogada_usuario(lin, col, jog1);
                        if (valjog != 0)
                        {
                            printf("\nJogada invalida...");
                            sleep(1);
                            system("cls");
                            imprime_velha();
                            printf("\nJogador %c\n", jog1);
                        }
                    } while (valjog != 0);
                    system("cls");
                    jogadas--;
                    vez = 2;
                    ganhador = verifica_ganhador(jog1);
                    gc = 1;
                }
                else
                {
                    printf("\nJogador %c\n", jog2);
                    do
                    {
                        lin_col(&lin, &col);
                        valjog = jogada_usuario(lin, col, jog2);
                        if (valjog != 0)
                        {
                            printf("\nJogada invalida...");
                            sleep(1);
                            system("cls");
                            imprime_velha();
                            printf("\nJogador %c\n", jog2);
                        }
                    } while (valjog != 0);
                    system("cls");
                    jogadas--;
                    vez = 1;
                    ganhador = verifica_ganhador(jog2);
                    gc = 2;
                }
            }

            imprime_velha();

            if (ganhador == 1)
                controle = false;
            else
            {
                controle = true;
                if (jogadas == 0)
                    controle = false;
                else
                    controle = true;
            }

        } while (controle);

        if (jogadas == 0)
            printf("\nQue pena! Ninguem ganhou!");
        else
        {
            if (gc == 1)
                printf("\nParabens!!! O ganhador foi % c", jog1);
            else
                printf("\nParabens!!! O ganhador foi % c", jog2);
        }
        printf("\nDeseja jogar novamente? [S-N]\n");
        scanf(" %c", &resp);
        if (resp == 's')
        {
            verif = 0;
            jogadas = 9;
            vez = 1;
            gc = 0;
            ganhador = 0;
        }
    } while (resp == 's');
    return 0;
}
