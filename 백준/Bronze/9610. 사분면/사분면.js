const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

n = Number(input[0]);
const ans = new Array(5).fill(0);
for (let i = 1; i <= n; i++) {
  const [x, y] = input[i].split(" ").map(Number);
  if (x * y > 0 && x > 0) ans[0]++;
  else if (x * y < 0 && x < 0) ans[1]++;
  else if (x * y > 0 && x < 0) ans[2]++;
  else if (x * y < 0 && y < 0) ans[3]++;
  else ans[4]++;
}

ans.map((e, i) => {
  if (i === 4) console.log("AXIS:", e);
  else console.log(`Q${i + 1}:`, e);
});
