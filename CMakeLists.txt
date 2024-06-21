cmake_minimum_required(VERSION 3.18)

project(re2c-example)
find_program(RE2C_PROGRAM "re2c" REQUIRED)
message(STATUS "Found re2c: ${RE2C_PROGRAM}")

add_library(ParseYMD "ParseYMD.c")
target_include_directories(ParseYMD PUBLIC ".")
add_custom_command(OUTPUT "ParseYMD.c"
  COMMAND "${RE2C_PROGRAM}" -o "ParseYMD.c" "${CMAKE_CURRENT_SOURCE_DIR}/ParseYMD.re"
  DEPENDS "ParseYMD.re")

add_executable(ParseYMD_exe "Main.c")
target_link_libraries(ParseYMD_exe ParseYMD)
set_target_properties(ParseYMD_exe PROPERTIES OUTPUT_NAME "ParseYMD")
