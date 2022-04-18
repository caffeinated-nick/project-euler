let count = 10000;
let proper_divisor_sums = {}; 

function get_proper_divisor_sum(n) {
    let divisors = get_proper_divisors(n);
    let divisor_sum = 1;
    divisors.forEach((i) => {
        divisor_sum += i;
    });
    return divisor_sum;
}

function get_proper_divisors(n) {
    let proper_divisors = [];
    let divisor = 2;
    let max_divisor = n - 1;

    while(divisor < max_divisor) {
        if (n % divisor == 0) {
            // println!("Found proper divisors for {}: {}, {}", n, divisor, n / divisor);
            proper_divisors.push(divisor);
            proper_divisors.push(n / divisor);
            max_divisor = n / divisor;
        }
        divisor += 1;
    }
    return proper_divisors;
}

let amicable_number_pair_sum = 0;
  
for(let idx = 2; idx < count; idx++) {
  proper_divisor_sums[idx] = get_proper_divisor_sum(idx);
}

for(let i = 2; i < count; i++) {
  if(proper_divisor_sums[i] !== i && i === proper_divisor_sums[proper_divisor_sums[i]]) {
    console.log("Found an amicable pair: ", proper_divisor_sums[i], proper_divisor_sums[proper_divisor_sums[i]]);
    amicable_number_pair_sum += proper_divisor_sums[proper_divisor_sums[i]];
    delete proper_divisor_sums[proper_divisor_sums[i]];
    amicable_number_pair_sum += proper_divisor_sums[i];
  }
  delete proper_divisor_sums[i];
}

console.log(amicable_number_pair_sum);