add_executable(Server main.cpp)
# for windows add ws2_32 wsock32
if (WIN32)
    target_link_libraries(Server PUBLIC ws2_32 wsock32 Crow)
else()
    target_link_libraries(Server PUBLIC Crow)
endif()
