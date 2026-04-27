const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const DIR = [
  [1, 0],
  [0, 1],
];

const n = parseInt(input[0]);
const arr = input.slice(1).map((v) => v.split(''));

const count = () => {
  let ret = 0;

  for (let i = 0; i < n; i += 1) {
    for (let j = 0; j < n; j += 1) {
      for (const d of DIR) {
        let y = i + d[0];
        let x = j + d[1];
        let count = 1;

        while (y >= 0 && y < n && x >= 0 && x < n && arr[y][x] === arr[i][j]) {
          count += 1;
          y += d[0];
          x += d[1];
        }

        ret = Math.max(ret, count);
      }
    }
  }

  return ret;
};

const swap = (y, x, d) => {
  const ny = y + d[0];
  const nx = x + d[1];

  if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
    return;
  }

  [arr[y][x], arr[ny][nx]] = [arr[ny][nx], arr[y][x]];
};

let answer = count();

for (let i = 0; i < n; i += 1) {
  for (let j = 0; j < n; j += 1) {
    for (const d of DIR) {
      swap(i, j, d);
      answer = Math.max(answer, count());
      swap(i, j, d);
    }
  }
}

console.log(answer);
