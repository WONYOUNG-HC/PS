const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const [n] = input[0].split(' ').map(Number);
const shirts = input[1].split(' ').map(Number);
const [t, p] = input[2].split(' ').map(Number);

console.log(
  shirts.reduce((acc, cur) => {
    return acc + Math.ceil(cur / t);
  }, 0)
);
console.log(Math.floor(n / p), n % p);
