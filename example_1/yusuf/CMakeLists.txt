cmake_minimum_required(VERSION 3.0.2)
project(meturone_egitim)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

add_message_files(
    FILES
    Dummy.msg
    answer.msg
)

generate_messages(
    DEPENDENCIES
    std_msgs
)


catkin_package(
    CATKIN_DEPENDS message_runtime
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(dummy_node src/dummy_node.cpp)
add_executable(sum_arrays src/sum_arrays.cpp)
target_link_libraries(dummy_node ${catkin_LIBRARIES})
target_link_libraries(sum_arrays ${catkin_LIBRARIES})
