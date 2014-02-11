#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define TEMPFACIL 5000
#define TEMPNORMAL 10000
#define TEMPDIFICIL 15000
#define FACIL 4
#define NORMAL 6
#define DIFICIL 8
#define TRUE 1
#define FALSE 0
#define ASCII 198
#define tratarRand(x) (((x >= 1) && (x <= 6)) || ((x == 11) || (x == 12) || (x == 14) || (x == 15) || ((x >= 17) && (x <= 21)) || (x == 33) || ((x >= 35) && (x <= 38)) || (x == 63) || (x == 64) || ((x >= 155) && (x <= 157)) || (x == 159) || (x == 168) || (x == 169) || (x == 173) || (x == 175) || (x == 190) || (x == 197))) ? 1 : 0

struct ranking
{
    char nome[10][11];
    int score[10];
};

struct ranking rk;

char menu();
char getSpecChar(int ini, int lim);
int menuDificuldade();
void gerarJogo(int n);
int getLnCl(int gen);
void printRank();
int scoreCalc(int lvl, int chances, int score);
void about();
void organizarRank(int pos);

int main()
{
    char op;
    int i;

    for (i = 0; i < 10; i++)
        strcpy(rk.nome[i], "          ");
    for (i = 0; i < 10; i++)
        rk.score[i] = 0;
    do
    {
        op = menu();
        switch(op)
        {
            case '1': { gerarJogo(menuDificuldade()) ; break; }
            case '2': { printRank(); break; }
            case '3': { about(); break; }
            case '4': { printf("\n\nO jogo sera fechado!\n\n"); Sleep(3000); break; }
        }
        system("pause");
    } while (op != '4');
    return 0;
}

