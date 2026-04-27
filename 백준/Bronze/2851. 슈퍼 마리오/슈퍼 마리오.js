const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
let input = require("fs").readFileSync(filePath).toString().split("\n");
input = input.map((i) => parseInt(i));
for (let i = 1; i < 10; i++) {
  input[i] += input[i - 1];
}

let dif = 1000;
let ans = 0;
for (let i = 0; i < 10; i++) {
  if (Math.abs(100 - input[i]) <= dif) {
    dif = Math.abs(100 - input[i]);
    ans = i;
  }
}

console.log(input[ans]);
