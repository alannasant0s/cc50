#include <stdio.h>
#include <cs50.h>

// Constante -------- Essas variáveis estão no escopo global, fora da função main
// Isso significa que posso utiliza-la em qualquer lugar do meu código
const int N = 3;

// Função para clcular a média

float average(int length, float array[]);

int main(void)
{
    /*Obter as notas inseridas pelos alunos*/
    float score[N];
    for (int i = 0; i < N; i++)
    {
    score[i] = get_float("Insira a nota: ");
    }
    /*Exibe a média na tela*/
    printf("A média das notas é: %f\n", average(N, score));
}
// o codigo foi corrigido para receber notas em float

// calculando a média
float average(int length, float array[])
{

    float sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float)length;
}
