#include <bits\stdc++.h>
using namespace std;

const int maximizerValue = 10;
const int minimizerValue = -10;

const char player = 'x';
const char ai = 'o';

struct Move
{
    int row, col;
};

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

bool isMoveLeft(char board[3][3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == '_')
                return true;
        }
    }
    return false;
}

int minimax(char board[3][3], int depth, int isMaximizer)
{
    int score = evaluate(board);
    if (score == maximizerValue)
        return maximizerValue;
    if (score == minimizerValue)
        return minimizerValue;
    if (!isMoveLeft(board))
        return 0;

    // If this maximizer's move
    if (isMaximizer)
    {
        int best = -1000;
        // Traverse all cells
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                // Check if cell is empty
                if (board[row][col] == '_')
                {
                    // Make the move
                    board[row][col] = player;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = max(best,
                               minimax(board, depth + 1, !isMaximizer));

                    // Undo the move
                    board[row][col] = '_';
                }
            }
        }
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                // Check if cell is empty
                if (board[row][col] == '_')
                {
                    // Make the move
                    board[row][col] = ai;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                               minimax(board, depth + 1, !isMaximizer));

                    // Undo the move
                    board[row][col] = '_';
                }
            }
        }
        return best;
    }
}

Move findBestMove(char board[3][3])
{
    int bestVal = INT_MIN;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            // Check if cell is empty
            if (board[row][col] == '_')
            {
                // Make the move
                board[row][col] = player;

                int moveValue = minimax(board, 0, false);
                if (moveValue > bestVal)
                {
                    bestVal = moveValue;
                    bestMove.row = row;
                    bestMove.col = col;
                }
            }
        }
    }
    cout << "The value of the best move is : " << bestVal << endl;
    return bestMove;
}

int main()
{
    // x for maximizer player
    // o for minimizer player
    // _ empty cell
    char board[3][3] =
        {
            {'x', 'o', 'x'},
            {'o', 'o', 'x'},
            {'_', '_', '_'}};
    Move bestMove = findBestMove(board);

    cout << "The Optimal Move is : " << endl;
    cout << bestMove.row << ' ' << bestMove.col << endl;
}