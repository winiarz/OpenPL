

file(GLOB TestCopyIntegersSrc "Test/copy_integers/*.cpp")

add_executable(Bin/Test/Copy_Integers ${TestCopyIntegersSrc})
target_link_libraries (Bin/Test/Copy_Integers ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/Copy_Integers ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
