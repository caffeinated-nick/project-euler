use std::fs;
// use std::str;

fn main() {
  let mut total_sum = 0;
  let mut idx = 1;
  let alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'];

  let data = fs::read_to_string("./names.txt").expect("Unable to read file");
  for line in data.split_terminator('\n') {
    let mut current_sum = 0;
    for c in line.chars() {
      current_sum += alphabet.iter().position(|&s| s == c).unwrap() + 1;
    }
    total_sum += current_sum * idx;
    idx += 1;
  }

  println!("{}", total_sum);
}
