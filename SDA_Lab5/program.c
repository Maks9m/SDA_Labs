#include <stdio.h>
#include <stdbool.h>

void MakeMatrix(int a, int b, float M[a][b], int B, int T);

int main(void)
{
    float M[8][9] = {
    {  5.72,   3.34,   9.78,   9.08,   9.03,   7.49,   9.90,   8.36,   9.37 },
    {  3.99,  -0.01,   9.78,  -0.12,   7.43,   7.25,   6.76,  -1.18,   8.02 },
    {  4.83,  -0.54,   5.00,  -7.49,   7.35,   5.61,   6.27,  -1.29,   4.31 },
    { -1.95,  -1.92,   5.00,  -7.49,   7.35,  -1.82,   0.00,  -1.36,  -3.14 },
    { -2.50,  -3.15,   5.00,  -7.84,   6.75,  -4.36,   0.00,  -4.73,  -4.03 },
    { -5.34,  -4.73,  -5.37,  -7.91,   6.24,  -5.45,  -7.90,  -5.89,  -4.13 },
    { -6.02,  -4.78,  -6.29,  -8.06,   5.15,  -7.90,  -9.38,  -6.65,  -8.02 },
    { -7.79,  -7.75,  -7.03,  -8.81,   1.10,  -9.41,  -9.63,  -8.70,  -8.94 }
    };

    int a = 8;        // Кількість рядків
    int b = 9;        // Кількість стовпчиків
    int B = 0, T = 5; // Шуканий діапазон [B, T]
    int U, D;         // Верхня й нижня границі пошуку
    int A;            // Середина діапазону

    MakeMatrix(a, b, M, B, T); // Вивести задану матрицю

    // Алгоритм №1
    for (int j = 0; j < b; j++)
    {
        bool found = false;
        U = 0;
        D = a - 1;
        A = (U + D) / 2; // Середній елемент
        while (U <= D && found == false)
        {
            // Якщо елемент більше шуканого діапазону
            if (M[A][j] > T)
            {
                U = A + 1; // Рухаємо верхню границю
                A = (U + D) / 2;
            }
            else
            {
                // Якщо елемент менше шуканого діапазону
                if (M[A][j] < B)
                {
                    D = A - 1; // Рухаємо нижню границю
                    A = (U + D) / 2;
                }
                // Якщо входить в шуканий діапазон
                else
                {
                    printf("B %i-му стовпчику знайдено елемент %.2f за координатами (%i, %i)\n", j, M[A][j], A, j);
                    found = true;
                    continue;
                }
            }
        }
        if (found == false)
        {
            printf("B %i-му стовпчику не знайдено шуканого елементу\n", j);
        }
    }
}

void MakeMatrix(int a, int b, float M[a][b], int B, int T)
{
    printf("\nMaтpиця [%i, %i]:\n", a, b);
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            // Bиділення шуканих елементів
            if (M[i][j] >= B && M[i][j] <= T)
            {
                printf("\033[1;31m"); // Виділите червоним кольором
                printf("%7.2f ", M[i][j]);
                printf("\033[0m"); // Прибрати колір
            }
            else
            {
                printf("\033[0m"); // Прибрати колір
                printf("%7.2f ", M[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}