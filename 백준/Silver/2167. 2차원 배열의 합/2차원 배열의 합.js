const input = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');

const [n, m] = input[0].split(' ').map(Number);
const sum = Array.from({ length: n + 1 }, () => Array(m + 1).fill(0));

for (let i = 1; i <= n; i += 1) {
  const arr = [0].concat(input[i].split(' ').map(Number));

  for (let j = 1; j <= m; j += 1) {
    sum[i][j] = arr[j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
  }
}

const k = Number(input[n + 1]);

for (let i = 0; i < k; i += 1) {
  const [x1, y1, x2, y2] = input[n + 2 + i].split(' ').map(Number);

  const res = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];

  console.log(res);
}
