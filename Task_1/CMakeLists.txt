cmake_minimum_required(VERSION 3.28)

project(Sanitizers)

set(SOURCES 
    header.h
    task_1.cpp
    adddell.cpp
    input.cpp
    inputdata.cpp
    mainmenu.cpp
    search.cpp
    change.cpp
    insertsort.cpp
    sstopinput.cpp
    outputplacess.cpp
    trains.bin
    
)

add_executable(ASan ${SOURCES})
target_compile_options(ASan PRIVATE -fsanitize=address)
target_link_libraries(ASan PRIVATE -fsanitize=address)

add_executable(TSan header.h task_1.cpp adddell.cpp input.cpp inputdata.cpp mainmenu.cpp search.cpp change.cpp insertsort.cpp sstopinput.cpp outputplacess.cpp)
target_compile_options(TSan PRIVATE -fsanitize=thread)
target_link_libraries(TSan PRIVATE -fsanitize=thread)