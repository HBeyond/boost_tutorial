add_executable(sharedptr sharedptr.cpp)
target_include_directories(sharedptr PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${PUBLIC_DEPEND_INCLUDES})
target_include_directories(sharedptr PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${PRIVATE_DEPEND_INCLUDES})
target_link_libraries(sharedptr
        PUBLIC ${PUBLIC_DEPEND_LIBS}
        PRIVATE ${PRIVATE_DEPEND_LIBS} ${Boost_LIBRARIES})

    add_executable(sharedptr_stdContainer sharedptr_stdContainer.cpp)
    target_include_directories(sharedptr PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            ${PUBLIC_DEPEND_INCLUDES})
    target_include_directories(sharedptr_stdContainer PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${PRIVATE_DEPEND_INCLUDES})
    target_link_libraries(sharedptr_stdContainer
            PUBLIC ${PUBLIC_DEPEND_LIBS}
            PRIVATE ${PRIVATE_DEPEND_LIBS} ${Boost_LIBRARIES})

        add_executable(sharedptr_factory sharedptr_factory.cpp)
        target_include_directories(sharedptr_factory PUBLIC
                $<INSTALL_INTERFACE:include>
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                ${PUBLIC_DEPEND_INCLUDES})
        target_include_directories(sharedptr_factory PRIVATE
                ${CMAKE_CURRENT_SOURCE_DIR}/src
                ${PRIVATE_DEPEND_INCLUDES})
        target_link_libraries(sharedptr_factory
                PUBLIC ${PUBLIC_DEPEND_LIBS}
                PRIVATE ${PRIVATE_DEPEND_LIBS} ${Boost_LIBRARIES})

            add_executable(sharedptr_boolConvert sharedptr_boolConvert.cpp)
            target_include_directories(sharedptr_boolConvert PUBLIC
                    $<INSTALL_INTERFACE:include>
                    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                    ${PUBLIC_DEPEND_INCLUDES})
            target_include_directories(sharedptr_boolConvert PRIVATE
                    ${CMAKE_CURRENT_SOURCE_DIR}/src
                    ${PRIVATE_DEPEND_INCLUDES})
            target_link_libraries(sharedptr_boolConvert
                    PUBLIC ${PUBLIC_DEPEND_LIBS}
                    PRIVATE ${PRIVATE_DEPEND_LIBS} ${Boost_LIBRARIES})

add_executable(object_pool object_pool.cpp)
target_include_directories(object_pool PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${PUBLIC_DEPEND_INCLUDES})
target_include_directories(object_pool PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${PRIVATE_DEPEND_INCLUDES})
target_link_libraries(object_pool
        PUBLIC ${PUBLIC_DEPEND_LIBS}
        PRIVATE ${PRIVATE_DEPEND_LIBS} ${Boost_LIBRARIES})
