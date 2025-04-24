#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // declarando minhas variaveis e iniciando os contadores
    int letras; int palavras; int frases;

    letras = 0; palavras = 0; frases = 0;

    // solicitando o texto a ser analisado
    string s = get_string("Insira seu texto aqui: ");


// Itera por cada caractere da palavra e conta as letras
for (int i = 0; s[i] != '\0'; i++)
{
    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
    {letras +=1 ;}

}
// Itera por cada caractere e conta as palavras
for (int i = 0; s[i] ; i++)
{
    if(s[i] == ' ')
    palavras = palavras + 1 ;
}
    palavras +=1;

// Itera por cada caractere e conta as frases
    for (int i = 0; s[i] ; i++)
    {
        if((s[i] == '.') || (s[i] == '!') || (s[i] == '?'))
        frases +=1 ;
    }
// Calcula L e S (médias por 100 palavras)
    float L = (letras * 100.0) / palavras;
    float S = (frases * 100.0) / palavras;

    // Aplica a fórmula Coleman-Liau
    float indice = 0.0588 * L - 0.296 * S - 15.8;
    int nivel = round(indice); // Arredonda para o inteiro mais próximo

// exibe os resultados
printf("A quantidade de letras é de: %i\n ", letras);
printf("A quantidade de palavras é de: %i\n " , palavras);
printf("A quantidade de frases é de: %i\n " , frases);
printf("Índice Coleman-Liau: %i\n", nivel);
// Classifica o nível de leitura
    if (nivel >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (nivel < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", nivel);
    }

   
}
