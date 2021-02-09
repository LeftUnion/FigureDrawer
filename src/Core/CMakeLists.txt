project(Core)

set(CMAKE_AUTOMOC ON)

add_subdirectory(GeometryComponent)
list(APPEND components "GeometryComponent")

message("Found the following components:")
foreach(component ${components})
  message("  ${component}")
endforeach()

