const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const n = +input[0];
const a = input[1]
  .split(' ')
  .map((item) => +item)
  .sort((a, b) => b - a);
const b = input[2]
  .split(' ')
  .map((item) => +item)
  .sort((a, b) => a - b);

let answer = 0;
a.forEach((numA) => {
  const numB = b.pop();

  if (numA < numB) {
    answer += 1;
  } else {
    b.push(numB);
  }
});

console.log(answer < (n + 1) / 2 ? 'NO' : 'YES');
