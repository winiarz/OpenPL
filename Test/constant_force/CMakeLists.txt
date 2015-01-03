
file(GLOB TestConstantForceSrc "Test/constant_force/*.cpp")

add_executable(Bin/Test/ConstantForce ${TestConstantForceSrc})
target_link_libraries (Bin/Test/ConstantForce ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/ConstantForce ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
