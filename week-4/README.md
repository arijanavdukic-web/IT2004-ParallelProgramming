# Assignment 3
In aosoa_measurment.cpp i uncommented line 28,29,30.
I added alocating and deallocateing resources (`new` and `delete[]`).
Also in make file a added test for 100M.

LINK TO SHEETS: https://docs.google.com/spreadsheets/d/1VkzvLslh4AM-5uoZpLgg-yvnXcH8ZXYH1ZdAeOfPdu0/edit?usp=sharing

## Explanation of results

- Time grows with N: 10M takes about 650 ms and 100M about 6800 ms, so 10 times more elements takes about 10 times more time.
- The vector length V almost does not change the time (the lines are flat).
- The array is filled in order, so cache lines are used well for every V. Also `rand()` is slow and takes most of the time, so it hides the layout effect.
