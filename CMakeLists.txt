cmake_minimum_required(VERSION 3.28)
project(project_cpf_cnpj)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)
include_directories(src/headers)
include_directories(src/main)

add_executable(project_cpf_cnpj
        src/assets/imgs/project_cpf_cnpj.png
        src/headers/gerador.h
        src/headers/validador.h
        src/main/gerador.c
        src/main/projeto.c
        src/main/validador.c
        README.md)
