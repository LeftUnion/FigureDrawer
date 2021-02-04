set(Component "FooComponent")

find_package(Qt5 ${QT_REQUIRED_VERSION} COMPONENTS REQUIRED
  Gui
  Core
)

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${Component}
  ${HEADERS}
  ${SOURCES}
)

target_link_libraries(${Component}
  PRIVATE
    Qt5::Core
    Qt5::Gui
)


target_include_directories(${Component}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${Component}
)

add_library(${PROJECT_NAME}::${Component} ALIAS ${Component})
