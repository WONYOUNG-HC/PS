const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

n = Number(input[0]);
for (let i = 1; i <= n; i++) {
  const str = input[i] + " is ";
  const b = str.toLowerCase().split("b").length;
  const g = str.toLowerCase().split("g").length;

  let ans;
  if (b === g) ans = str.concat("NEUTRAL");
  else if (b > g) ans = str.concat("A BADDY");
  else ans = str.concat("GOOD");
  console.log(ans);
}
