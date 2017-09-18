# imserver
PROJECT(imserver)

#add headers
INCLUDE_DIRECTORIES(
    ../../include
    ../../include/net
    ../../include/parser
    ../../include/utils
    ../../include/data
)

# add src
ADD_EXECUTABLE(Imserver 
               Imserver.cpp 
               app/src/HtProcessor.cpp 
               app/src/Im.cpp 
               app/src/WsProcessor.cpp)
TARGET_LINK_LIBRARIES(Imserver hhnet hhparser hhutils hhdata)