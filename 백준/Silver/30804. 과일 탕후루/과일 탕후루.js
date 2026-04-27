const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const n = parseInt(input[0]);
const arr = input[1].split(' ').map((v) => parseInt(v));

const count = Array(10).fill(0);
let answer = 0;
let left = 0;
let right = 0;

while (right < n) {
  count[arr[right]] += 1;

  if (count.filter((v) => v > 0).length > 2) {
    count[arr[left]] -= 1;
    left += 1;
  }

  answer = Math.max(answer, right - left + 1);
  right += 1;
}

console.log(answer);
