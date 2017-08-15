# data dir
PROJECT(hhdata)

#add headers
INCLUDE_DIRECTORIES(
        ../../include
        ../../include/net
        ../../include/parser
        ../../include/utils
        ../../include/data
)

# add src
AUX_SOURCE_DIRECTORY(. HHDATA_SRC)

# static library
ADD_LIBRARY(hhdata STATIC ${HHDATA_SRC})
SET_TARGET_PROPERTIES(hhdata PROPERTIES OUTPUT_NAME "hhdata")
SET_TARGET_PROPERTIES(hhdata PROPERTIES LINKER_LANGUAGE CXX)

#add josn
TARGET_LINK_LIBRARIES(hhdata jsoncpp mysqlclient hiredis glog)
