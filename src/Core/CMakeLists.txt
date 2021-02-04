project(Core)

set(CMAKE_AUTOMOC ON)

add_subdirectory(BarComponent)
list(APPEND components "BarComponent")

add_subdirectory(FooComponent)
list(APPEND components "FooComponent")

message("Found the following components:")
foreach(component ${components})
  message("  ${component}")
endforeach()

