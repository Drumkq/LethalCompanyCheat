cmake_minimum_required(VERSION 3.27.3)
project(LethalCheat VERSION 1.0)

file (GLOB_RECURSE LETHAL_SOURCE
    Source/**.hpp
    Source/**.cpp
)
add_library(${PROJECT_NAME} MODULE ${LETHAL_SOURCE})
target_include_directories(${PROJECT_NAME} PRIVATE "ThirdParty/mono/include/mono-2.0")
target_link_libraries(
    ${PROJECT_NAME} 
    PRIVATE 
    "ThirdParty/mono/lib/**.lib"
)