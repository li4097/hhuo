PROJECT(hhparser)

#add headers
INCLUDE_DIRECTORIES(
)

# add src
AUX_SOURCE_DIRECTORY(. HHPARSER_SRC)

# static library
ADD_LIBRARY(hhparser STATIC ${HHPARSER_SRC})
SET_TARGET_PROPERTIES(hhparser PROPERTIES OUTPUT_NAME "hhparser")
set_target_properties(hhparser PROPERTIES LINKER_LANGUAGE CXX)