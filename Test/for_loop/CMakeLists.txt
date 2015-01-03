
file(GLOB TestForLoopSrc "Test/for_loop/*.cpp")

add_executable(Bin/Test/ForLoop ${TestForLoopSrc})
target_link_libraries (Bin/Test/ForLoop ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/ForLoop ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
