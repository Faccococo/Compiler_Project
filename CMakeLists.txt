cmake_minimum_required(VERSION 3.5)
project(splc C CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

# 查找 Flex 和 Bison
find_package(BISON)
find_package(FLEX)

# Bison 处理 syntax.y
bison_target(Parser syntax.y ${CMAKE_CURRENT_BINARY_DIR}/syntax.tab.c)

# Flex 处理 lex.l
flex_target(Lexical_Analyser lex.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c)

# 不将lex.yy.c加入到编译列表中，cmake就不会生成lex.yy.c
add_library(lex_yy ${FLEX_Lexical_Analyser_OUTPUTS})

# 添加 Bison 和 Flex 的依赖
add_flex_bison_dependency(Lexical_Analyser Parser)

# 包含 Bison 和 Flex 生成的头文件
include_directories(${CMAKE_CURRENT_BINARY_DIR} include)

# 添加所有源文件
add_executable(splc
    src/parse_tree.c
        src/semantic.c
    src/symbol.c 
    src/type.c
    src/yyerror_ow.c
    ${BISON_Parser_OUTPUTS}
        src/ir_gen.cpp
)

message(${CMAKE_CURRENT_BINARY_DIR})
message(${BISON_Parser_OUTPUTS})

# 如果需要，可以链接到其他库
# target_link_libraries(my_program other_libraries)
