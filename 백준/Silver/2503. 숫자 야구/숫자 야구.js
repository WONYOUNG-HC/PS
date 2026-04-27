const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const arr = input.slice(1).map((v) => v.split(' ').map(Number));
let answer = 0;

for (let i = 111; i < 1000; i += 1) {
  if (new Set(i.toString()).size !== 3 || i.toString().includes('0')) {
    continue;
  }

  let isPossible = true;

  arr.forEach((v) => {
    const num = v[0];
    let strike = 0;
    let ball = 0;

    for (let j = 0; j < 3; j += 1) {
      if (i.toString()[j] === num.toString()[j]) {
        strike += 1;
      } else if (i.toString().includes(num.toString()[j])) {
        ball += 1;
      }
    }

    if (strike !== v[1] || ball !== v[2]) {
      isPossible = false;
    }
  });

  if (isPossible) {
    answer += 1;
  }
}

console.log(answer);
