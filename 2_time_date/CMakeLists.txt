add_executable(timer timer.cpp)
target_include_directories(timer PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${PUBLIC_DEPEND_INCLUDES})
target_include_directories(timer PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${PRIVATE_DEPEND_INCLUDES})
target_link_libraries(timer
        PUBLIC ${PUBLIC_DEPEND_LIBS}
        PRIVATE ${PRIVATE_DEPEND_LIBS} ${Boost_LIBRARIES})

add_executable(progress_timer progress_timer.cpp)
target_include_directories(progress_timer PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${PUBLIC_DEPEND_INCLUDES})
target_include_directories(progress_timer PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${PRIVATE_DEPEND_INCLUDES})
target_link_libraries(progress_timer
        PUBLIC ${PUBLIC_DEPEND_LIBS}
        PRIVATE ${PRIVATE_DEPEND_LIBS} ${Boost_LIBRARIES})

    add_executable(progress_display progress_display.cpp)
    target_include_directories(progress_display PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            ${PUBLIC_DEPEND_INCLUDES})
    target_include_directories(progress_display PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${PRIVATE_DEPEND_INCLUDES})
    target_link_libraries(progress_display
            PUBLIC ${PUBLIC_DEPEND_LIBS}
            PRIVATE ${PRIVATE_DEPEND_LIBS} ${Boost_LIBRARIES})

        add_executable(date date.cpp)
        target_include_directories(date PUBLIC
                $<INSTALL_INTERFACE:include>
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                ${PUBLIC_DEPEND_INCLUDES})
        target_include_directories(date PRIVATE
                ${CMAKE_CURRENT_SOURCE_DIR}/src
                ${PRIVATE_DEPEND_INCLUDES})
        target_link_libraries(date
                PUBLIC ${PUBLIC_DEPEND_LIBS}
                PRIVATE ${PRIVATE_DEPEND_LIBS} ${Boost_LIBRARIES})
