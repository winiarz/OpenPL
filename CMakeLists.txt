cmake_minimum_required (VERSION 2.6)
project( OpenPL )

include_directories("${PROJECT_BINARY_DIR}/Clcc/Include"
		    "${PROJECT_BINARY_DIR}/ClPlatform/Include"
		    "${PROJECT_BINARY_DIR}/ClPlatform/Interface"
		    "${PROJECT_BINARY_DIR}/ClPlatform/Mock" 
		    "${PROJECT_BINARY_DIR}/Common/Include"
		    "${PROJECT_BINARY_DIR}/Common/Interface"
		    "${PROJECT_BINARY_DIR}/Common/Mock"
		    "${PROJECT_BINARY_DIR}/Simulation/Include"
		    "${PROJECT_BINARY_DIR}/Simulation/SimulationCreate/Include"
		    "${PROJECT_BINARY_DIR}/Simulation/SimulationCreate/Interface"
		    "${PROJECT_BINARY_DIR}/Simulation/SimulationCreate/InstructionProcessing/Include"
		    "${PROJECT_BINARY_DIR}/Simulation/SimulationCreate/InstructionProcessing/Interface"
		    "${PROJECT_BINARY_DIR}/Simulation/SimulationCreate/InstructionProcessing/VariableTypes"
		    "${PROJECT_BINARY_DIR}/Simulation/SimulationCreate/InstructionProcessing/Mock/"
		    "${PROJECT_BINARY_DIR}/Simulation/SimulationExecute/Include"
		    "${PROJECT_BINARY_DIR}/Simulation/SimulationExecute/Include/Types" 
		    "${PROJECT_BINARY_DIR}/Simulation/SimulationExecute/Include/VecTypes"
		    "${PROJECT_BINARY_DIR}/Simulation/SimulationExecute/Include/Structures")

set( CMAKE_CXX_FLAGS "-std=c++11" )

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include(ClPlatform/ClPlatfomCMakeLists.txt)
include(Clcc/ClccCMakeLists.txt)
include(Common/CommokCMakeLists.txt)
include(Simulation/SimulationCreate/SimCreateCMakeLists.txt)
include(Simulation/SimulationExecute/SimExecuteCMakeLists.txt)

set(OPENPL_ALL_LIBS SimCreate SimExecute InstructionProcessing ClPlatform Common)

set(EXTERNAL_LIBS "/usr/lib/x86_64-linux-gnu/libOpenCL.so.1"
		  "/usr/lib/libgtest.a"
		  "/usr/lib/libgtest_main.a"
		  "/usr/lib/libgmock.a"
		  "/usr/lib/libgmock_main.a"
                  "/usr/lib/x86_64-linux-gnu/libGLEW.so"
                  -pthread)

include(ClPlatform/TestClPlatformCMakeLists.txt)
include(Common/TestCommonCMakeLists.txt)
include(Simulation/SimulationCreate/InstructionProcessing/TestInstructionProcessingCMakeLists.txt)

include(Test/empty_sim/CMakeLists.txt)
include(Test/declare_memory/CMakeLists.txt)
include(Test/copy_integers/CMakeLists.txt)
include(Test/local_variables/CMakeLists.txt)
include(Test/simple_aritmetics/CMakeLists.txt)
include(Test/constants/CMakeLists.txt)
include(Test/if_command/CMakeLists.txt)
include(Test/while_loop/CMakeLists.txt)
include(Test/for_loop/CMakeLists.txt)
include(Test/vector_operations/CMakeLists.txt)
include(Test/matrix_operations/CMakeLists.txt)
include(Test/material_point/CMakeLists.txt)
include(Test/constant_force/CMakeLists.txt)
include(Test/N_Body/CMakeLists.txt)
