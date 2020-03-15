#include <bits\stdc++.h>
using namespace std;

const int maximizerValue = 10;
const int minimizerValue = -10;

int evaluate(char grid[3][3])
{
    // check winning state in rows
    for (int row = 0; row < 3; row++)
    {
        if (grid[row][0] == grid[row][1] && grid[row][0] == grid[row][2])
        {
            if (grid[row][0] == 'x')
                return maximizerValue;
            else if (grid[row][0] == 'o')
                return minimizerValue;
        }
    }

    // check winning state in cols
    for (int col = 0; col < 3; col++)
    {
        if (grid[0][col] == grid[1][col] && grid[0][col] == grid[2][col])
        {
            if (grid[0][col] == 'x')
                return maximizerValue;
            else if (grid[0][col] == 'o')
                return minimizerValue;
        }
    }

    // check winning state in main diagonal
    if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2])
    {
        if (grid[0][0] == 'x')
            return maximizerValue;
        else if (grid[0][0] == 'o')
            return minimizerValue;
    }

    // check winning state in anti diagonal
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
    {
        if (grid[0][2] == 'x')
            return maximizerValue;
        else if (grid[0][2] == 'o')
            return minimizerValue;
    }

    return 0; // tie state
}

int main()
{
    // x for maximizer player
    // o for minimizer player
    // _ empty cell
    char board[3][3] =
        {
            {'x', '_', 'o'},
            {'_', 'x', 'o'},
            {'_', '_', 'x'}};
    int evalValue = evaluate(board);
    cout << evalValue << endl;
}