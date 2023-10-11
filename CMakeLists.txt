cmake_minimum_required(VERSION 3.21)
project(raytracer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -fno-gnu-unique -Werror")

include_directories(include)

add_executable(bootstrap_raytracer
        include/bootstrapMain.hpp
        src/boostrapMain.cpp
        include/vector3D.hpp
        src/vector3D.cpp
        include/point3D.hpp
        src/point3D.cpp
        src/Ray.cpp
        include/Ray.hpp
        src/Sphere.cpp
        include/Sphere.hpp
        src/Camera.cpp
        include/Camera.hpp
        include/rectangle3D.hpp
        src/rectangle3D.cpp
        include/Plane.hpp
        src/Plane.cpp
        src/AmbientLighting.cpp
        include/AmbientLighting.hpp
        include/ILight.hpp
        include/IPrimitives.hpp)

add_executable(raytracer
        include/errors.hpp
        include/raytracer.hpp
        include/point3D.hpp
        include/parser.hpp
        include/IPrimitives.hpp
        include/someStructsForTheParser.hpp
        include/rectangle3D.hpp
        include/Ray.hpp
        include/Sphere.hpp
        include/Plane.hpp
        include/Camera.hpp
        include/AmbientLighting.hpp
        include/ILight.hpp
        include/ILights.hpp
        include/DirectionalLight.hpp
        include/sceneBuilder.hpp

        src/main.cpp
        src/errors.cpp
        src/raytracer.cpp
        src/parser.cpp
        src/vector3D.cpp
        src/point3D.cpp
        src/Ray.cpp
        src/Sphere.cpp
        src/Camera.cpp
        src/rectangle3D.cpp
        src/Plane.cpp
        src/DirectionalLight.cpp
        src/AmbientLighting.cpp

        src/sceneBuilder.cpp)

target_link_libraries(raytracer -lsfml-system sfml-graphics sfml-window)
target_link_libraries(raytracer config++)
