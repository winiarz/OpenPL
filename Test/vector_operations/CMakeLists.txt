
file(GLOB TestVetorOperationsSrc "Test/vector_operations/*.cpp")

add_executable(Bin/Test/VectorOperations ${TestVetorOperationsSrc})
target_link_libraries (Bin/Test/VectorOperations ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/VectorOperations ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
