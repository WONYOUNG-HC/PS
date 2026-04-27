const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const dp = Array.from({ length: 21 }, () => Array.from({ length: 21 }, () => Array(21).fill(-1)));

const w = (a, b, c) => {
  if (a <= 0 || b <= 0 || c <= 0) {
    return 1;
  }

  if (a > 20 || b > 20 || c > 20) {
    return w(20, 20, 20);
  }

  if (dp[a][b][c] !== -1) {
    return dp[a][b][c];
  }

  if (a < b && b < c) {
    dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  } else {
    dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
  }

  return dp[a][b][c];
};

for (let i = 0; i < input.length - 1; i += 1) {
  const [a, b, c] = input[i].split(' ').map(Number);

  console.log(`w(${a}, ${b}, ${c}) = ${w(a, b, c)}`);
}
