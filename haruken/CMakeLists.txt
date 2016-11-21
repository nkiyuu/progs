cmake_minimum_required(VERSION 3.6)
project(haruken)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/Action.cpp
    src/Action.hpp
    src/ActionType.hpp
    src/Answer.cpp
    src/Answer.hpp
    src/ArrayNum.hpp
    src/Assert.hpp
    src/Asteroid.cpp
    src/Asteroid.hpp
    src/Game.cpp
    src/Game.hpp
    src/Laser.cpp
    src/Laser.hpp
    src/Main.cpp
    src/Math.cpp
    src/Math.hpp
    src/Parameter.cpp
    src/Parameter.hpp
    src/Print.hpp
    src/Random.cpp
    src/Random.hpp
    src/RandomSeed.cpp
    src/RandomSeed.hpp
    src/Recorder.cpp
    src/Recorder.hpp
    src/Ship.cpp
    src/Ship.hpp
    src/Simulator.cpp
    src/Simulator.hpp
    src/Stage.cpp
    src/Stage.hpp
    src/Timer.cpp
    src/Timer.hpp
    src/Types.hpp
    src/Util.cpp
    src/Util.hpp
    src/Vector2.cpp
    src/Vector2.hpp)

add_executable(haruken ${SOURCE_FILES})