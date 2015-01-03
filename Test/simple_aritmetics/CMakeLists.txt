
file(GLOB TestSimpleAritmeticsSrc "Test/simple_aritmetics/*.cpp")

add_executable(Bin/Test/Simple_Aritmetics ${TestSimpleAritmeticsSrc})
target_link_libraries (Bin/Test/Simple_Aritmetics ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/Simple_Aritmetics ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
