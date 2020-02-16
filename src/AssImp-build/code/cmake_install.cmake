# Install script for directory: F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Assimp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp-build/code/Debug/assimp-vc142-mtd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp-build/code/Release/assimp-vc142-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp-build/code/MinSizeRel/assimp-vc142-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp-build/code/RelWithDebInfo/assimp-vc142-mt.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp-build/code/Debug/assimp-vc142-mtd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp-build/code/Release/assimp-vc142-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp-build/code/MinSizeRel/assimp-vc142-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp-build/code/RelWithDebInfo/assimp-vc142-mt.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/anim.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/aabb.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/ai_assert.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/camera.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/color4.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/color4.inl"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp-build/code/../include/assimp/config.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/commonMetaData.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/defs.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Defines.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/cfileio.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/light.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/material.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/material.inl"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/matrix3x3.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/matrix3x3.inl"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/matrix4x4.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/matrix4x4.inl"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/mesh.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/pbrmaterial.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/postprocess.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/quaternion.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/quaternion.inl"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/scene.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/metadata.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/texture.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/types.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/vector2.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/vector2.inl"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/vector3.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/vector3.inl"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/version.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/cimport.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/importerdesc.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Importer.hpp"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/DefaultLogger.hpp"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/ProgressHandler.hpp"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/IOStream.hpp"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/IOSystem.hpp"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Logger.hpp"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/LogStream.hpp"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/NullLogger.hpp"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/cexport.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Exporter.hpp"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/DefaultIOStream.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/DefaultIOSystem.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/ZipArchiveIOSystem.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/SceneCombiner.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/fast_atof.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/qnan.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/BaseImporter.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Hash.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/MemoryIOWrapper.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/ParsingUtils.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/StreamReader.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/StreamWriter.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/StringComparison.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/StringUtils.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/SGSpatialSort.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/GenericProperty.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/SpatialSort.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/SkeletonMeshBuilder.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/SmoothingGroups.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/SmoothingGroups.inl"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/StandardShapes.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/RemoveComments.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Subdivision.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Vertex.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/LineSplitter.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/TinyFormatter.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Profiler.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/LogAux.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Bitmap.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/XMLTools.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/IOStreamBuffer.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/CreateAnimMesh.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/irrXMLWrapper.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/BlobIOSystem.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/MathFunctions.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Exceptional.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/ByteSwapper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Compiler/pushpack1.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Compiler/poppack1.h"
    "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp-build/code/Debug/assimp-vc142-mtd.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "F:/Documents/Creation of stuff/C++/Aqua-git/src/AssImp-build/code/RelWithDebInfo/assimp-vc142-mt.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
endif()

