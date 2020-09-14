cmake_minimum_required(VERSION 3.0.2)
project(meturone_egitim)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS roscpp std_msgs message_generation)

add_service_files(
    FILES
    RandomArray.srv
)

generate_messages(
    DEPENDENCIES
    std_msgs
)

catkin_package(
    CATKIN_DEPENDS message_runtime
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(dummy_node src/dummy_node.cpp)
target_link_libraries(dummy_node ${catkin_LIBRARIES})
