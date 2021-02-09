project(Gui)

find_package(Qt5 ${QT_REQUIRED_VERSION} REQUIRED COMPONENTS Core Gui Widgets)

file(GLOB_RECURSE UI_GUI "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

qt5_wrap_ui(GUI_HEADERS ${UI_GUI})

#set(CMAKE_SYSTEM_NAME Windows)

#SET(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
#SET(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)
#SET(CMAKE_RC_COMPILER i686-w64-mingw32-windres)
#set(CMAKE_RANLIB i686-w64-mingw32-ranlib)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
#set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)

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
