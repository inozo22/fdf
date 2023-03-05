# fdf
## Table of contents (Índice)
1. [Subject](#1-subject)
    - [1.1. The Instruction](#11-The-Instruction)
    - [1.2. Obligation part](#12-Obligation-part)

## 1. Subject
### 1.1. The Instruction
- Functions should not finish unexpectedly (segfault, bus error, double free, etc) or have undefined behaviour.
- All memory allocated on the heap shall be released appropriately when necessary. No memory leaks shall be allowed. 
- If the statement requires it, you must deliver a Makefile that will compile your source files to the required output with the -Wall, -Werror and -Wextra flags, and of course your Makefile must not relink.
- Your Makefile has to be included at least the norm $(NAME), all, clean, fclean and re.
- To deliver the bonus of your project you must include a bonus rule in your Makefile, in which you add all the headers, libraries or functions that are forbidden in the main part of the project. The bonus must be in separate_bonus. {c/h} files. The mandatory part and the bonus are evaluated separately.
- If your project allows the use of libft, you should copy its source and its associated Makefile into a libft directory with a corresponding Makefile. Your project's Makefile of your project should first compile the library using its Makefile, and then compile the project.
- It's recommended to create test programmes for your project, although this work will not be handed in or evaluated. It will give you the opportunity to verify that your software works correctly during your evaluation and that of your peers. And yes, you are allowed to use these tests during your evaluation or that of your peers.

