const input = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');

const [a1, a0] = input[0].split(' ').map(Number);
const c = Number(input[1]);
const n0 = Number(input[2]);

const f = (n) => a1 * n + a0;
const g = (n) => n;

let ans = true;

for (let n = n0; n <= 100; n += 1) {
  ans &= f(n) <= c * g(n);
}

console.log(+ans);
