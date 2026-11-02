# Global Sum – Assignment

## What is the assignment about?

This program compares five ways of adding many decimal numbers. Computers cannot represent every decimal number exactly, so small rounding errors can happen when numbers are added.

The five methods are:

1. **Standard double** – adds the values one by one using `double`.
2. **Long double** – uses `long double` for greater precision.
3. **Pairwise** – adds values in pairs and then combines the partial sums.
4. **Kahan** – keeps track of small rounding errors during addition.
5. **Knuth** – calculates and keeps the small error from each addition.

## Project files

- `main.c` creates the test data, runs the methods, and measures their execution time.
- `sum_algorithms.c` contains the five summation methods.
- `sum_algorithms.h` contains the function declarations.
- `Makefile` builds the program.
- `results.txt` contains the output from our test run.

## How did we test?

We tested arrays with sizes from 2^10 (1,024 values) to 2^24 (16,777,216 values).

Half of the values were `0.1`, and the other half were `0.0000000001`.

For every method, the program calculates the sum and compares it with a reference sum. It also measures how long the calculation takes.

- **Error** tells us how far the calculated result is from the reference sum. A smaller error means a more accurate result.
- **Runtime** tells us how many seconds the calculation took. A smaller runtime means a faster calculation in that run.

## Results for the largest array

| Method | Error | Runtime (seconds) |
|---|---:|---:|
| Standard double | 1.419517167278e-05 | 0.044870 |
| Long double | 5.379666845329e-08 | 0.062069 |
| Pairwise | 4.700950739789e-11 | 0.162659 |
| Kahan | 4.700950739789e-11 | 0.246981 |
| Knuth | 4.700950739789e-11 | 0.248264 |

These are the results from one run on our virtual machine. Runtime can change between runs and computers.

## What did we learn?

Standard `double` was generally fast, but it had the largest error. `long double` reduced the error. Pairwise, Kahan, and Knuth produced the smallest errors in our tests, but took longer.

This is important in parallel programming because a large set of values can be divided between several threads or processors. Each one calculates a partial sum, and those partial sums are combined. Since the order of floating-point additions can affect the result, the summation method can affect accuracy.

## How to build and run

Open a terminal in the project folder and run:

```bash
make clean
make
./sum_test
```

To save the output in `results.txt`, run:

```bash
./sum_test | tee results.txt
```
