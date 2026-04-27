const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const [n, m] = input[0].split(' ').map((i) => parseInt(i));
const strList = input.slice(1, n + 1).sort((a, b) => a.localeCompare(b));
const prefixList = input.slice(n + 1);

class Node {
  constructor() {
    this.children = Array(26).fill(null);
  }
}

class Trie {
  constructor() {
    this.root = new Node();
  }

  insert(str) {
    let cur = this.root;

    for (let i = 0; i < str.length; i++) {
      const idx = str[i].charCodeAt(0) - 'a'.charCodeAt(0);

      if (cur.children[idx] === null) {
        cur.children[idx] = new Node();
      }

      cur = cur.children[idx];
    }
  }

  isPrefix(prefix) {
    let cur = this.root;

    for (let i = 0; i < prefix.length; i++) {
      const idx = prefix[i].charCodeAt(0) - 'a'.charCodeAt(0);

      if (cur.children[idx] === null) {
        return false;
      }

      cur = cur.children[idx];
    }

    return true;
  }
}

const trie = new Trie();

strList.forEach((str) => trie.insert(str));
console.log(prefixList.filter((prefix) => trie.isPrefix(prefix)).length);
