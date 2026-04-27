const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");
const [n, k] = input[0].split(" ");
let arr = [...input[1].split(" ")];
arr = arr.map((i) => parseInt(i));
arr.sort((l, r) => l - r);
console.log(arr[k - 1]);
