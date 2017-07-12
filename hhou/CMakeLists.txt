PROJECT(hhuo)

set(HHUO_SRCS
        src/HH_FDEvent.cpp
        src/HH_EventLoop.cpp
        src/HH_ListenEvent.cpp
        src/HH_Poller.cpp
        src/HH_Thread.cpp
        src/HH_ThreadPool.cpp
        src/HH_CircularBuffer.cpp
        src/HH_Parse.cpp)

# shared library
ADD_LIBRARY(hhuo SHARED ${HHUO_SRCS})

# static library
ADD_LIBRARY(hhuo_static STATIC ${HHUO_SRCS})
SET_TARGET_PROPERTIES(hhuo_static PROPERTIES OUTPUT_NAME "hhuo")
SET_TARGET_PROPERTIES(hhuo PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(hhuo_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)