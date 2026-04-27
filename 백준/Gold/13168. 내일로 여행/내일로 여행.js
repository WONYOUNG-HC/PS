const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

let [n, r] = input[0].split(" ").map(Number);
const cities = [...new Set(input[1].split(" "))];
n = cities.length;

const numbering = {};
for (let i = 0; i < n; i++) {
  numbering[cities[i]] = i;
}

const m = Number(input[2]);
const route = input[3].split(" ");
const k = Number(input[4]);

const arr1 = Array.from(new Array(n), () => new Array(n).fill(Infinity));
const arr2 = Array.from(new Array(n), () => new Array(n).fill(Infinity));
for (let i = 0; i < n; i++) {
  arr1[i][i] = 0;
  arr2[i][i] = 0;
}

for (let i = 5; i < k + 5; i++) {
  let [type, s, e, price] = input[i].split(" ");
  [s, e, price] = [numbering[s], numbering[e], Number(price)];
  arr1[s][e] = Math.min(arr1[s][e], price);
  arr1[e][s] = Math.min(arr1[e][s], price);

  if (
    type === "Mugunghwa" ||
    type === "ITX-Saemaeul" ||
    type == "ITX-Cheongchun"
  ) {
    price = 0;
  } else if (type === "S-Train" || type === "V-Train") {
    price /= 2;
  }

  arr2[s][e] = Math.min(arr2[s][e], price);
  arr2[e][s] = Math.min(arr2[e][s], price);
}

for (let k = 0; k < n; k++) {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      arr1[i][j] = Math.min(arr1[i][j], arr1[i][k] + arr1[k][j]);
      arr2[i][j] = Math.min(arr2[i][j], arr2[i][k] + arr2[k][j]);
    }
  }
}

let [p1, p2] = [0, 0];
for (let i = 1; i < m; i++) {
  const [s, e] = [numbering[route[i - 1]], numbering[route[i]]];
  p1 += arr1[s][e];
  p2 += arr2[s][e];
}

console.log(p1 > p2 + r ? "Yes" : "No");
