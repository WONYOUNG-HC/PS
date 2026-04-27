const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const n = +input[0];

let k = 1;
let diag = 1;

while (true) {
  if (k + diag > n) {
    break;
  }

  k += diag;
  diag += 1;
}

let row, col;

if (diag % 2 === 0) {
  row = n - k + 1;
  col = diag - (n - k);
} else {
  row = diag - (n - k);
  col = n - k + 1;
}

console.log(`${row}/${col}`);
