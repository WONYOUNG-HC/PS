const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

arr = Array.from({ length: 20 }, (v, i) => i + 1);
input.forEach((e) => {
  e = e.split(" ").map((e) => e - 1);
  const res = arr.slice(e[0], e[1] + 1).reverse();
  for (let i = e[0]; i <= e[1]; i++) {
    arr[i] = res[i - e[0]];
  }
});

console.log(...arr);
