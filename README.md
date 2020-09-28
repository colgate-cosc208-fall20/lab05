# Lab 05: Memory Errors

## Overview
In this lab, you'll identify and correct memory errors in a simple program
that allows a user to traverse a flow chart.

### Learning objectives
After completing this lab, you should be able to:
* Use valgrind to diagnose memory problems in C programs
* Determine when functions should take pointers as parameters and/or return
pointers
* Determine when values should be stored on the heap versus the stack
* Implement simple linked data structures in C

## Getting started
Visit [this page](https://classroom.github.com/a/p4MMZjiU) to create and obtain access to a private git repository
containing the starter code for the lab. After the repository is created, you
should clone your repository on a birds server.

The code you need to debug for this lab is in the `flowchart.c`
file included in your repository. When you want to compile the code, run the
command
```bash
$ make
```
which will compile the code using the commands in the `Makefile` included in
your repository. 

Use the command
```bash
$ ./flowchart
```
to run the program.

The program implements the following flowchart:
``` 
            _
         _-' '-_
      _-'       '-_
   _-'     Do you  '-_                    +------+
_-'     understand    '-_-------Yes------>| Good |
'-_    flow charts?   _-'                 +------+
   '-_             _-'                       ^
      '-_       _-'                          |
         '-_ _-'                             |
            | No                             | 
            |                                |
            V                                | Yes
         _-' '-_                          _-' '-_
      _-'       '-_                    _-'       '-_
   _-'  Okay. You  '-_              _-'   And you   '-_
_-'    see the line   '-_--Yes-->_-'    can see the    '-_
'-_      labeled      _-'        '-_    ones labeled   _-'
   '-_    "Yes"?   _-'              '-_     "No"?   _-'
      '-_       _-'                    '-_       _-'
         '-_ _-'                          '-_ _-'
            | No                             | No
            |                                |
            V                                V
         _-' '-_                          _-' '-_
      _-'       '-_                    _-'       '-_
   _-'   But you   '-_              _-'   But you   '-_
_-'    see the ones   '-_        _-'   just followed   '-_
'-_      labeled      _-'        '-_    them twice!    _-'
   |-_    "No"?    _-|              '-_             _-|
   |  '-_       _-'  |                 '-_       _-'  |
   |      '-_ _-'    |                    '-_ _-'     |
   | Yes             | No                    | No     | Yes
   |                 |                       |        |
   V                 V                       V        V
+-------------+    +-------------------+   +-------------+
| Wait, what? |    |    You need to    |   | That wasn't |
+-------------+    | learn flowcharts! |   | a question. |
                   +-------------------+   +-------------+
```
(This flowchart is derived from [this xkcd comic](https://xkcd.com/518/).)

## Debugging
Your task is to identify and correct all memory errors in the program, using
valgrind to assist you. For each error you identify, you must do the
following:
1. Describe the error in 1-2 sentences in the `errors.txt` file.
2. Modify the code in `flowchart.c` to fix the error.
3. Describe in 1-2 sentences in the `errors.txt` file *why* you chose to modify the code in the manner you did.

When you are finished, valgrind *should not report any memory errors*. (Memory
leaks are okay.)

## Challenge problem

Challenge problems are an opportunity to earn a small amount of extra credit
toward your next exam score. 

The challenge problem for this lab is to write a `cleanup` function that
frees all dynamically allocated heap memory used to store the flowchart (i.e.,
the `struct node`s). The `cleanup` function should be called at the end of
`main`. Hint: you'll need to maintain a [reference
count](https://en.wikipedia.org/wiki/Reference_counting) for each node so you
know when it can safely be deallocated.

## Submission instructions
You should **commit and push** your updated `flowchart.c` and `errors.txt`
files to your git repository. You should visit the GitHub page for your
repository and view the log and the `flowchart.c` and `errors.txt` files to
confirm you have correctly committed and pushed your changes.
