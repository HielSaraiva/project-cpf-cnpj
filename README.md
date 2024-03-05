## N2 - AV07 - Introducao à programacão (Prova Presencial):
* Menu com gerador e verificador de CPF e CNPJ
* Alunos: Hiel Saraiva e Conrado Einstein

## Compilar múltiplos ficheiros no mesmo pacote no VSCode(macOS) utilize uma das seguintes opcões de comandos:
### Primeira opcão:
``````
gcc [nome_do_arquivo1].c [nome_do_arquivo2].c

./a.out
``````

### Segunda opcão:
``````
clang -c [nome_do_arquivo1].c

clang -c [nome_do_arquivo2].c

clang [nome_do_arquivo1].o [nome_do_arquivo2].o

./a.out
``````

### Observações interessantes:
#### Criar arquivo executável UNIX:
``````
gcc -o [Nome do Arquivo].c
``````

#### Criar código em Assembly do código em C:
``````
gcc -S [Nome do Arquivo].c
``````
