const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const p = Number(input[0]);
for (let i = 1; i <= p; i++) {
  const arr = input[i].split(" ").map(Number);
  const tc = arr.shift();

  let cnt = 0;
  for (let i = 19; i > 0; i--) {
    for (let j = 0; j < i; j++) {
      if (arr[j] > arr[i]) {
        cnt++;
      }
    }
  }

  console.log(tc, cnt);
}
