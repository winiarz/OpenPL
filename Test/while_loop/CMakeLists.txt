
file(GLOB TestWhileLoopSrc "Test/while_loop/*.cpp")

add_executable(Bin/Test/WhileLoop ${TestWhileLoopSrc})
target_link_libraries (Bin/Test/WhileLoop ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/WhileLoop ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
