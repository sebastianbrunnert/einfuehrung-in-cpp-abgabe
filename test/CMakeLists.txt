enable_testing()

set(ControlSources
    ${CMAKE_SOURCE_DIR}/src/control/Game.cpp
    ${CMAKE_SOURCE_DIR}/src/control/ShipControl.cpp
    ${CMAKE_SOURCE_DIR}/src/control/AlienBlockControl.cpp
    ${CMAKE_SOURCE_DIR}/src/control/BulletControl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/control/BarrierControl.cpp
    )

set(ModelSources
    ${CMAKE_SOURCE_DIR}/src/model/Ship.cpp
    ${CMAKE_SOURCE_DIR}/src/model/Alien.cpp
    ${CMAKE_SOURCE_DIR}/src/model/AlienBlock.cpp
    ${CMAKE_SOURCE_DIR}/src/model/Bullet.cpp
    ${CMAKE_SOURCE_DIR}/src/model/Barrier.cpp
    )

set(ViewSources
    ${CMAKE_SOURCE_DIR}/src/view/Layer.cpp
    )

set(TestSources
    ${CMAKE_CURRENT_SOURCE_DIR}/ShipTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AlienTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AlienBlockTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/BulletTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/BarrierTest.cpp
    )

add_executable(Test
    ${ModelSources}
    ${ControlSources}
    ${ViewSources}
    ${TestSources}
    )
