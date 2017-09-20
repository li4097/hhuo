ADD_EXECUTABLE(test4server test4server.cpp)
TARGET_LINK_LIBRARIES(test4server hhnet hhparser hhutils glog ssl crypto)

ADD_EXECUTABLE(test4json test4json.cpp)
TARGET_LINK_LIBRARIES(test4json hhparser hhutils hhdata jsoncpp glog)

ADD_EXECUTABLE(test4mysql test4mysql.cpp)
TARGET_LINK_LIBRARIES(test4mysql hhdata mysqlclient glog)

ADD_EXECUTABLE(test4log test4log.cpp)
TARGET_LINK_LIBRARIES(test4log glog)

ADD_EXECUTABLE(test4redis test4redis.cpp)
TARGET_LINK_LIBRARIES(test4redis hhdata hiredis glog)

ADD_EXECUTABLE(test4base64 test4base64.cpp)
TARGET_LINK_LIBRARIES(test4base64 hhutils glog ssl crypto)

ADD_EXECUTABLE(test4gzip test4gzip.cpp)
TARGET_LINK_LIBRARIES(test4gzip hhutils glog z)

ADD_EXECUTABLE(test4sha1 test4sha1.cpp)
TARGET_LINK_LIBRARIES(test4sha1 hhutils glog ssl crypto)