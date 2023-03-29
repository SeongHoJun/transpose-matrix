#include <stdio.h>
#include <stdlib.h>   //malloc, free

int main()
{
    int rows, cols, terms;
    int** matrix, ** transpose;
    printf("Enter the size of rows and colums, the number of non-zero terms: ");
    scanf_s("%d %d %d", &rows, &cols, &terms);

    matrix = (int**)malloc(sizeof(int*) * rows);   //2���� �迭 ���� ��

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * cols);   //1���� �迭 ���� ��
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }


    //��, ���� �� �ֱ�
    int row = 0, col = 0, value = 0;
    printf("Enter row, column, and value pairs in order:\n");
    for (int i = 0; i < terms; i++)
    {
        scanf_s("%d %d %d", &row, &col, &value);
        if (row < rows && col < cols)
        {
            matrix[row][col] = value;
        }
    }

    //��ġ����� ������ ���ο� 2���� �迭 �Ҵ�
    transpose = (int**)malloc(sizeof(int*) * cols);

    for (int i = 0; i < cols; i++)
    {
        transpose[i] = (int*)malloc(sizeof(int) * rows);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = 0 ;
        }
    }

    // ��ġ ��� ���
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }


    // ��ġ ��� ���
    printf("The transposed matrix is:\n");

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (transpose[i][j] != 0)  // ���� 0�� �ƴ� ��쿡�� ���
            {
                printf("%d %d %d\n ",i,j,transpose[i][j]);
            }
        }
    }

    // �޸� ����
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < cols; i++)
    {
        free(transpose[i]);
    }
    free(transpose);


    return 0;
}