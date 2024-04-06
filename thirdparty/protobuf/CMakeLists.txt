# check if Protobuf is already installed in the system - using CMake's built in script FindProtobuf
find_package(Protobuf QUIET)

if(Protobuf_FOUND)
    message(STATUS "Found preinstalled protobuf libraries at ${Protobuf_LIBRARIES}")
    add_library(Protobuf_external INTERFACE)
else()
    message(STATUS "Preinstalled Protobuf not found.")
    message(STATUS "Will download and install Protobuf in ${STAGED_INSTALL_PREFIX}")

    include(ExternalProject)
    ExternalProject_Add(Protobuf_external
        GIT_REPOSITORY
        https://github.com/protocolbuffers/protobuf.git
        GIT_TAG
        v3.1.4
        UPDATE_COMMAND
        ""
        CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}

        -DwxBUILD_SHARED=OFF

        TEST_AFTER_INSTALL
        0
        DOWNLOAD_NO_PROGRESS
        1
        LOG_CONFIGURE
        1
        LOG_BUILD
        1
        LOG_INSTALL
        1
    )

    set(Protobuf_ROOT_DIR ${STAGED_INSTALL_PREFIX})
    file(TO_NATIVE_PATH "${Protobuf_ROOT_DIR}" Protobuf_ROOT_DIR)
    set(Protobuf_ROOT_DIR ${Protobuf_ROOT_DIR} CACHE INTERNAL "Protobuf installation dir")
endif()