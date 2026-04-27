const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const [a, b, c] = input;

console.log(+a + +b - +c);
console.log(a + b - c);
