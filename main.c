#include <stdio.h>
#include <stdlib.h>
#include <time.h>
                                                                                                                              
#define ROW_LENGTH 138
#define ITTERATIONS 21 

typedef enum Cell {
    I,
    O,
} Cell;

typedef struct Row {
    Cell indexes[ROW_LENGTH];
} Row;

int random_number()
{
    return (rand() > RAND_MAX / 2);
}

Row random_row()
{
    Row result = {0};

    for (int i = 0; i < ROW_LENGTH; i++) {
        result.indexes[i] = (random_number() == I) ? I : O;
    }
    
    return result;
}

void print_row(Row row)
{
    printf("| ");

    for (int i = 0; i < ROW_LENGTH; i++) {
        (row.indexes[i] == I) ? printf("*") : printf(" ");
    }
    
    printf(" |\n");
}

Row calculate_row(Row curr)
{
    Row result = {0};

    for (int i = 1; i < ROW_LENGTH - 2; i++) {
        int left = curr.indexes[i - 1];
        int mid = curr.indexes[i];
        int right = curr.indexes[i + 1];
                
        if (left == O && mid == O && right == O) { result.indexes[i] = O; } 
        if (left == O && mid == O && right == I) { result.indexes[i] = I; } 
        if (left == O && mid == I && right == O) { result.indexes[i] = I; } 
        if (left == O && mid == I && right == I) { result.indexes[i] = I; } 
        if (left == I && mid == O && right == O) { result.indexes[i] = O; } 
        if (left == I && mid == O && right == I) { result.indexes[i] = I; } 
        if (left == I && mid == I && right == O) { result.indexes[i] = I; } 
        if (left == I && mid == I && right == I) { result.indexes[i] = O; } 
    }

    return result;
}

void border()
{
    printf(" -");
    
    for (int i = 0; i < ROW_LENGTH - 2; i++) {
        printf("-");
    }
    printf("---\n");
}

int main()
{
    srand(time(0));
    border();

    Row curr = {0};

    curr = random_row();
    print_row(curr);
    
    for (int i = 0; i <= ITTERATIONS; i++) {
        curr = calculate_row(curr);
        print_row(curr);
    }

    border();

    return 0;
}
