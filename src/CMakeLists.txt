find_package(SDL3)

function (add_library_with_sdl lib)
	add_library(${lib} STATIC ${lib}.cpp)
	target_link_libraries(${lib} PUBLIC SDL3::SDL3)
	target_include_directories(${lib} PUBLIC ${CMAKE_SOURCE_DIR}/include)
endfunction()

add_library_with_sdl(simulation)