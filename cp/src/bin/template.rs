#![allow(unused_imports, dead_code)]
use std::cmp::{min,max};
use std::fmt::Debug;
use std::io::{BufWriter, stdin, stdout, Write, Stdout};
 
fn next<T: std::str::FromStr>() -> T {
    let mut input = String::new();
    stdin().read_line(&mut input).expect("next: Failed read");
    input.trim().parse().ok().expect("next: Failed parse")
}

fn next_line<T: std::str::FromStr>() -> Vec<T>
where <T as std::str::FromStr>::Err: std::fmt::Debug
{
    let mut input = String::new();
    stdin().read_line(&mut input).expect("line: Failed read");
    return input.split_whitespace().map(|a| a.parse().expect("line: Failed to parse")).collect();
}


fn solve(_o: &mut BufWriter<Stdout>) -> bool
{
    let mut n = next::<i32>();

    // writeln!(_o, "{a} {b}").ok();
    true
}

pub fn yes_or_no(ok: bool, out: &mut BufWriter<Stdout>) {

    if ok { writeln!(out, "Yes").ok(); }
    else  { writeln!(out, "NO" ).ok(); }
}
fn main() {
    let mut out = BufWriter::new(stdout());
    let a = next::<i32>();
    // let a = 1;
    for _ in 0..a {
        // yes_or_no(solve(), &mut out);
        solve(&mut out);
    }
}
