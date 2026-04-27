const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const vo = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"];
for (let i = 0; ; i++) {
  if (input[i] === "#") {
    break;
  }
  let cnt = 0;
  for (const c of input[i]) {
    vo.includes(c) && cnt++;
  }
  console.log(cnt);
}
