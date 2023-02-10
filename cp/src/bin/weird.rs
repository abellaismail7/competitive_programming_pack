#![allow(unused_imports, dead_code)]
#![allow(unused_macros)]
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

fn next_tup<T: std::str::FromStr + Copy>() -> (T, T)
where <T as std::str::FromStr>::Err: std::fmt::Debug
{
    let mut input = String::new();
    stdin().read_line(&mut input).expect("line: Failed read");
    let v:Vec<T> = input
        .split_whitespace()
        .map(|s| s.parse::<T>().expect("tup: Failed to parse")).collect();
    (v[0], v[1])
}

macro_rules! repeat {
    ($n:expr, $f:expr) => {
        for _ in 0..$n {
            $f();
        }
    };
}

fn solve(_o: &mut BufWriter<Stdout>) -> bool
{
    let n = next::<usize>();

    let v = next_line();
    let mut p = Vec::new();
    p.reserve(v.len());
    v.iter().rev().fold(1, |acc, x| {
        p.push(acc*x);
        acc * x
    });

    p.reverse();

    let mut r = 1;
    for i in 0..(n - 1) {
        r *= v[i];
        if r == p[i + 1] {
            writeln!(_o, "{}", i + 1 ).ok();
            return true;
        }
    }
    writeln!(_o, "-1" ).ok();
    true
}

pub fn yes_or_no(ok: bool, out: &mut BufWriter<Stdout>) {

    if ok { writeln!(out, "Yes").ok(); }
    else  { writeln!(out, "NO" ).ok(); }
}

fn main() {
    let mut out = BufWriter::new(stdout());
    let a = next::<i32>();
    //let a = 1;
    for _ in 0..a {
        // yes_or_no(solve(), &mut out);
        solve(&mut out);
    }
}
