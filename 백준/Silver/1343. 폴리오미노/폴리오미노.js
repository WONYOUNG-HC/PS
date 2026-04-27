const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const arr = input[0].split('');

for (let i = 0; i < arr.length; i += 1) {
  if (arr.slice(i, i + 4).join('') === 'XXXX') {
    for (let j = 0; j < 4; j += 1) {
      arr[i + j] = 'A';
    }

    i += 3;
  } else if (arr.slice(i, i + 2).join('') === 'XX') {
    arr[i] = 'B';
    arr[i + 1] = 'B';

    i += 1;
  } else if (arr[i] === 'X') {
    console.log(-1);
    return;
  }
}

console.log(arr.join(''));