char menu()
{
    char opt;

    system("cls");
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("\n    %c  JOGO DA MEMORIA  %c", 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c Jogar         %c", 186, 1, 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c Ranking       %c", 186, 2, 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c Sobre         %c", 186, 3, 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c Sair          %c", 186, 4, 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n\n\n", 200 , 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    return opt = getSpecChar(1, 4);
}

char getSpecChar(int ini, int lim)
{
    char c;

    if ((ini >= 0 && ini <= 9) && (lim >= 0 && lim <= 9))
    {
        ini = ini + '0';
        lim = lim + '0';
        do
        {
            c = getch();
        } while (c < ini || c > lim);
    }
    else if ((ini >= 65 && ini <= 90) && (lim >= 65 && lim <= 90))
    {
        do
        {
            c = getch();
            if ((c == 13) && (lim > 'H'))
                break;
        } while ((c < ini || c > lim) && (c < ini + 32 || c > lim + 32));
    }
    putchar(c);
    return c;
}

int menuDificuldade()
{
    char op;

    system("cls");
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("\n    %c       NIVEL       %c", 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c FACIL   %c %2ds %c", 186, 1, 186, 186, TEMPFACIL / 1000, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c NORMAL  %c %2ds %c", 186, 2, 186, 186, TEMPNORMAL / 1000, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c DIFICIL %c %2ds %c", 186, 3, 186, 186, TEMPDIFICIL / 1000, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n\n\n", 200 , 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 188);
    op = getSpecChar(1, 3);
    switch(op)
    {
        case '1': { return FACIL; break; }
        case '2': { return NORMAL; break; }
        case '3': { return DIFICIL; break; }
    }
    return 0;
}

void gerarJogo(int const n)
{
    int chances = 1, acabou = 0, flag, vez = -1, col = 0, col2 = 0, ln = 0, ln2 = 0, temp, cont, score = 0, cont2, i, j, mat[n][n], matgen[n][n], matcomp[((n * n) / 2)];
    float multi = 0.0;

    srand(time(0));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            matgen[i][j] = 219;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mat[i][j] = 0;
    for (i = 0; i < n + n; i++)
        matcomp[i] = 0;
    for (cont = 0; cont < ((n * n) / 2); cont++)
    {
        i = rand() % n;
        j = rand() % n;
        while (mat[i][j] != 0)
        {
            i = rand() % n;
            j = rand() % n;
        }
        flag = FALSE;
        while (flag == FALSE)
        {
            while (flag == FALSE)
            {
                temp = rand() % ASCII;
                flag = tratarRand(temp);
            }
            flag = FALSE;
            for (cont2 = 0; cont2 < ((n * n) / 2); cont2++)
                if (temp == matcomp[cont2])
                    break;
                else if ((temp != matcomp[cont2]) && (cont2 == (((n * n) / 2) - 1)))
                    flag = TRUE;
        }
        mat[i][j] = temp;
        matcomp[cont] = temp;
        while (mat[i][j] != 0)
        {
            i = rand() % n;
            j = rand() % n;
        }
        mat[i][j] = temp;
    }
    /*
    // VER MATRIZES
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            printf("M[%d][%d] = %d\n", i, j, mat[i][j]);

    //IMRPIMIR VETOR DE COMPARAÇÃO
    for (i = 0; i < ((n * n) / 2); i++)
        printf("M[%d] = %d\n", i, matcomp[i]);

    // ALGORITMO PARA VERIFICAR REPETIÇÃO DE NUMEROS NA MATRIZ
    for (i = 0; i < ((n * n) / 2); i++)
        for (j = 0; j < ((n * n) / 2); j++)
            if ((matcomp[i] == matcomp[j] && (i != j)))
            {
               printf("Mi[%d] == %d\n", i, matcomp[i]);
               printf("Mj[%d] == %d", j, matcomp[j]);
               system("pause");
            }
    */
    flag = FALSE;
    if (n == 4)
    {
        for (i = (TEMPFACIL / 1000); i > 0; i--)
        {
            system("cls");
            printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
            printf("      %c   %c   %c   %c", 65, 66, 67, 68);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 1, 186, mat[0][0], 186, mat[0][1], 186, mat[0][2], 186, mat[0][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 2, 186, mat[1][0], 186, mat[1][1], 186, mat[1][2], 186, mat[1][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 3, 186, mat[2][0], 186, mat[2][1], 186, mat[2][2], 186, mat[2][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 4, 186, mat[3][0], 186, mat[3][1], 186, mat[3][2], 186, mat[3][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
            printf("Voce tem: %d segundos", i);
            Sleep(1000);
        }
        do
        {
            system("cls");
            vez++;
            printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
            printf("      %c   %c   %c   %c", 65, 66, 67, 68);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 1, 186, matgen[0][0], 186, matgen[0][1], 186, matgen[0][2], 186, matgen[0][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 2, 186, matgen[1][0], 186, matgen[1][1], 186, matgen[1][2], 186, matgen[1][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 3, 186, matgen[2][0], 186, matgen[2][1], 186, matgen[2][2], 186, matgen[2][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 4, 186, matgen[3][0], 186, matgen[3][1], 186, matgen[3][2], 186, matgen[3][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
            if ((acabou == ((n * n) / 2)))
                break;
            while (TRUE)
            {
                printf("\n\nDigite a coluna: ");
                switch(vez)
                {
                    case 0: { col = getLnCl(getSpecChar('A', 'D')); break; }
                    case 1: { col2 = getLnCl(getSpecChar('A', 'D')); break; }
                }
                printf("\nDigite a linha: ");
                switch(vez)
                {
                    case 0: { ln = getLnCl(getSpecChar(1, 4)); break; }
                    case 1: { ln2 = getLnCl(getSpecChar(1, 4)); break; }
                }
                if (((matgen[ln][col] == 219) && (vez == 0)) || ((matgen[ln2][col2] == 219) && (vez == 1)))
                    break;
                else
                    printf("\nVoce ja escolheu essa posicao!");
            }
            if (vez == 0)
                matgen[ln][col] = mat[ln][col];
            else if (vez == 1)
            {
                matgen[ln2][col2] = mat[ln2][col2];
                chances++;
            }
            if ((mat[ln][col] == mat[ln2][col2]) && (vez == 1))
            {
                score = score + 50 + (multi * score);
                multi += 0.05;
                acabou++;
                vez = -1;
            }
            else if (((vez == 1) && (mat[ln][col] != mat[ln2][col2])))
            {
                system("cls");
                printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
                printf("      %c   %c   %c   %c", 65, 66, 67, 68);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c", 1, 186, matgen[0][0], 186, matgen[0][1], 186, matgen[0][2], 186, matgen[0][3], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c", 2, 186, matgen[1][0], 186, matgen[1][1], 186, matgen[1][2], 186, matgen[1][3], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c", 3, 186, matgen[2][0], 186, matgen[2][1], 186, matgen[2][2], 186, matgen[2][3], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c", 4, 186, matgen[3][0], 186, matgen[3][1], 186, matgen[3][2], 186, matgen[3][3], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
                printf("\n\nQue pena, voce errou!!");
                Sleep(2000);
                system("cls");
                multi = 0;
                vez = -1;
                matgen[ln][col] = 219;
                matgen[ln2][col2] = 219;
            }
        } while (TRUE);
    }
    else if (n == 6)
    {
        for (i = (TEMPNORMAL / 1000); i > 0; i--)
        {
            system("cls");
            printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
            printf("      %c   %c   %c   %c   %c   %c", 65, 66, 67, 68, 69, 70);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 1, 186, mat[0][0], 186, mat[0][1], 186, mat[0][2], 186, mat[0][3], 186, mat[0][4], 186, mat[0][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 2, 186, mat[1][0], 186, mat[1][1], 186, mat[1][2], 186, mat[1][3], 186, mat[1][4], 186, mat[1][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 3, 186, mat[2][0], 186, mat[2][1], 186, mat[2][2], 186, mat[2][3], 186, mat[2][4], 186, mat[2][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 4, 186, mat[3][0], 186, mat[3][1], 186, mat[3][2], 186, mat[3][3], 186, mat[3][4], 186, mat[3][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 5, 186, mat[4][0], 186, mat[4][1], 186, mat[4][2], 186, mat[4][3], 186, mat[4][4], 186, mat[4][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 6, 186, mat[5][0], 186, mat[5][1], 186, mat[5][2], 186, mat[5][3], 186, mat[5][4], 186, mat[5][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
            printf("Voce tem: %d segundos", i);
            Sleep(1000);
        }
        do
        {
            system("cls");
            vez++;
            printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
            printf("      %c   %c   %c   %c   %c   %c", 65, 66, 67, 68, 69, 70);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 1, 186, matgen[0][0], 186, matgen[0][1], 186, matgen[0][2], 186, matgen[0][3], 186, matgen[0][4], 186, matgen[0][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 2, 186, matgen[1][0], 186, matgen[1][1], 186, matgen[1][2], 186, matgen[1][3], 186, matgen[1][4], 186, matgen[1][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 3, 186, matgen[2][0], 186, matgen[2][1], 186, matgen[2][2], 186, matgen[2][3], 186, matgen[2][4], 186, matgen[2][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 4, 186, matgen[3][0], 186, matgen[3][1], 186, matgen[3][2], 186, matgen[3][3], 186, matgen[3][4], 186, matgen[3][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 5, 186, matgen[4][0], 186, matgen[4][1], 186, matgen[4][2], 186, matgen[4][3], 186, matgen[4][4], 186, matgen[4][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 6, 186, matgen[5][0], 186, matgen[5][1], 186, matgen[5][2], 186, matgen[5][3], 186, matgen[5][4], 186, matgen[5][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
            if ((acabou == ((n * n) / 2)))
                break;
            while (TRUE)
            {
                printf("\n\nDigite a coluna: ");
                switch(vez)
                {
                    case 0: { col = getLnCl(getSpecChar('A', 'F')); break; }
                    case 1: { col2 = getLnCl(getSpecChar('A', 'F')); break; }
                }
                printf("\nDigite a linha: ");
                switch(vez)
                {
                    case 0: { ln = getLnCl(getSpecChar(1, 6)); break; }
                    case 1: { ln2 = getLnCl(getSpecChar(1, 6)); break; }
                }
                if (((matgen[ln][col] == 219) && (vez == 0)) || ((matgen[ln2][col2] == 219) && (vez == 1)))
                    break;
                else
                    printf("\nVoce ja escolheu essa posicao!");
            }
            if (vez == 0)
                matgen[ln][col] = mat[ln][col];
            else if (vez == 1)
            {
                matgen[ln2][col2] = mat[ln2][col2];
                chances++;
            }
            if ((mat[ln][col] == mat[ln2][col2]) && (vez == 1))
            {
                score = score + 50 + (multi * score);
                multi += 0.05;
                acabou++;
                vez = -1;
            }
            else if ((vez == 1) && (mat[ln][col] != mat[ln2][col2]))
            {
                system("cls");
                printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
                printf("      %c   %c   %c   %c   %c   %c", 65, 66, 67, 68, 69, 70);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 1, 186, matgen[0][0], 186, matgen[0][1], 186, matgen[0][2], 186, matgen[0][3], 186, matgen[0][4], 186, matgen[0][5], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 2, 186, matgen[1][0], 186, matgen[1][1], 186, matgen[1][2], 186, matgen[1][3], 186, matgen[1][4], 186, matgen[1][5], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 3, 186, matgen[2][0], 186, matgen[2][1], 186, matgen[2][2], 186, matgen[2][3], 186, matgen[2][4], 186, matgen[2][5], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 4, 186, matgen[3][0], 186, matgen[3][1], 186, matgen[3][2], 186, matgen[3][3], 186, matgen[3][4], 186, matgen[3][5], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 5, 186, matgen[4][0], 186, matgen[4][1], 186, matgen[4][2], 186, matgen[4][3], 186, matgen[4][4], 186, matgen[4][5], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 6, 186, matgen[5][0], 186, matgen[5][1], 186, matgen[5][2], 186, matgen[5][3], 186, matgen[5][4], 186, matgen[5][5], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
                printf("\n\nQue pena, voce errou!!");
                Sleep(2000);
                system("cls");
                multi = 0;
                vez = -1;
                matgen[ln][col] = 219;
                matgen[ln2][col2] = 219;
            }
        } while (TRUE);
    }
    else if (n == 8)
    {
        for (i = (TEMPDIFICIL / 1000); i > 0; i--)
        {
            system("cls");
            printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
            printf("      %c   %c   %c   %c   %c   %c   %c   %c", 65, 66, 67, 68, 69, 70, 71, 72);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 1, 186, mat[0][0], 186, mat[0][1], 186, mat[0][2], 186, mat[0][3], 186, mat[0][4], 186, mat[0][5], 186, mat[0][6], 186, mat[0][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 2, 186, mat[1][0], 186, mat[1][1], 186, mat[1][2], 186, mat[1][3], 186, mat[1][4], 186, mat[1][5], 186, mat[1][6], 186, mat[1][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 3, 186, mat[2][0], 186, mat[2][1], 186, mat[2][2], 186, mat[2][3], 186, mat[2][4], 186, mat[2][5], 186, mat[2][6], 186, mat[2][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 4, 186, mat[3][0], 186, mat[3][1], 186, mat[3][2], 186, mat[3][3], 186, mat[3][4], 186, mat[3][5], 186, mat[3][6], 186, mat[3][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 5, 186, mat[4][0], 186, mat[4][1], 186, mat[4][2], 186, mat[4][3], 186, mat[4][4], 186, mat[4][5], 186, mat[4][6], 186, mat[4][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 6, 186, mat[5][0], 186, mat[5][1], 186, mat[5][2], 186, mat[5][3], 186, mat[5][4], 186, mat[5][5], 186, mat[5][6], 186, mat[5][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 7, 186, mat[6][0], 186, mat[6][1], 186, mat[6][2], 186, mat[6][3], 186, mat[6][4], 186, mat[6][5], 186, mat[6][6], 186, mat[6][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 8, 186, mat[7][0], 186, mat[7][1], 186, mat[7][2], 186, mat[7][3], 186, mat[7][4], 186, mat[7][5], 186, mat[7][6], 186, mat[7][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
            printf("Voce tem: %d segundos", i);
            Sleep(1000);
        }
        do
        {
            system("cls");
            vez++;
            printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
            printf("      %c   %c   %c   %c   %c   %c   %c   %c", 65, 66, 67, 68, 69, 70, 71, 72);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 1, 186, matgen[0][0], 186, matgen[0][1], 186, matgen[0][2], 186, matgen[0][3], 186, matgen[0][4], 186, matgen[0][5], 186, matgen[0][6], 186, matgen[0][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 2, 186, matgen[1][0], 186, matgen[1][1], 186, matgen[1][2], 186, matgen[1][3], 186, matgen[1][4], 186, matgen[1][5], 186, matgen[1][6], 186, matgen[1][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 3, 186, matgen[2][0], 186, matgen[2][1], 186, matgen[2][2], 186, matgen[2][3], 186, matgen[2][4], 186, matgen[2][5], 186, matgen[2][6], 186, matgen[2][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 4, 186, matgen[3][0], 186, matgen[3][1], 186, matgen[3][2], 186, matgen[3][3], 186, matgen[3][4], 186, matgen[3][5], 186, matgen[3][6], 186, matgen[3][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 5, 186, matgen[4][0], 186, matgen[4][1], 186, matgen[4][2], 186, matgen[4][3], 186, matgen[4][4], 186, matgen[4][5], 186, matgen[4][6], 186, matgen[4][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 6, 186, matgen[5][0], 186, matgen[5][1], 186, matgen[5][2], 186, matgen[5][3], 186, matgen[5][4], 186, matgen[5][5], 186, matgen[5][6], 186, matgen[5][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 7, 186, matgen[6][0], 186, matgen[6][1], 186, matgen[6][2], 186, matgen[6][3], 186, matgen[6][4], 186, matgen[6][5], 186, matgen[6][6], 186, matgen[6][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 8, 186, matgen[7][0], 186, matgen[7][1], 186, matgen[7][2], 186, matgen[7][3], 186, matgen[7][4], 186, matgen[7][5], 186, matgen[7][6], 186, matgen[7][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
            if ((acabou == ((n * n) / 2)))
                break;
            while (TRUE)
            {
                printf("\n\nDigite a coluna: ");
                switch(vez)
                {
                    case 0: { col = getLnCl(getSpecChar('A', 'H')); break; }
                    case 1: { col2 = getLnCl(getSpecChar('A', 'H')); break; }
                }
                printf("\nDigite a linha: ");
                switch(vez)
                {
                    case 0: { ln = getLnCl(getSpecChar(1, 8)); break; }
                    case 1: { ln2 = getLnCl(getSpecChar(1, 8)); break; }
                }
                if (((matgen[ln][col] == 219) && (vez == 0)) || ((matgen[ln2][col2] == 219) && (vez == 1)))
                    break;
                else
                    printf("\nVoce ja escolheu essa posicao!");
            }
            if (vez == 0)
                matgen[ln][col] = mat[ln][col];
            else if (vez == 1)
            {
                matgen[ln2][col2] = mat[ln2][col2];
                chances++;
            }
            if ((mat[ln][col] == mat[ln2][col2]) && (vez == 1))
            {
                score = score + 50 + (multi * score);
                multi += 0.05;
                acabou++;
                vez = -1;
            }
            else if ((vez == 1) && (mat[ln][col] != mat[ln2][col2]))
            {
                system("cls");
                printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
                printf("      %c   %c   %c   %c   %c   %c   %c   %c", 65, 66, 67, 68, 69, 70, 71, 72);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 1, 186, matgen[0][0], 186, matgen[0][1], 186, matgen[0][2], 186, matgen[0][3], 186, matgen[0][4], 186, matgen[0][5], 186, matgen[0][6], 186, matgen[0][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 2, 186, matgen[1][0], 186, matgen[1][1], 186, matgen[1][2], 186, matgen[1][3], 186, matgen[1][4], 186, matgen[1][5], 186, matgen[1][6], 186, matgen[1][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 3, 186, matgen[2][0], 186, matgen[2][1], 186, matgen[2][2], 186, matgen[2][3], 186, matgen[2][4], 186, matgen[2][5], 186, matgen[2][6], 186, matgen[2][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 4, 186, matgen[3][0], 186, matgen[3][1], 186, matgen[3][2], 186, matgen[3][3], 186, matgen[3][4], 186, matgen[3][5], 186, matgen[3][6], 186, matgen[3][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 5, 186, matgen[4][0], 186, matgen[4][1], 186, matgen[4][2], 186, matgen[4][3], 186, matgen[4][4], 186, matgen[4][5], 186, matgen[4][6], 186, matgen[4][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 6, 186, matgen[5][0], 186, matgen[5][1], 186, matgen[5][2], 186, matgen[5][3], 186, matgen[5][4], 186, matgen[5][5], 186, matgen[5][6], 186, matgen[5][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 7, 186, matgen[6][0], 186, matgen[6][1], 186, matgen[6][2], 186, matgen[6][3], 186, matgen[6][4], 186, matgen[6][5], 186, matgen[6][6], 186, matgen[6][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 8, 186, matgen[7][0], 186, matgen[7][1], 186, matgen[7][2], 186, matgen[7][3], 186, matgen[7][4], 186, matgen[7][5], 186, matgen[7][6], 186, matgen[7][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
                printf("\n\nQue pena, voce errou!!");
                Sleep(2000);
                system("cls");
                multi = 0;
                vez = -1;
                matgen[ln][col] = 219;
                matgen[ln2][col2] = 219;
            }
        } while (TRUE);
    }
    printf("\n\nParabens!!!");
    printf("\nO calculo da pontuacao ira iniciar");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    system("cls");
    score = scoreCalc(n, chances, score);
    for (j = 0; j < 10; j++)
    {
        if (score > rk.score[j])
        {
            flag = TRUE;
            printf("NEW RECORD!!!!!!!!!\n\n");
            break;
        }
        else
            flag = FALSE;
    }
    printf("\n\n\nFinal Score: %d\n\n", score);
    if (flag == TRUE)
    {
        organizarRank(j);
        strcpy(rk.nome[j], "          ");
        rk.score[j] = score;
        printf("\n\nDigite seu nome: ");
        for (i = 0; i < 10; i++)
        {
            temp = getSpecChar('A', 'Z');
            if (temp == 13)
                break;
            else
                rk.nome[j][i] = temp;
        }
        printf("\n\nAgora seu nome esta no ranking!!!\n\n");
    }
}

int getLnCl(int gen)
{
    switch(gen)
    {
        case 'A': { gen = 0; break; }
        case 'a': { gen = 0; break; }
        case 'B': { gen = 1; break; }
        case 'b': { gen = 1; break; }
        case 'C': { gen = 2; break; }
        case 'c': { gen = 2; break; }
        case 'D': { gen = 3; break; }
        case 'd': { gen = 3; break; }
        case 'E': { gen = 4; break; }
        case 'e': { gen = 4; break; }
        case 'F': { gen = 5; break; }
        case 'f': { gen = 5; break; }
        case 'G': { gen = 6; break; }
        case 'g': { gen = 6; break; }
        case 'H': { gen = 7; break; }
        case 'h': { gen = 7; break; }
        case '1': { gen = 0; break; }
        case '2': { gen = 1; break; }
        case '3': { gen = 2; break; }
        case '4': { gen = 3; break; }
        case '5': { gen = 4; break; }
        case '6': { gen = 5; break; }
        case '7': { gen = 6; break; }
        case '8': { gen = 7; break; }
    }
    return gen;
}

void printRank()
{
    int i;

    system("cls");
    printf("------------ RANKING ----------\n\n");
    printf("       NOME             SCORE\n");
    for (i = 0; i < 10; i++)
        printf(" #%2d  %s          %d\n", i + 1, rk.nome[i], rk.score[i]);
    printf("\n\n");
}

int scoreCalc(int lvl, int chances, int score)
{
    int i, temp;

    for (i = 0; i < 20; i++)
    {
        system("cls");
        printf("\n\n\nFinal Score: ");
        temp = rand() % 50000;
        printf("%d", temp);
        Sleep(100);
    }
    system("cls");
    if (chances == ((lvl * lvl) / 2))
        return (score * 1.4);
    else if ((chances >= ((lvl * lvl) / 2)) && (chances <= (lvl * lvl)))
        return (score * 1.2);
    else if ((chances >= (lvl * lvl)) && (chances <= ((lvl * lvl) + (2 * lvl))))
        return (score * 1.1);
    else if (((chances > (lvl * lvl) + (2 * lvl))) && (chances <= ((lvl * lvl) * 2 + lvl)))
        return score;
    else if ((chances > ((lvl * lvl) * 2 + lvl)))
        return score - (15 * chances);
    return 0;
}

void about()
{
    system("cls");
    printf("      ENTENDENDO A PONTUACAO\n\n");
    printf("   1 - A cada acerto voce recebe +5%% de BONUS.\n");
    printf("   2 - Se voce errar, seu BONUS e ZERADO.\n");
    printf("   3 - Quanto mais CHANCES voce usar, menor sera o seu SCORE\n\n");
    printf("       FORMULA DA PONTUACAO\n\n");
    printf("  LVL = dimensao da matriz do nivel escolhido (4 || 6 || 8)\n");
    printf("  SCORE = pontuacao feita durante o jogo\n");
    printf("  CHANCES = quantidade de chances usadas para vencer o jogo\n\n");
    printf("CHANCES = ((LVL * LVL) / 2), SCORE + 40%%\n");
    printf("CHANCES > ((LVL * LVL) / 2) E CHANCES <= (LVL * LVL), SCORE + 20%%\n");
    printf("CHANCES > (LVL * LVL) E CHANCES <= ((LVL * LVL) + (2 * LVL)), SCORE + 10%%\n");
    printf("CHANCES > ((LVL * LVL) + (2 * LVL)) E CHANCES <= ((LVL * LVL) * 2 + LVL), +0%%\n");
    printf("CHANCES > ((LVL * LVL) * 2 + LVL), seu SCORE recebe - (15 * CHANCES)\n\n");
}

void organizarRank(int pos)
{
    int i;

    for (i = 8; i >= pos; i--)
    {
        strcpy(rk.nome[i + 1], rk.nome[i]);
        rk.score[i + 1] = rk.score[i];
    }
}
