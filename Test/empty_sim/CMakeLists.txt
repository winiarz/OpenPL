

file(GLOB TestEmptySimSrc "Test/empty_sim/*.cpp")

add_executable(Bin/Test/Empty_Simulation ${TestEmptySimSrc})
target_link_libraries (Bin/Test/Empty_Simulation ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/Empty_Simulation 
				     ${OPENPL_ALL_LIBS}
				     ${EXTERNAL_LIBS})
