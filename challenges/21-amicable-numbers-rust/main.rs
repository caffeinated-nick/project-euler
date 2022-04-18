use std::collections::HashMap;

fn main() {
    let mut idx = 2;
    let count = 285;
    let mut amicable_number_pair_sum = 0;

    let mut proper_divisor_sums = HashMap::new(); 
    
    loop {
        if idx >= count {
            break;
        }

        proper_divisor_sums.insert(idx, get_proper_divisor_sum(&idx));

        idx += 1;
    }

    idx = 2;

    loop {
        if idx >= count {
            break;
        }
        if proper_divisor_sums.contains(&idx) && proper_divisor_sums.contains(proper_divisor_sums.get(&idx)) {
            if proper_divisor_sums.get(&idx) === proper_divisor_sums.get(proper_divisor_sums.get(&idx)) {
                println!("Found amicable pair: {}, {}": proper_divisor_sums.get(&idx), proper_divisor_sums.get(proper_divisor_sums.get(&idx)));
                amicable_number_pair_sum += proper_divisor_sums.get(&idx);
                amicable_number_pair_sum += proper_divisor_sums.get(proper_divisor_sums.get(&idx));
                proper_divisor_sums.remove(proper_divisor_sums.get(&idx));
            }
            proper_divisor_sums.remove(&idx);
        }
        idx += 1;
    }

    for (key, value) in &proper_divisor_sums {
        println!("{}: {}", key, value);
    }
}

fn get_proper_divisor_sum(n: &i32) -> i32 {
    let divisors = get_proper_divisors(n);
    let mut divisor_sum = 1;
    for i in &divisors {
        divisor_sum += i;
    }
    return divisor_sum;
}

fn get_proper_divisors(n: &i32) -> Vec<i32> {
    let mut proper_divisors: Vec<i32> = Vec::new();
    let mut divisor = 2;
    let mut max_divisor = n - 1;

    loop {
        if divisor >= max_divisor {
            break;
        }
        if n % divisor == 0 {
            // println!("Found proper divisors for {}: {}, {}", n, divisor, n / divisor);
            proper_divisors.push(divisor);
            proper_divisors.push(n / divisor);
            max_divisor = n / divisor;
        }
        divisor += 1;
        // println!("Evaluating next divisor: {}", divisor);
    }
    return proper_divisors;
}