cmake_minimum_required(VERSION 2.8.3)
project(chatbot)

find_package(catkin REQUIRED COMPONENTS roscpp std_msgs)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(data_node src/data_node.cpp)
target_link_libraries(userinput ${catkin_LIBRARIES})

install(TARGETS userinput
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
