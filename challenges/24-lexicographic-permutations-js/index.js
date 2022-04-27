const chars = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];

class TrieNode {
  children = [];

  constructor(data) {
    this.data = data;
  }

  appendChild(child) {
    this.children.push(child);
  }
}

const root = new TrieNode("");
let count = 0;

function nextChild(currentNode, remainingChars) {
  // console.log(remainingChars);
  if(remainingChars.length === 0) {
    count += 1;
    console.log(`found term number ${count}: ${currentNode.data}`);
    if(count === 1000000) {
      console.log("found number a million")
      process.exit();
    }
    return;
  }
  for(let i = 0; i < remainingChars.length; i++) {
    const nextNode = new TrieNode(currentNode.data + remainingChars[i]);
    currentNode.appendChild(nextNode);
    nextChild(nextNode, remainingChars.filter(char => char != remainingChars[i]));
  }
}

nextChild(root, chars);