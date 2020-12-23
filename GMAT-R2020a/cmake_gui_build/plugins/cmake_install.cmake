# Install script for directory: D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/plugins

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/GMAT-R2020a-Windows-x64")
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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/CInterfacePlugin/src/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/DataInterfacePlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/EphemPropagatorPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/ExtendedKalmanFilterPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/EstimationPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/EventLocatorPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/ExtraPropagatorsPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/FormationPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/GmatFunctionPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/MatlabInterfacePlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/NewParameterPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/PolyhedronGravityPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/ProductionPropagatorPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/PythonInterfacePlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/SaveCommandPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/ScriptToolsPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/StationPlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/ThrustFilePlugin/src/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/GMAT/gmat-src/GMAT-r2020a2/GMAT-R2020a/cmake_gui_build/plugins/YukonOptimizerPlugin/src/base/cmake_install.cmake")
endif()

