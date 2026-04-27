const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().trim();
const arr = input.split(" ").map((i) => parseInt(i));
console.log(arr.reduce((acc, cur) => (acc += cur)));
