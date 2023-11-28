#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>> &board)
{
    const int size = 9;

    // Check rows and columns
    for (int i = 0; i < size; ++i)
    {
        std::unordered_set<char> rowSet;
        std::unordered_set<char> colSet;

        for (int j = 0; j < size; ++j)
        {
            // Check rows
            if (board[i][j] != '.' && rowSet.count(board[i][j]) > 0)
            {
                return false;
            }
            rowSet.insert(board[i][j]);

            // Check columns
            if (board[j][i] != '.' && colSet.count(board[j][i]) > 0)
            {
                return false;
            }
            colSet.insert(board[j][i]);
        }
    }

    // Check 3x3 sub-boxes
    for (int i = 0; i < size; i += 3)
    {
        for (int j = 0; j < size; j += 3)
        {
            std::unordered_set<char> subBoxSet;
            for (int k = 0; k < 3; ++k)
            {
                for (int l = 0; l < 3; ++l)
                {
                    char current = board[i + k][j + l];
                    if (current != '.' && subBoxSet.count(current) > 0)
                    {
                        return false;
                    }
                    subBoxSet.insert(current);
                }
            }
        }
    }

    return true;
}

int main()
{
    const int size = 9;
    std::vector<std::vector<char>> sudokuBoard(size, std::vector<char>(size));

    // Input the Sudoku board
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cin >> sudokuBoard[i][j];
        }
    }

    // Validate the Sudoku board
    if (isValidSudoku(sudokuBoard))
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    return 0;
}