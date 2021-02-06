project(Gui)

find_package(Qt5 ${QT_REQUIRED_VERSION} REQUIRED COMPONENTS Core Gui Widgets)

file(GLOB_RECURSE UI_GUI "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

qt5_wrap_ui(GUI_HEADERS ${UI_GUI})

add_executable(${PROJECT_NAME} ${UI_GUI} ${HEADERS} ${SOURCES} ${TEMPLATES} ${CONFIGS})

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    Qt5::Core
    Qt5::Widgets
    Core::GeometryComponent
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
