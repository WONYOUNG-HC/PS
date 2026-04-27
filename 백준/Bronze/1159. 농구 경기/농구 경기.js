const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");
const n = parseInt(input[0]);

let ans = "";
for (let i = 97; i <= 122; i++) {
  let cnt = 0;
  for (let j = 1; j < input.length; j++) {
    if (input[j][0] === String.fromCharCode(i)) {
      cnt += 1;
    }
  }

  if (cnt >= 5) {
    ans += String.fromCharCode(i);
  }
}

console.log(ans === "" ? "PREDAJA" : ans);
