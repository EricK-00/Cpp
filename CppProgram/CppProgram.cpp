#include <iostream>
#include <vector>

char board[1024][1024];
int N, maxRow, maxCol;

int PowerOf2(int power)
{
    if (power == 1)
        return 2;

    return 2 * PowerOf2(power - 1);
}

void DrawStar(int n, int mid)
{
    if (n == 0) return;

    int row = PowerOf2(n) - 1;
    //int rowEnd = row - 1;

    std::cout << "row: " << row << ", mid " << mid << std::endl;

    if (n % 2 == 0)
    {
        for (int i = row - 1; i > 0; i--)
        {
            board[i + mid][maxCol / 2 + i] = '*';
            board[i + mid][maxCol / 2 - i] = '*';
        }
        for (int i = 0; i <= maxCol / 2; i++)
        {
            board[mid][maxCol / 2 + i] = '*';
            board[mid][maxCol / 2 - i] = '*';
        }
    }
    else
    {
        //std::cout << "rS: " << rowStart << ", rE " << rowEnd << std::endl;
        for (int i = 0; i < row; i++)
        {
            board[i + mid][maxCol / 2 + i] = '*';
            board[i + mid][maxCol / 2 - i] = '*';
        }
        for (int i = 0; i <= maxCol / 2; i++)
        {
            board[row + mid][maxCol / 2 + i] = '*';
            board[row + mid][maxCol / 2 - i] = '*';
        }
    }

    DrawStar(n - 1, (row + 1) / 2);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;

    maxCol = PowerOf2(N + 1) - 3;

    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            board[i][j] = ' ';
        }
    }

    DrawStar(N, 0);

    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << '\n';
    }
}