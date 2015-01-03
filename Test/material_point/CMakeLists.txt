
file(GLOB TestMaterialPointSrc "Test/material_point/*.cpp")

add_executable(Bin/Test/MaterialPoint ${TestMaterialPointSrc})
target_link_libraries (Bin/Test/MaterialPoint ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Bin/Test/MaterialPoint ${OPENPL_ALL_LIBS} ${EXTERNAL_LIBS})
