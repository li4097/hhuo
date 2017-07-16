ADD_EXECUTABLE(test4server test4server.cpp)
TARGET_LINK_LIBRARIES(test4server hhnet hhparser hhutils)

ADD_EXECUTABLE(test4thread test4thread.cpp)
TARGET_LINK_LIBRARIES(test4thread hhnet hhparser hhutils)

ADD_EXECUTABLE(test4task test4task.cpp)
TARGET_LINK_LIBRARIES(test4task hhnet hhparser hhutils)

ADD_EXECUTABLE(test4json test4json.cpp)
TARGET_LINK_LIBRARIES(test4json hhnet hhparser hhutils hhdata)