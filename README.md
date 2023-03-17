<h1>
	fdf
</h1>

<p>
	<b>This project consists of representing a landscape as a three-dimensional object in which all surfaces are delineated.</b><br>
</p>

<p align="center">
	<img src="https://github.com/inozo22/fdf/blob/main/img/fdf_1.jpg" />
</p>

## Table of contents (Índice)
1. [Subject](#1-subject)
    - [1.1. The Instruction](#11-The-Instruction)
    - [1.2. Obligation part](#12-Obligation-part)
2. [Error control](#2-error-control)
3. [Simple plan](#3-simple-plan)

## 1. Subject
### 1.1. The Instruction
- Functions should not finish unexpectedly (segfault, bus error, double free, etc) or have undefined behaviour.
- All memory allocated on the heap shall be released appropriately when necessary. No memory leaks shall be allowed. 
- If the statement requires it, you must deliver a Makefile that will compile your source files to the required output with the -Wall, -Werror and -Wextra flags, and of course your Makefile must not relink.
- Your Makefile has to be included at least the norm $(NAME), all, clean, fclean and re.
- To deliver the bonus of your project you must include a bonus rule in your Makefile, in which you add all the headers, libraries or functions that are forbidden in the main part of the project. The bonus must be in separate_bonus. {c/h} files. The mandatory part and the bonus are evaluated separately.
- If your project allows the use of libft, you should copy its source and its associated Makefile into a libft directory with a corresponding Makefile. Your project's Makefile of your project should first compile the library using its Makefile, and then compile the project.
- It's recommended to create test programmes for your project, although this work will not be handed in or evaluated. It will give you the opportunity to verify that your software works correctly during your evaluation and that of your peers. And yes, you are allowed to use these tests during your evaluation or that of your peers.

## 2. Error control
- Number of argument is not 2 (ac != 2)
- Different number of rows or columns
- Does it have to be enclosed by 0
    - No, it can be any numbers
- Numbers are not int(IDK)
- Shouldn't accept characters
- (How many numbers of rows or columns I have to accept?)
- 

## 3. Simple plan
- Accept argument (ac, **av(fd)) I don't have to link to list, because it won't allocate any memory before enter main function
    - Error check(ac != 2)
    - pass to main function(fdf?)
        - gnl
            - error fail memory allocation (not necessary release memory)
            - error not numbers (necessary release memory)
            - error not int (necessary release memory)
            - pass to initiation (x, y and (general?))<- if it's needed
                - x = rows(列) - check all numbers of row, check the first row and the last row
                - y = columns(行) - check all numbers of columns, check the first columns and the last columns
                - general
            - pass to function draw (x, y, z, and colour)
                - x
                - y