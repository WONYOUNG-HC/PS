const input = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');

let [a, b, c] = input[0].split(' ').map(Number);
let [x, y, z] = input[1].split(' ').map(Number);

let ans = 0;

for (let i = 0; i < 3; i++) {
  ans += Math.min(a, x);
  ans += Math.min(b, y);
  ans += Math.min(c, z);

  const restX = Math.max(0, x - a);
  const restY = Math.max(0, y - b);
  const restZ = Math.max(0, z - c);

  a = Math.max(0, a - x);
  b = Math.max(0, b - y);
  c = Math.max(0, c - z);

  y = Math.floor(restX / 3) + (restY % 3);
  z = Math.floor(restY / 3) + (restZ % 3);
  x = Math.floor(restZ / 3) + (restX % 3);
}

console.log(ans);
