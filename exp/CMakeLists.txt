

include_directories( ${Boost_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})
file(GLOB sources "*.cpp")
foreach(source ${sources})
    get_filename_component(exec ${source} NAME_WE)
    message(STATUS "found source " ${source})
    message(STATUS "will make target " ${exec})
    add_executable(${exec} ${source})
    target_link_libraries(${exec} ${Boost_LIBRARIES})
endforeach(source ${sources})

 


