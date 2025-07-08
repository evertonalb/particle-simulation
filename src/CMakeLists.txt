find_package(SDL3)

function (add_library_with_sdl lib)
	add_library(${lib} STATIC ${lib}.cpp)
	target_link_libraries(${lib} PUBLIC SDL3::SDL3)
	target_include_directories(${lib} PUBLIC ${CMAKE_SOURCE_DIR}/include)
endfunction()

# Non-SDL-related
add_library(vector STATIC vector.cpp)
target_include_directories(vector PUBLIC ${CMAKE_SOURCE_DIR}/include)

# SDL-related
add_library_with_sdl(simulation)

add_library_with_sdl(polygon)
target_link_libraries(polygon PUBLIC vector)

add_library_with_sdl(ball)
target_link_libraries(ball PRIVATE polygon)

