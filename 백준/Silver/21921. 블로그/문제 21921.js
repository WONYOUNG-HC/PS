const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const [n, x] = input[0].split(" ").map(Number);
const arr = input[1].split(" ").map(Number);

let s = 1,
  e = x;

let sum = 0;
for (let i = 0; i < e; i++) {
  sum += arr[i];
}
// console.log(`s ${0}, e ${x - 1} : ${sum}`);
let mx = sum,
  cnt = 1;
while (e < arr.length) {
  sum -= arr[s - 1];
  sum += arr[e];
  // console.log(`s ${s}, e ${e} : ${sum}`); 

  if (sum > mx) {
    mx = sum;
    cnt = 1;
  } else if (sum === mx) {
    cnt += 1;
  }

  s++, e++;
}

console.log(mx > 0 ? mx : "SAD");
if (mx > 0) {
  console.log(cnt);
}
