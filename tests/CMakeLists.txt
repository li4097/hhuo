ADD_EXECUTABLE(testPtr testPtr.cpp)
TARGET_LINK_LIBRARIES(testPtr hhuo)


ADD_EXECUTABLE(testAuto testAuto.cpp)
TARGET_LINK_LIBRARIES(testAuto hhuo)

ADD_EXECUTABLE(of of.cpp)
TARGET_LINK_LIBRARIES(of hhuo)

ADD_EXECUTABLE(bind bind.cpp)
TARGET_LINK_LIBRARIES(bind hhuo)