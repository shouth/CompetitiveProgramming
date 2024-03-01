cmake_minimum_required(VERSION 3.10)
project(CompetitiveProgramming)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

foreach(source ${SOURCES})
  cmake_path(GET source STEM stem)
  add_executable("${stem}" "${source}")
  target_include_directories("${stem}" PRIVATE "ac-library")
  target_compile_options("${stem}"
    PRIVATE
      -std=c++20
      -ftrapv
      -fsanitize=address,undefined
      -fno-sanitize-recover=all)
  target_link_options("${stem}"
    PRIVATE
      -fsanitize=address,undefined)
endforeach()
