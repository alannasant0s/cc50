// Cria um novo indivíduo com um número de `gerações`
person *create_family(int generations)
{
    // Aloca memória para uma nova pessoa
    person *p = malloc(sizeof(person));
    if (p == NULL)
    {
        return NULL;
    }

    // Se ainda há gerações para criar
    if (generations > 1)
    {
        // Cria dois novos pais para a pessoa atual
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        // Atribui alelos à pessoa atual baseado nos alelos dos pais (aleatoriamente)
        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];
    }
    else
    {
        // Define os ponteiros dos pais como NULL (fim da árvore genealógica)
        p->parents[0] = NULL;
        p->parents[1] = NULL;
        
        // Atribui alelos aleatórios (geração inicial)
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    return p;
}

// Libera a memória de `p` e todos os seus ancestrais
void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }
    
    // Libera os pais recursivamente
    free_family(p->parents[0]);
    free_family(p->parents[1]);
    
    // Libera a pessoa atual
    free(p);
}