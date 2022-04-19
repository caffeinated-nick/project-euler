fn main() {
    // println!("Let's go!");
    let mut total_sum = 0;
    let max = 28123;
    let mut abundant_numbers: Vec<i32> = Vec::new();

    for idx in 2..max {
        let current_sum = get_proper_divisor_sum(&idx);

        if current_sum > idx {
            // println!("Found an abundant number: {}, {}", idx, current_sum);
            abundant_numbers.push(idx);
        }
    }

    // for number in abundant_numbers.iter() {
    //     print!("{}, ", number)
    // }

    for idx in 1..max {
        // if idx % 100 == 0 {
            // println!("{} of {}, Total sum: {}", idx, max, total_sum);
        // }
        total_sum += get_non_abundant_sum_or_zero(&idx, &abundant_numbers);
    }
    println!("Total sum: {}", total_sum);
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
            if divisor != n / divisor {
                proper_divisors.push(n / divisor);
            }
            max_divisor = n / divisor;
        }
        divisor += 1;
        // println!("Evaluating next divisor: {}", divisor);
    }
    return proper_divisors;
}

/** 
    Kind of like cocktail shaker sort... but a search?
    Take to indices, 0 and the index of the value that is still lower than our target value.
    Sum the values of these indices, 
        if too big, we need to reduce the higher index
        if too small, we need to increase the lower one to
    If the lower one exceeds the higher one, of if the higher one hits 0 without a match,
        Then we have a match
*/  
fn get_non_abundant_sum_or_zero(n: &i32, abundant_numbers: &Vec<i32>) -> i32 {
    let mut low_index = 0;
    let mut high_index: usize = get_max_index(n, abundant_numbers);

    loop {
        // println!("low index: {}, low value: {}, high index: {}, high value: {}, n: {}", low_index, abundant_numbers[low_index], high_index, abundant_numbers[high_index], n);
        let sum = abundant_numbers[low_index] + abundant_numbers[high_index];
        if sum == *n {
            // This is an abundant sum
            return 0;
        } else if sum > *n {
            // Too big, need to go smaller
            if high_index == 0  {
                // Can't go smaller... therefore, this is a non-abundant sum!
                return *n;
            }
            high_index -= 1;
        } else if sum < *n {
            // Too small, need to go bigger
            low_index += 1;
        }
        if low_index > high_index {
            // This is a non-abundant-sum! 
            // println!("Found a non-abundant-sum: {}", *n);
            return *n;
        }
    }
}

fn get_max_index(n: &i32, abundant_numbers: &Vec<i32>) -> usize {
    for (index, value) in abundant_numbers.iter().enumerate() {
        if value > n {
            return index;
        }
    }
    return abundant_numbers.len() - 1;
}