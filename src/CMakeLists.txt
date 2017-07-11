PROJECT(hhuo)

set(HHUO_SRCS
        HH_FDEvent.cpp
        HH_EventLoop.cpp
        HH_ListenEvent.cpp
        HH_Poller.cpp
        HH_Thread.cpp
        HH_ThreadPool.cpp
        HH_CircularBuffer.cpp)

# shared library
ADD_LIBRARY(hhuo SHARED ${HHUO_SRCS})

# static library
ADD_LIBRARY(hhuo_static STATIC ${HHUO_SRCS})
SET_TARGET_PROPERTIES(hhuo_static PROPERTIES OUTPUT_NAME "hhuo")
SET_TARGET_PROPERTIES(hhuo PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(hhuo_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)