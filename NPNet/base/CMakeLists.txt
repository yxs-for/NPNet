
aux_source_directory(. SRC)

add_library(NPNETBASE ${SRC})
target_link_libraries(NPNETBASE pthread)
add_subdirectory(test)

