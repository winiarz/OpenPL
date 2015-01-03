
file(GLOB TestConstantsSrc "Test/constants/*.cpp")

add_executable(Bin/Test/Constants ${TestConstantsSrc})
target_link_libraries (Bin/Test/Constants ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/Constants ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
