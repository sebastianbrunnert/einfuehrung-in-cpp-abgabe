enable_testing()

set(ControlSources
    ${CMAKE_SOURCE_DIR}/src/control/Game.cpp
    )

set(ModelSources
    ${CMAKE_SOURCE_DIR}/src/model/Ship.cpp
    ${CMAKE_SOURCE_DIR}/src/model/Alien.cpp
    ${CMAKE_SOURCE_DIR}/src/model/AlienBlock.cpp
    )

set(ViewSources
    ${CMAKE_SOURCE_DIR}/src/view/Layer.cpp
    )

set(TestSources
    ${CMAKE_CURRENT_SOURCE_DIR}/ShipTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AlienTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AlienBlockTest.cpp
    )

add_executable(Test
    ${ModelSources}
    ${ControlSources}
    ${ViewSources}
    ${TestSources}
    )
