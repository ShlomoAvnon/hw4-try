cmake_minimum_required(VERSION 3.21)
project(hw1_project2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw1_project2
        Barfight.cpp
        Barfight.h
        Card.cpp
        Card.h
        Dragon.cpp
        Dragon.h
        Fairy.cpp
        Fairy.h
        Fighter.cpp
        Fighter.h
        Goblin.cpp
        Goblin.h
        HealthPoints.cpp
        HealthPoints.h
        main.cpp
        Merchant.cpp
        Merchant.h
        Mtmchkin.cpp
        Mtmchkin.h
        Node.h
        Pitfall.cpp
        Pitfall.h
        Player.cpp
        Player.h
        Queue.h
        RLEList.c
        RLEList.h
        Rogue.cpp
        Rogue.h
        Treasure.h
        Tresure.cpp
        utilities.cpp
        utilities.h
        Vampire.cpp
        Vampire.h
        Wizard.cpp
        Wizard.h)
