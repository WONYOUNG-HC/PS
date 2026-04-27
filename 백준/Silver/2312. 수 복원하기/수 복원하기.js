const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");
const tc = parseInt(input[0]);

for (let i = 1; i <= tc; i++) {
  let n = parseInt(input[i]);

  const lis = [];
  let div = 2;
  while (n != 1) {
    if (n % div === 0) {
      if (lis.length === 0 || lis[lis.length - 1][0] !== div) {
        lis.push([div, 1]);
      } else {
        lis[lis.length - 1][1] += 1;
      }

      n /= div;
    } else {
      div += 1;
    }
  }

  for (const x of lis) {
    console.log(...x);
  }
}
