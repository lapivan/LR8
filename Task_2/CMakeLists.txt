cmake_minimum_required(VERSION 3.28)

project(Sanitizers)

set(SOURCES 
    header.h
    task.cpp
    main.cpp
    adddel.cpp
    input.cpp
    inputdata.cpp
    showdata.cpp
    change.cpp
    sort.cpp
    
)

add_executable(ASan ${SOURCES})
target_compile_options(ASan PRIVATE -fsanitize=address)
target_link_libraries(ASan PRIVATE -fsanitize=address)

add_executable(TSan header.h task.cpp main.cpp adddel.cpp input.cpp inputdata.cpp  showdata.cpp change.cpp sort.cpp)
target_compile_options(TSan PRIVATE -fsanitize=thread)
target_link_libraries(TSan PRIVATE -fsanitize=thread)