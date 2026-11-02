# IT 2004 - Parallel Programming

This repository has the code examples for the IT 2004 Parallel Programming labs. We add new examples every week, so the repository grows as the semester goes on.

## What this repository is for

Parallel programming means splitting work so that several processors can do it at the same time. Before we can do that well, we need to be comfortable with C, memory and measuring performance. Then we can start writing programs that run on many processes.

The examples are short programs that each focus on one idea. They are not complete projects. Read them, run them, and change them to see what happens. They are meant to go along with the lectures, not replace them.

## How it's organized

Each week has its own folder, for example `week-01` and `week-02`. If a week has more than one example, each one gets its own subfolder, like `week-02/example-01`.

Every example comes with a Makefile, so you can build and run it the same way every week. Examples that need a longer explanation also have their own README. If there is one, read it before you look at the code.

Some examples come in pairs: a version with a problem in it, and a fixed version. Compare the two and figure out what changed and why.

## Language and tools

The examples are written in C. The parallel examples use MPI. We also use tools like Valgrind and gdb to find bugs and see what a program is actually doing.
