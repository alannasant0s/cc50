#include <stdio.h>
#include<cs50.h>


void draw(int n);
int main(void)
{
    int altura = get_int("Altura: ");
    draw(altura);
}

void draw(int n)
{
    for (int i = 0; i < n ; i++)
    {

        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}