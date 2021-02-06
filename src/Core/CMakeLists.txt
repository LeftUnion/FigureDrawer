project(Core)

set(CMAKE_AUTOMOC ON)

add_subdirectory(BarComponent)
list(APPEND components "BarComponent")

add_subdirectory(FooComponent)
list(APPEND components "FooComponent")

add_subdirectory(GeometryComponent)
list(APPEND components "GeometryComponent")

message("Found the following components:")
foreach(component ${components})
  message("  ${component}")
endforeach()

