let scores = {
  X: 10,
  O: -10,
  tie: 0
};

function bestMove() {
  // AI makes its turn
  let bestScore = -Infinity;
  let move;

  for (let row = 0; row < 3; row++) {
    for (let col = 0; col < 3; col++) {
      // Is the spot available?
      if (board[row][col] === "") {
        board[row][col] = ai;
        let score = minimax(board, 0, false);
        board[row][col] = ""; // undo your move

        if (score > bestScore) {
          bestScore = score;
          move = { row, col };
        }
      }
    }
  }
  board[move.row][move.col] = ai;
  currentPlayer = human;
}

function minimax(board, depth, isMaximizer) {
  let result = evaluate();
  if (result !== null) {
    return scores[result];
  }

  if (isMaximizer) {
    let bestScore = -Infinity;
    for (let row = 0; row < 3; row++) {
      for (let col = 0; col < 3; col++) {
        // Is the spot available?
        if (board[row][col] === "") {
          board[row][col] = ai;
          let score = minimax(board, depth + 1, false);
          board[row][col] = ""; // undo your move
          bestScore = max(score, bestScore);
        }
      }
    }
    return bestScore;
  } else {
    let bestScore = Infinity;
    for (let row = 0; row < 3; row++) {
      for (let col = 0; col < 3; col++) {
        // Is the spot available?
        if (board[row][col] == "") {
          board[row][col] = human;
          let score = minimax(board, depth + 1, true);
          board[row][col] = ""; // undo your move
          bestScore = min(score, bestScore);
        }
      }
    }
    return bestScore;
  }
}
