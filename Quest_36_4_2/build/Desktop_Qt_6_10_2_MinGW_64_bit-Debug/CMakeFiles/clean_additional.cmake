# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Quest_36_4_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Quest_36_4_autogen.dir\\ParseCache.txt"
  "Quest_36_4_autogen"
  )
endif()
