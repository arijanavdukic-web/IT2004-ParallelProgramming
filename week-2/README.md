Corrected code valgrind output:

/usr/bin/make -f /home/student/CLionProjects/week-2/Makefile -C /home/student/CLionProjects/week-2 valgrind
==5940== Memcheck, a memory error detector
==5940== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==5940== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==5940== Command: ./memory_demo
==5940== 
make: Entering directory '/home/student/CLionProjects/week-2'
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./memory_demo
==5940== 
==5940== HEAP SUMMARY:
==5940==     in use at exit: 0 bytes in 0 blocks
==5940==   total heap usage: 1 allocs, 1 frees, 40 bytes allocated
==5940== 
==5940== All heap blocks were freed -- no leaks are possible
==5940== 
==5940== For lists of detected and suppressed errors, rerun with: -s
==5940== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
make: Leaving directory '/home/student/CLionProjects/week-2'

Process finished with exit code 0

Not corrected code valgrind output:

/usr/bin/make -f /home/student/CLionProjects/week-2/Makefile -C /home/student/CLionProjects/week-2 valgrind
make: Entering directory '/home/student/CLionProjects/week-2'
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./memory_demo
==6305== Memcheck, a memory error detector
==6305== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==6305== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==6305== Command: ./memory_demo
==6305== 
==6305== Invalid write of size 4
==6305==    at 0x1091A2: main (original.c:7)
==6305==  Address 0x4a6e068 is 0 bytes after a block of size 40 alloc'd
==6305==    at 0x4844818: malloc (vg_replace_malloc.c:446)
==6305==    by 0x109161: main (original.c:5)
==6305== 
==6305== Conditional jump or move depends on uninitialised value(s)
==6305==    at 0x1091D0: main (original.c:9)
==6305==  Uninitialised value was created by a stack allocation
==6305==    at 0x109149: main (original.c:3)
==6305== 
==6305== Invalid read of size 4
==6305==    at 0x1091CB: main (original.c:9)
==6305==  Address 0x4a6e068 is 0 bytes after a block of size 40 alloc'd
==6305==    at 0x4844818: malloc (vg_replace_malloc.c:446)
==6305==    by 0x109161: main (original.c:5)
==6305== 
==6305== 
==6305== HEAP SUMMARY:
==6305==     in use at exit: 40 bytes in 1 blocks
==6305==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==6305== 
==6305== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==6305==    at 0x4844818: malloc (vg_replace_malloc.c:446)
==6305==    by 0x109161: main (original.c:5)
==6305== 
==6305== LEAK SUMMARY:
==6305==    definitely lost: 40 bytes in 1 blocks
==6305==    indirectly lost: 0 bytes in 0 blocks
==6305==      possibly lost: 0 bytes in 0 blocks
==6305==    still reachable: 0 bytes in 0 blocks
==6305==         suppressed: 0 bytes in 0 blocks
==6305== 
==6305== For lists of detected and suppressed errors, rerun with: -s
==6305== ERROR SUMMARY: 14 errors from 4 contexts (suppressed: 0 from 0)
make: Leaving directory '/home/student/CLionProjects/week-2'

Process finished with exit code 0
