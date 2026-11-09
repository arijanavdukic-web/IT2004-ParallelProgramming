# Assignment 5

## 1. What I did

I tested the original timestep code and three optimized versions.

The goal was to see how SIMD and compiler optimizations affect execution time.

## 2. Versions

- Original - original code.
- Optimization 1 - added SIMD reduction.
- Optimization 2 - added private variables and SIMD reduction.
- Optimization 3 - moved variables inside the loop and used SIMD reduction.

## 3. Compiler results

- Original: timestep loop was not vectorized.
- Optimization 1: main loop vectorized using 32-byte vectors.
- Optimization 2: main loop vectorized using 32-byte vectors.
- Optimization 3: main loop vectorized using 32-byte vectors.
- Optimization 3 with extra flags: two loops vectorized using 32-byte vectors.

The vector width was set to 256 bits (32 bytes). Some other parts of the code were not vectorized.

## 4. Program output

All versions returned the same result:

`Minimum dt is 0.016964`

## 5. Execution times

| Version | Run 1 | Run 2 | Run 3 | Median |
|---|---:|---:|---:|---:|
| Original | 0.6987 | 0.3343 | 0.2282 | 0.3343 |
| Optimization 1 | 0.5079 | 0.5055 | 0.3601 | 0.5055 |
| Optimization 2 | 0.3024 | 0.2670 | 0.2407 | 0.2670 |
| Optimization 3 | 0.2886 | 0.2795 | 0.2443 | 0.2795 |
| Optimization 3 + extra flags | 0.4496 | 0.3326 | 0.2867 | 0.3326 |

Optimization 2 had the best median execution time.

## 6. Extra flags

I tested Optimization 3 with:

`-fno-trapping-math -fno-math-errno`

The output stayed the same, but the execution time did not improve.

## 7. Optimization comparison

- Optimization 1: SIMD reduction was added. The compiler vectorized the main loop using 32-byte vectors.
- Optimization 2: Private variables were added. The main loop was also vectorized, and this version had the best median runtime (0.2670 s).
- Optimization 3: Variables were moved inside the loop. The main loop was vectorized, but the inner loop was not.
- Extra flags: Two loops were reported as vectorized, but execution time did not improve.

The loops were not completely vectorized in every version. The compiler still reported some parts that could not be vectorized.
## 8. Compiler reports

### original
```text
main.c:10:22: optimized: loop vectorized using 32 byte vectors
main.c:20:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
main.c:22:5: missed: statement clobbers memory: printf ("Minimum dt is %lf\n", mymindt_6);
timestep.c:9:22: missed: couldn't vectorize loop
timestep.c:9:22: missed: not vectorized: unsupported control flow in loop.
timestep.c:11:25: missed: statement clobbers memory: wavespeed_46 = sqrt (_8);
timer.c:9:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:14:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
```

### opt1
```text
main.c:10:22: optimized: loop vectorized using 32 byte vectors
main.c:20:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
main.c:22:5: missed: statement clobbers memory: printf ("Minimum dt is %lf\n", mymindt_6);
timestep-opt.c:9:13: optimized: loop vectorized using 32 byte vectors
timestep-opt.c:11:9: missed: couldn't vectorize loop
timestep-opt.c:11:9: missed: not vectorized: unsupported control flow in loop.
timestep-opt.c:9:13: optimized: loop vectorized using 32 byte vectors
timestep-opt.c:12:25: missed: statement clobbers memory: wavespeed_58 = sqrt (_26);
timer.c:9:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:14:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
```

### opt2
```text
main.c:10:22: optimized: loop vectorized using 32 byte vectors
main.c:20:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
main.c:22:5: missed: statement clobbers memory: printf ("Minimum dt is %lf\n", mymindt_6);
timestep-opt-1.c:9:13: optimized: loop vectorized using 32 byte vectors
timestep-opt-1.c:11:9: missed: couldn't vectorize loop
timestep-opt-1.c:11:9: missed: not vectorized: unsupported control flow in loop.
timestep-opt-1.c:9:13: optimized: loop vectorized using 32 byte vectors
timestep-opt-1.c:12:25: missed: statement clobbers memory: wavespeed_58 = sqrt (_26);
timer.c:9:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:14:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
```

### opt3
```text
main.c:10:22: optimized: loop vectorized using 32 byte vectors
main.c:20:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
main.c:22:5: missed: statement clobbers memory: printf ("Minimum dt is %lf\n", mymindt_6);
timestep-opt-3.c:8:13: optimized: loop vectorized using 32 byte vectors
timestep-opt-3.c:10:5: missed: couldn't vectorize loop
timestep-opt-3.c:10:5: missed: not vectorized: unsupported control flow in loop.
timestep-opt-3.c:8:13: optimized: loop vectorized using 32 byte vectors
timestep-opt-3.c:11:28: missed: statement clobbers memory: wavespeed_58 = sqrt (_26);
timer.c:9:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:14:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
```

### opt3_fast
```text
main.c:10:22: optimized: loop vectorized using 32 byte vectors
main.c:20:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
main.c:22:5: missed: statement clobbers memory: printf ("Minimum dt is %lf\n", mymindt_6);
timestep-opt-3.c:8:13: optimized: loop vectorized using 32 byte vectors
timestep-opt-3.c:10:5: optimized: loop vectorized using 32 byte vectors
timestep-opt-3.c:8:13: optimized: loop vectorized using 32 byte vectors
timer.c:9:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:14:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
```
