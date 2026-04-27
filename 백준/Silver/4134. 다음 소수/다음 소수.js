const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const tc = Number(input[0]);
for (let i = 1; i <= tc; i++) {
  let n = Number(input[i]);
  let flag = true;
  while (flag) {
    flag = false;
    if (n < 2) n = 2;
    for (let j = 2; j * j <= n; j++) {
      if (n % j == 0) {
        flag = true;
        break;
      }
    }

    !flag && console.log(n);
    n++;
  }
}
