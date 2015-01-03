

file(GLOB TestLocalVariablesSrc "Test/local_variables/*.cpp")

add_executable(Bin/Test/Local_Variables ${TestLocalVariablesSrc})
target_link_libraries (Bin/Test/Local_Variables ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/Local_Variables ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
