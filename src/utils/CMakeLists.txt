PROJECT(hhutils)

#add headers
INCLUDE_DIRECTORIES(
    ../../include
    ../../include/net
    ../../include/utils
)
# add src
AUX_SOURCE_DIRECTORY(. HHUTILS_SRC)

# static library
ADD_LIBRARY(hhutils STATIC ${HHUTILS_SRC})
SET_TARGET_PROPERTIES(hhutils PROPERTIES OUTPUT_NAME "hhutils")
SET_TARGET_PROPERTIES(hhutils PROPERTIES LINKER_LANGUAGE CXX)

#add zlib
TARGET_LINK_LIBRARIES(hhutils)