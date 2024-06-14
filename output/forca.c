#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void abertura()
{
    printf("********************\n");
    printf("* JOGO DE FORCA *\n");
    printf("********************\n");
}

void desenhaForca(int erro)
{
    switch (erro)
    {
    case 0:
        printf("\n---------------");
        printf("\n|             |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
        break;
    case 1:
        printf("\n---------------");
        printf("\n|             |");
        printf("\n|             O");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
        break;
    case 2:
        printf("\n---------------");
        printf("\n|             |");
        printf("\n|             O");
        printf("\n|             |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
        break;
    case 3:
        printf("\n---------------");
        printf("\n|             |");
        printf("\n|             O");
        printf("\n|            /|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
        break;
    case 4:
        printf("\n---------------");
        printf("\n|             |");
        printf("\n|             O");
        printf("\n|            /|\\");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
        break;
    case 5:
        printf("\n---------------");
        printf("\n|             |");
        printf("\n|             O");
        printf("\n|            /|\\");
        printf("\n|            /");
        printf("\n|");
        printf("\n|");
        printf("\n-");
        break;
    case 6:
        printf("\n---------------");
        printf("\n|             |");
        printf("\n|             O");
        printf("\n|            /|\\");
        printf("\n|            / \\");
        printf("\n|");
        printf("\n|          PERDEU O JOGO!");
        printf("\n-");
    default:
        break;
    }
}

int main()
{
    char palavraSecreta[20];
    char chutes[20];
    int tamanho;
    int acertou = 0;
    int erros = 0;
    abertura();
    printf("Digite a palavra secreta: ");
    scanf("%s", palavraSecreta);
    tamanho = strlen(palavraSecreta);
    for (int i = 0; i < tamanho; i++)
    {
        chutes[i] = '_';
    }

    while (acertou < tamanho && erros < 7)
    {
        printf("\n");
        desenhaForca(erros);
        printf("\nPalavra Secreta: ");
        for (int i = 0; i < tamanho; i++)
        {
            printf("%c ", chutes[i]);
        }
        char chute;
        printf("\nDigite a letra: ");
        scanf(" %c", &chute);
        int existe = 0;
        for (int i = 0; i < tamanho; i++)
        {
            if (palavraSecreta[i] == chute)
            {
                chutes[i] = chute;
                acertou++;
                existe = 1;
            }
        }

        if (!existe)
        {
            erros++;
        }
        if (existe == tamanho)
        {
            printf("Parabens, voce ganhou!\n");
            break;
        }
        if (erros == 7)
        {
            break;
        }
        
    }

    return 0;
}
