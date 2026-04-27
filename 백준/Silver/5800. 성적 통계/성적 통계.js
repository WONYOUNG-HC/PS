const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const k = Number(input[0]);
for (let i = 1; i <= k; i++) {
  const arr = input[i].split(" ").map(Number);
  arr.shift();

  arr.sort((l, r) => r - l);
  let dif = 0;
  for (let i = 1; i < arr.length; i++) {
    dif = Math.max(dif, arr[i - 1] - arr[i]);
  }

  console.log(`Class ${i}`);
  console.log(
    `Max ${Math.max(...arr)}, Min ${Math.min(...arr)}, Largest gap ${dif}`
  );
}
