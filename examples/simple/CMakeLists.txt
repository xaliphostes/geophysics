project(simple)

add_executable(${PROJECT_NAME} main.cxx)

target_link_libraries(${PROJECT_NAME}
    geophysics-shared
)

set_target_properties(simple PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DIST_DIR})
