#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

// Aqui eu crio o array com as pontuações para cada letra (A-Z), fora da função main
int POINTS[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
// Aqui defino a função para receber inteiros
int compute_score(string word);

int main(void)
{

    // solicito que o usuario insira as palavras para serem comparadas
    string player1 = get_string("Player 1: Digite sua palavra: ");
    string player2 = get_string("Player 2: Digite sua palavra: ");
    // calcula as pontuações
    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    // Determina o vencedor
    if (score1 > score2)
    {
        printf("Player1 Venceu!!\n");
    }
    else if (score2 > score1)
    {
        printf("Player2 Venceu!!\n");
    }
    else
    {
        printf("Ocorreu empate!!\n");
    }
}

//função que compara as palavras
int compute_score(string word)
{
    int score = 0;
    // Itera por cada caractre da palavra
    for (int i = 0; word[i] != '\0'; i++)
    {
        char c = toupper(word[i]); // Converte para maiúscula

         // Verifica se é uma letra válida (A-Z)
         if (c >= 'A' && c <= 'Z')
         {
             // Calcula o índice no array POINTS (A=0, B=1, etc.)
             int index = c - 'A';
             score += POINTS[index];
    }
    // Ignora caracteres que não são letras
}
    return score;
}
