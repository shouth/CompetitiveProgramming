cmake_minimum_required(VERSION 3.10)
project(CompetitiveProgramming)

include(FetchContent)
FetchContent_Populate(
  ac-library
  GIT_REPOSITORY https://github.com/atcoder/ac-library.git
  GIT_TAG        v1.5.1)
add_library(ac-library INTERFACE)
target_include_directories(ac-library INTERFACE "${ac-library_SOURCE_DIR}")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

foreach(source ${SOURCES})
  cmake_path(GET source STEM stem)
  add_executable("${stem}" "${source}")
  target_link_libraries("${stem}" PRIVATE ac-library)
  target_compile_definitions("${stem}"
    PRIVATE
      "$<$<CONFIG:Debug>:_GLIBCXX_DEBUG;_GLIBCXX_DEBUG_PEDANTIC;_FORTIFY_SOURCE=2;_LIBCPP_DEBUG=1>")
  target_compile_options("${stem}"
    PRIVATE
      -std=c++20
      "$<$<CONFIG:Debug>:-ftrapv;-fsanitize=address,undefined;-fno-sanitize-recover=all>")
  target_link_options("${stem}"
    PRIVATE
      "$<$<CONFIG:Debug>:-fsanitize=address,undefined>")
endforeach()
