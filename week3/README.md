Original code output(formated by claude):
Invalid write of size 4
   at main (buggy.c:7)
 Address 0x4a7d068 is 0 bytes after a block of size 40 alloc'd
   at malloc (...vgpreload_memcheck-amd64-linux.so)
   by main (buggy.c:5)

Conditional jump or move depends on uninitialised value(s)
   at main (buggy.c:9)
 Uninitialised value was created by a stack allocation
   at main (buggy.c:3)

Invalid read of size 4
   at main (buggy.c:9)
 Address 0x4a7d068 is 0 bytes after a block of size 40 alloc'd
   at malloc (...)
   by main (buggy.c:5)

HEAP SUMMARY:
    in use at exit: 40 bytes in 1 blocks
  total heap usage: 1 allocs, 0 frees, 40 bytes allocated

40 bytes in 1 blocks are definitely lost in loss record 1 of 1
   at malloc (...)
   by main (buggy.c:5)

ERROR SUMMARY: 13 errors from 4 contexts

Fixed code output (formated by claude):
HEAP SUMMARY:
    in use at exit: 0 bytes in 0 blocks
  total heap usage: 1 allocs, 1 frees, 40 bytes allocated

All heap blocks were freed -- no leaks are possible

ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

