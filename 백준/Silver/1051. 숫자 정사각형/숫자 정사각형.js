const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const [n, m] = input[0].split(' ').map((i) => parseInt(i));
const arr = input.slice(1).map((v) => v.split('').map((i) => parseInt(i)));

let answer = 0;
for (let k = 0; k < Math.min(n, m); k += 1) {
  for (let i = 0; i + k < n; i += 1) {
    for (let j = 0; j + k < m; j += 1) {
      const pos = [
        [i, j],
        [i + k, j],
        [i, j + k],
        [i + k, j + k],
      ];

      if (pos.every((v) => arr[v[0]][v[1]] === arr[pos[0][0]][pos[0][1]])) {
        answer = Math.max(answer, (k + 1) ** 2);
      }
    }
  }
}

console.log(answer);
