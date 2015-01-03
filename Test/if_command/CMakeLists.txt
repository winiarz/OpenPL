
file(GLOB TestIfCommandSrc "Test/if_command/*.cpp")

add_executable(Bin/Test/If_Command ${TestIfCommandSrc})
target_link_libraries (Bin/Test/If_Command ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/If_Command ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
