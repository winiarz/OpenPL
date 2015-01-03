
file(GLOB TestNBodySrc "Test/N_Body/*.cpp")

add_executable(Bin/Test/NBody ${TestNBodySrc})
target_link_libraries (Bin/Test/NBody ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/NBody ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
