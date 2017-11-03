PROJECT(hhuo)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -pthread -std=c++11 -Wno-unused-function")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -pthread -std=c++11 -Wno-unused-function")

#  include directories
INCLUDE_DIRECTORIES( 
    ${PROJECT_SOURCE_DIR}/include
    /usr/local/include
    /usr/include
)

# lib directories
LINK_DIRECTORIES(
    ${PROJECT_BINARY_DIR}/lib
    /usr/local/lib
    /usr/lib
)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# openssl option
FIND_PACKAGE(OpenSSL REQUIRED)
MESSAGE(STATUS "OpenSSL include: ${OPENSSL_INCLUDE_DIR}")
MESSAGE(STATUS "OpenSSL lib: ${OPENSSL_LIBRARIES}")
INCLUDE_DIRECTORIES(${OPENSSL_INCLUDE_DIR})
LINK_DIRECTORIES(${OPENSSL_LIBRARIES})
SET(PARSER "hhparser")
SET(LIBPARSER "libhhparser.a")
SET(NET "hhnet")
SET(LIBNET "libhhnet.a")
OPTION(USESSL "Enable use openssl" OFF)
IF(USESSL)
    SET(NET "hhnet_ssl")
    SET(LIBNET "libhhnet_ssl.a")
    MESSAGE(STATUS "OpenSSL ON")
    ADD_DEFINITIONS(-DHAVE_OPENSSL)
ENDIF() 

# http option
OPTION(HTTP "Enable http" ON)
IF(HTTP)
	SET(PARSER "hhparser_http")
	SET(LIBPARSER "libhhparser_http.a")
    MESSAGE(STATUS "Http ON")
    ADD_DEFINITIONS(-DHTTP)
ENDIF()

# websocket option
OPTION(WEBSOCKET "Enable websocket" OFF)
IF(WEBSOCKET)
	SET(PARSER "hhparser_ws")
	SET(LIBPARSER "libhhparser_ws.a")
    MESSAGE(STATUS "Websocket ON")
    ADD_DEFINITIONS(-DWEBSOCKET)
ENDIF()

# tcpconnection option
OPTION(TCPCONN "Enable tcpconnection" OFF)
IF(TCPCONN)
	SET(PARSER "hhparser_tp")
	SET(LIBPARSER "libhhparser_tp.a")
    MESSAGE(STATUS "Tcpconnection ON")
    ADD_DEFINITIONS(-DTCPCONN)
ENDIF()

# shortconnection option
OPTION(SHORTCONN "short connection" OFF)
IF(SHORTCONN)
    MESSAGE(STATUS "Short Connection")
    ADD_DEFINITIONS(-DSHORT_CONN)
ENDIF()

# add subdirs
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)
ADD_SUBDIRECTORY(unittests)

#copy *.h
INSTALL(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION /usr/local/include/hhou)
INSTALL(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION /usr/include/hhou)

#install *.a
INSTALL(FILES ${PROJECT_BINARY_DIR}/lib/${LIBNET} 
			  ${PROJECT_BINARY_DIR}/lib/libhhdata.a
			  ${PROJECT_BINARY_DIR}/lib/${LIBPARSER}
			  ${PROJECT_BINARY_DIR}/lib/libhhutils.a DESTINATION /usr/local/lib)
			  
INSTALL(FILES ${PROJECT_BINARY_DIR}/lib/${LIBNET} 
			  ${PROJECT_BINARY_DIR}/lib/libhhdata.a
			  ${PROJECT_BINARY_DIR}/lib/${LIBPARSER}
			  ${PROJECT_BINARY_DIR}/lib/libhhutils.a DESTINATION /usr/lib)
