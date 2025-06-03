#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Aqui defino a função para criptografar
void cripto_text(string texto);

int main(void)
{
    // Solicita o texto do usuário
    string texto = get_string(" ");

    // Chamo a função de criptografia
    cripto_text(texto);

    return 0;
}
void cripto_text(string texto)
{
    printf("Texto criptografado: ");

    // Itera por cada caractere do texto
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
    char c = texto[i];
     // Verifica se é uma letra maiúscula
     if (c >= 'A' && c <= 'Z')
     {
         // Aplica a cifra de César (+2)
         c = 'A' + (c - 'A' + 2) % 26;
     }
     // Verifica se é uma letra minúscula
     else if (c >= 'a' && c <= 'z')
     {
         // Aplica a cifra de César (+2)
         c = 'a' + (c - 'a' + 2) % 26;
     }

     // Imprime o caractere (criptografado ou não)
     printf("%c", c);
 }

 printf("\n");
}
