
file(GLOB TestMatrixOperationsSrc "Test/matrix_operations/*.cpp")

add_executable(Bin/Test/MatrixOperations ${TestMatrixOperationsSrc})
target_link_libraries (Bin/Test/MatrixOperations ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/MatrixOperations ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
