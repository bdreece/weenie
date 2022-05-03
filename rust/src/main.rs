fn bubble_sort(a: &mut Vec<i32>) {
    let n = a.len() - 1;
    let mut swapped = true;
    while swapped {
        swapped = false;
        for i in 0..n {
            if a[i] > a[i + 1] {
                a.swap(i, i + 1);
                swapped = true;
            }
        }
    }
}

fn main() {
    let mut a: Vec<i32> = vec![];
    for arg in std::env::args().skip(1) {
        a.push(arg.parse::<i32>().unwrap());
    }
    bubble_sort(&mut a);
    for item in a.iter() {
        print!("{}, ", item);
    }
}
