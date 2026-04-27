const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const isbn = input[0].split('');

for (let i = 0; i < 10; i++) {
  let sum = 0;

  for (let j = 0; j < 12; j++) {
    const k = isbn[j] === '*' ? i : +isbn[j];

    if (j % 2 === 0) {
      sum += k;
    } else {
      sum += k * 3;
    }
  }

  if ((sum + +isbn[12]) % 10 === 0) {
    console.log(i);
    break;
  }
}
