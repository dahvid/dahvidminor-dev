
cmake_minimum_required (VERSION 2.6)
project (py2cpp)



SET(CMAKE_BUILD_TYPE Debug)
#SET(CMAKE_BUILD_TYPE RelWithDebInfo)



#set search for modules and module search
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/Modules)
message("CMAKE_MODULE_PATH=" ${CMAKE_MODULE_PATH})
message("CMAKE_SYSTEM_LIBRARY_PATH "  ${CMAKE_SYSTEM_LIBRARY_PATH})


#SET(CMAKE_CXX_COMPILER /usr/local/gcc-4.7.0/bin/g++)
#SET(CMAKE_CC_COMPILER /usr/local/gcc-4.7.0/bin/gcc)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	message("found Apple")
	SET(CMAKE_CXX_COMPILER /opt/local/bin/g++-mp-4.7)
	SET(CMAKE_CC_COMPILER  /opt/local/bin/gcc-mp-4.7)
ENDIF() 

#SET(CMAKE_CXX_FLAGS "-std=c++0x")

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR})

message("Building cmake files for project directory.", ${CMAKE_SOURCE_DIR})



#set search for modules and module search
IF (WIN32)
    set(CMAKE_SYSTEM_PREFIX_PATH C:/Program Files/boost/boost_1_46_1  ${CMAKE_SYSTEM_PREFIX_PATH} )
    set(CMAKE_SYSTEM_LIBRARY_PATH C:/Program Files/boost/boost_1_46_1  ${CMAKE_SYSTEM_LIBRARY_PATH} )
ELSE (WIN32)
    set(CMAKE_SYSTEM_PREFIX_PATH /opt/local /space/local ${CMAKE_SYSTEM_PREFIX_PATH} )
    set(CMAKE_SYSTEM_LIBRARY_PATH /opt/local /space/local ${CMAKE_SYSTEM_LIBRARY_PATH} )
ENDIF (WIN32)
message("CMAKE_SYSTEM_LIBRARY_PATH "  ${CMAKE_SYSTEM_LIBRARY_PATH})

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(PYTHON_LIBRARIES /opt/local/lib/libpython2.6.dylib)
	set(PYTHON_INCLUDE_PATH /opt/local/Library/Frameworks/Python.framework/Versions/2.6/Headers)
ELSE()
	find_package(PythonLibs REQUIRED)
ENDIF()
message("found Python libraries "  ${PYTHON_LIBRARIES})
message("found Python includes "  ${PYTHON_INCLUDE_PATH})

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	#set(BOOST_ROOT /product/grape/data/boosts/1_48_rhe6) 1_45_cent5.5
	set(BOOST_ROOT /product/grape/data/boosts/1_53_cent5.5) 
	add_definitions(-Dlinux)
ENDIF()

set(Boost_ADDITIONAL_VERSIONS "1.48")
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREAD ON)
find_package(Boost 1.48 COMPONENTS python REQUIRED)
message("found boost libraries:")
foreach(item ${Boost_LIBRARIES})
	message(${item})
endforeach()

message("found boost includes "  ${Boost_INCLUDE_DIRS})
#add_definitions(-DBOOST_VARIANT_AUX_BROKEN_CONSTRUCTOR_TEMPLATE_ORDERING)

set(Internal_Boost_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}; ${CMAKE_SOURCE_DIR}/boost)
include_directories( ${Boost_INCLUDE_DIRS} ${PUBLIC_INCLUDES} ${CMAKE_SOURCE_DIR} ${PYTHON_INCLUDE_PATH} ${Internal_Boost_INCLUDE_DIRS} )
add_executable(py2c_test py2c_test.cpp)
target_link_libraries(py2c_test ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})




