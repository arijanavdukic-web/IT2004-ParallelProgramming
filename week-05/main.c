
#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sum_algorithms.h"

#define ORDERS_OF_MAGNITUDE 1.0e9

double get_time(struct timespec start)
{
    struct timespec end;
    clock_gettime(CLOCK_MONOTONIC, &end);

    return (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec) * 1.0e-9;
}

int main(void)
{
    printf("GLOBAL SUM PRECISION AND PERFORMANCE TEST\n");
    printf("==========================================\n");

    for (int power = 10; power <= 24; power += 2) {
        long ncells = 1L << power;
        long half = ncells / 2;

        double high_value = 1.0e-1;
        double low_value = 1.0e-1 / ORDERS_OF_MAGNITUDE;

        double *energy = malloc(ncells * sizeof(double));

        if (energy == NULL) {
            printf("Memory allocation failed for 2^%d\n", power);
            return 1;
        }

        for (long i = 0; i < ncells; i++)
            energy[i] = (i < half) ? high_value : low_value;

        /* Reference sum calculated using long double */
        long double reference =
        (long double)half * (long double)high_value +
        (long double)half * (long double)low_value;

        printf("\n==========================================\n");
        printf("ARRAY SIZE: 2^%d = %ld elements\n", power, ncells);
        printf("Reference sum: %.15Lf\n", reference);
        printf("------------------------------------------\n");

        const char *names[] = {
            "Standard double",
            "Long double",
            "Pairwise",
            "Kahan",
            "Knuth"
        };

        double (*double_methods[])(double *, long) = {
            do_sum,
            NULL,
            do_pair_sum,
            do_kahan_sum,
            do_knuth_sum
        };

        for (int method = 0; method < 5; method++) {
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);

            long double result;

            if (method == 1)
                result = do_ldsum(energy, ncells);
            else
                result = double_methods[method](energy, ncells);

            double runtime = get_time(start);
            long double error = fabsl(result - reference);

            printf("%-17s | Error: %.12Le | Runtime: %.6f s\n",
                   names[method], error, runtime);
        }

        free(energy);
    }

    printf("\nAll tests completed!\n");

    return 0;
}
