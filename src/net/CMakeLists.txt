PROJECT(hhnet)

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
ADD_LIBRARY(hhnet STATIC ${HHNET_SRC})
SET_TARGET_PROPERTIES(hhnet PROPERTIES OUTPUT_NAME "hhnet")
set_target_properties(hhnet PROPERTIES LINKER_LANGUAGE CXX)

# add ssl
IF (USESSL)
    TARGET_LINK_LIBRARIES(hhnet ssl crypto)
ENDIF()