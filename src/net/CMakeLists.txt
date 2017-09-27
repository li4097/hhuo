PROJECT(${NET})

#add headers
INCLUDE_DIRECTORIES(
    ../../include
    ../../include/net
    ../../include/parser
    ../../include/utils
)

# add src
AUX_SOURCE_DIRECTORY(. HHNET_SRC)

# static library
ADD_LIBRARY(${NET} STATIC ${HHNET_SRC})
SET_TARGET_PROPERTIES(${NET} PROPERTIES OUTPUT_NAME ${NET})
SET_TARGET_PROPERTIES(${NET} PROPERTIES LINKER_LANGUAGE CXX)

# add glog
TARGET_LINK_LIBRARIES(${NET})