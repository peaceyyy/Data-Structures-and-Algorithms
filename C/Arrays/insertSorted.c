
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertFruit(char ***fruitBasket, char *fruit, int *size)
{
    int position;
    *fruitBasket = realloc(*fruitBasket, sizeof(char *) * (*size + 1));

    for (position = 0; position < *size && strcmp(fruit, (*fruitBasket)[position]) > 0; position++)
        ;

    // memmove(&(*fruitBasket)[position + 1], &(*fruitBasket)[position], (*size - position) * sizeof(char *));
    memmove(&(*(*fruitBasket + position + 1)), &(*(*fruitBasket + position)), (*size - position) * sizeof(char *));
    // (*fruitBasket)[position] = strdup(fruit); //These two
    *(*fruitBasket + position) = strdup(fruit); //  are essentially the same

    (*size)++;
}

void printFruitBasket(char *fruitBasket[], int size)
{
    if (fruitBasket == NULL)
        printf("Fruit Basket is empty!");

    else {
        for (int i = 0; i < size; i++)
        {
            printf("%s\n", fruitBasket[i]);
        }
    } 

    printf("\n");
}

void freeFruitBasket(char ***fruitBasket, int size)
{
    for (int i = 0; i < size; i++)
    {
         free(fruitBasket[i]);
    }
    free(*fruitBasket); 
    *fruitBasket = NULL;
    
}

int main()
{
    int size = 0;
    char **fruitBasket = NULL;
    insertFruit(&fruitBasket, "Pineapple", &size);
    insertFruit(&fruitBasket, "Pineappl", &size);
    insertFruit(&fruitBasket, "Apple", &size);
    insertFruit(&fruitBasket, "App", &size);
    insertFruit(&fruitBasket, "Crocodile", &size);
    printFruitBasket(fruitBasket, size);

    freeFruitBasket(&fruitBasket, size);
    printFruitBasket(fruitBasket, size);

    return 0;
}
