

file(GLOB TestDeclareMemorySrc "Test/declare_memory/*.cpp")

add_executable(Bin/Test/Declare_Memory ${TestDeclareMemorySrc})
target_link_libraries (Bin/Test/Declare_Memory ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/Declare_Memory ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
