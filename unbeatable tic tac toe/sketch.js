let board = [
  ["", "", ""],
  ["", "", ""],
  ["", "", ""]
];

let cellWidth; // = (width / 3);
let cellHeight; // = (height / 3);

let ai = "X";
let human = "O";
let currentPlayer = human;

function setup() {
  createCanvas(400, 400);
  cellWidth = width / 3;
  cellHeight = height / 3;
  bestMove();
}

function equals3(a, b, c) {
  return a == b && b == c && a != "";
}

function evaluate() {
  let winner = null;

  // horizontal
  for (let row = 0; row < 3; row++) {
    if (equals3(board[row][0], board[row][1], board[row][2])) {
      winner = board[row][0];
    }
  }

  // Vertical
  for (let col = 0; col < 3; col++) {
    if (equals3(board[0][col], board[1][col], board[2][col])) {
      winner = board[0][col];
    }
  }

  // Diagonal
  if (equals3(board[0][0], board[1][1], board[2][2])) {
    winner = board[0][0];
  }
  if (equals3(board[2][0], board[1][1], board[0][2])) {
    winner = board[2][0];
  }

  let openSpots = 0;
  for (let row = 0; row < 3; row++) {
    for (let col = 0; col < 3; col++) {
      if (board[row][col] == "") {
        openSpots++;
      }
    }
  }

  if (winner === null && openSpots === 0) {
    return "tie";
  } else {
    return winner;
  }
}

function mousePressed() {
  if (currentPlayer == human) {
    const row = floor(mouseX / cellWidth);
    const col = floor(mouseY / cellHeight);
    // Human make turn

    // If valid turn
    if (board[row][col] == "") {
      board[row][col] = human;
      currentPlayer = ai;
      bestMove();
    }
  }
}

function draw() {
  background(255);
  strokeWeight(4);

  line(cellWidth, 0, cellWidth, height);
  line(cellWidth * 2, 0, cellWidth * 2, height);
  line(0, cellHeight, width, cellHeight);
  line(0, cellHeight * 2, width, cellHeight * 2);

  // drawing of x-o in the grid
  for (let col = 0; col < 3; col++) {
    for (let row = 0; row < 3; row++) {
      let x = cellWidth * row + cellWidth / 2;
      let y = cellHeight * col + cellHeight / 2;
      let spot = board[row][col];
      textSize(32);
      let r = cellWidth / 4;
      if (spot == human) {
        // circle
        noFill();
        ellipse(x, y, r * 2);
      } else if (spot == ai) {
        // two intersected lines
        line(x - r, y - r, x + r, y + r);
        line(x + r, y - r, x - r, y + r);
      }
    }
  }

  let result = evaluate();
  if (result != null) {
    noLoop();
    // game state
    let resultP = createP("");
    resultP.style("font-size", "42pt");
    resultP.style("text-align", "center");
    resultP.style("margin-top", "10px");
    if (result == "tie") {
      resultP.style("color", "limegreen");
      resultP.html("Tie!");
    } else {
      result == "X"
        ? resultP.style("color", "red")
        : resultP.style("color", "green");
      resultP.html(`${result} wins!`);
    }
  }
}
