## Introduction to Programming (In-person Test):
* Menu with CPF and CNPJ generator and checker.
* Students: Hiel Saraiva e Conrado Einstein.

## Compile multiple files into the same package in VSCode (macOS):

### First Option:
``````
gcc [file_name_1].c [file_name_2].c

./a.out
``````

### Second Option:
``````
clang -c [file_name_1].c

clang -c [file_name_2].c

clang [file_name_1].o [file_name_2].o

./a.out
``````

## Interesting observations:
### Create UNIX executable file:
``````
gcc -o [File Name].c
``````

### Create assembly code from C code:
``````
gcc -S [File Name].c
``````
