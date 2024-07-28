cmake_minimum_required(VERSION 3.10)
project(CompetitiveProgramming)

# Fetch AtCoder Library
include(FetchContent)
FetchContent_Populate(
  ac-library
  GIT_REPOSITORY https://github.com/atcoder/ac-library.git
  GIT_TAG        v1.5.1)
add_library(ac-library INTERFACE)
target_include_directories(ac-library INTERFACE "${ac-library_SOURCE_DIR}")

# Check compiler is GCC or Clang
if(NOT CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

# Set flags for targets
function(target_set_flags target)
  target_link_libraries("${target}" PRIVATE ac-library)
  set_target_properties("${target}"
    PROPERTIES
      CXX_STANDARD 20
      CXX_STANDARD_REQUIRED YES
      CXX_EXTENSIONS NO)

  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions("${target}"
      PRIVATE
        # For libstdc++
        _GLIBCXX_DEBUG
        _GLIBCXX_DEBUG_PEDANTIC
        _GLIBCXX_DEBUG_BACKTRACE
        _FORTIFY_SOURCE=2

        # For libc++
        _LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_DEBUG)
    target_compile_options("${target}"
      PRIVATE
        -ftrapv
        -fsanitize=address,undefined
        -fno-omit-frame-pointer
        -fno-sanitize-recover=all)
    target_link_options("${target}"
      PRIVATE
        -fsanitize=address,undefined)
  endif()
endfunction()

# Create precompiled header
add_custom_command(
  OUTPUT "${CMAKE_BINARY_DIR}/pch.cpp"
  COMMAND "${CMAKE_COMMAND}" -E touch "${CMAKE_BINARY_DIR}/pch.cpp"
  VERBATIM)
add_library(pch "${CMAKE_BINARY_DIR}/pch.cpp")
target_precompile_headers(pch
  PRIVATE
    "<atcoder/all>"
    "<algorithm>"
    "<array>"
    "<bit>"
    "<bitset>"
    "<cmath>"
    "<complex>"
    "<cstdint>"
    "<deque>"
    "<functional>"
    "<initializer_list>"
    "<iomanip>"
    "<iostream>"
    "<iterator>"
    "<limits>"
    "<list>"
    "<map>"
    "<numbers>"
    "<numeric>"
    "<optional>"
    "<queue>"
    "<ranges>"
    "<set>"
    "<span>"
    "<stack>"
    "<string>"
    "<string_view>"
    "<tuple>"
    "<utility>"
    "<vector>")
target_set_flags(pch)

# Create targets
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
foreach(source ${SOURCES})
  cmake_path(GET source STEM target)
  add_executable("${target}" "${source}")
  target_precompile_headers("${target}" REUSE_FROM pch)
  target_set_flags("${target}")
endforeach()
