const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");
for (let i = 1; i <= 30; i++) {
  if (!input.includes(i.toString())) {
    console.log(i);
  }
}
