# fdf
## Table of contents (Índice)
1. [Subject](#1-subject)
    - [1.1. The Instruction](#11-The-Instruction)
    - [1.2. blank](#12-blank)
    - [1.3. The programme](#13-the-programme)
2. [Cryptic subject](#2-cryptic-subject)
    - [2.1. How many arguments are required?](#21-how-many-arguments-are-required)
    - [2.2. How many times I can sort?](#22-how-many-times-i-can-sort)
    - [2.3. Is there any time limit?](#23-is-there-any-time-limit)
3. [Possible error](#3-possible-error)
4. [Algorithm](#4-algorithm)
    - [4.1. Quick sort](#41-quick-sort)
    - [4.2. Insert sort](#42-insert-sort)
    - [4.3. Merge sort](#43-merge-sort)
    - [4.4. Brute-force search](#44-brute-force-search)
    - [4.5. Binary search](#45-binary-search)
    - [4.6. Ternary search](#46-ternary-search)
    - [4.7. Backtracking method (Depth-first search)](#47-backtracking-method-depth-first-search) 
5. [Reference](#5-reference)     

## 1. Subject
### 1.1. The Instruction
- Functions should not finish unexpectedly (segfault, bus error, double free, etc) or have undefined behaviour.
- All memory allocated on the heap shall be released appropriately when necessary. No memory leaks shall be allowed. 
- If the statement requires it, you must deliver a Makefile that will compile your source files to the required output with the -Wall, -Werror and -Wextra flags, and of course your Makefile must not relink.
- Your Makefile has to be included at least the norm $(NAME), all, clean, fclean and re.
- To deliver the bonus of your project you must include a bonus rule in your Makefile, in which you add all the headers, libraries or functions that are forbidden in the main part of the project. The bonus must be in separate_bonus. {c/h} files. The mandatory part and the bonus are evaluated separately.
- If your project allows the use of libft, you should copy its source and its associated Makefile into a libft directory with a corresponding Makefile. Your project's Makefile of your project should first compile the library using its Makefile, and then compile the project.
- It's recommended to create test programmes for your project, although this work will not be handed in or evaluated. It will give you the opportunity to verify that your software works correctly during your evaluation and that of your peers. And yes, you are allowed to use these tests during your evaluation or that of your peers.

### 1.2. Obligation part
|  | Detail |
| --- | --- |
| Programme's name | fdf |
| Files to be submitted | Makefile, *.h, *.c |
| Makefile | NAME, all, clean, fclean, re|
| Arguments | A file in *.fdf format|
| Authorized function | - open, close, read, write, malloc, free, perror, strerror, exit<br> - All functions of the
math library (-lm compiler option, man 3 math)<br> - all functions in the MiniLibX library<br> - ft_printf and all of functions that you have programmed|
| libft | It's permitted to use|
| Description | This project is about the creation of a simple model of a landscape.|

### 1.3. The programme
- You must write a program called push_swap that will receive as argument the stack a in the format of a list of integers. The first argument must be the one on top of the stack(be careful with the order).
- The program must display the list of instructions(shortest)
to sort the stack a, from smallest to largest where the smallest is at the top of the stack.
- The instructions should be separated using a "\n" and nothing else.
- The goal is to sort the stack with as few operation as possible. During the evaluation we will compare the number of instructions obtained by your program with a maximum instruction range.
- Your program will receive no points either if your program displays a list that is too long or if the result is not correct.
- If no parameters are specified, the program should not display anything and should return control to the user.
- In case of an error, you should display Error followed by a "\n" in the standard error output. Some of the possible errors are: arguments that are not integers, arguments greater than an int, and/or finding duplicate numbers.

## 2. Cryptic subject
### 2.1. How many arguments are required.
- At least 500.
### 2.2. How many times I can sort?
It depends on the number of arguments.
- If it's sorted, it should be 0 times.
- If there are 3 arguments, less than 4 times.
- If there are 5 arguments, less than 13 times(in the subject, it's put 6 arguments, but according to Slack we have to show the instruction shorter than 12 times with 5 arguments, also guidelines.pdf(it's a copy of correction in Urduliz)).
- 100 arguments, 700 times (until 1500 times it's acceptable, but points will be deducted)
- 500 arguments, 5500 times (until 11500 times it's acceptable, but points will be deducted)
### 2.3. Is there any time limit?
- No, but it should be reasonable time.

## 3. Possible error
- No arguments (argc should be more than 2) -> Should will be written "\n"
- It's not integer
- There are dubbed numbers
- 
## 4. Algorithm
**::(> <)::**  
If the arguments are less than 6, use Brute-force search, and then for arguments more than 6 use quick sort?  
### 4.1. Quick sort
- Quick sorting is a method of repeatedly sorting into groups of 'values less than the standard' and groups of 'values greater than the standard' by setting an appropriate standard value. First of all, I have to decide the standard(pibot)  
### 4.2. Insert sort
- Insertion sort is an alignment algorithm that takes values one by one from an "unaligned array" and inserts them in the appropriate positions in an "aligned array"
### 4.3. Merge sort
- Merge sorting is an alignment algorithm that repeatedly divides into two parts until the number of elements is one, and then returns in an aligned manner.
### 4.4. Brute-force search
- Explore all possible street numbers.
### 4.5. Binary seach
### 4.6. Ternary seach
### 4.7. Backtracking method (Depth-first search)
- Depth-first search is an algorithm for exploning graphs and tree structures, in which the path does not return until it comes across a dead-end node where no further progress can be made, and then proceeds through neighbouring nodes.  


### memo

    -1. if the number of turn is same as the turn is recorded -> goodbye  
    (Because there is no possibility to be shorter than that)
        -2. if STACK a is sorted, update the record and exit
            -3. start check all commands
            while check all of them...
                -4. if there is command redundant, quit and go back to 3
                    -5. change the STACK
                        -6. reenter to 1
                            (-?. depth first check?)
So, I can check all of commands one by one, but also cut some cases in line 1 and 4

Theoretically, it is able to count until 8 turns
(with simple calculation, normally takes 1s for 10000 * 10000 times, as I have 11 commands, 11^8 = 214358881 so it will take 2s more or less.)   
*review required*  
If I will check all case one by one, I may be able to omit 1.? (If so, I only need once to record the first turn)  
This will be simpler than memo, maybe do it simply first, and then if there is problem, change?  
*review required* 

## 5. Reference
- doubly-circularly-linked list  
(JP)https://cattech-lab.com/science-tools/simulation-lecture-mini-6/  
(JP)https://programming-place.net/ppp/contents/algorithm/data_struct/004.html  
- algorithm  
(EN)https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e  
(JP)https://www.edrawsoft.com/jp/explain-algorithm-flowchart.html  
- in general  
(EN)https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

