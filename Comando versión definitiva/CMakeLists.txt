# Check that we aren't building in-source
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR
        "We don't allow building in the original (source) directory!"
        "Please, remove the CMakeCache.txt and repeat from a dedicate directory"
    )
endif()

cmake_minimum_required (VERSION 3.1.0 FATAL_ERROR)
project (Commando-1985-NES-Edition)

set (CMAKE_CXX_STANDARD 11)

add_executable(Commando-1985-NES-Edition
  src/Application.cpp
  src/Enemy_BossGrenade.cpp
  src/Enemy_Bosslvl1.cpp
  src/Enemy_Bunker.cpp
  src/Enemy_CapturerGuard.cpp
  src/Enemy_Car.cpp
  src/Enemy.cpp
  src/Enemy_Hole.cpp
  src/Enemy_Knife.cpp
  src/Enemy_Motorbike.cpp
  src/Enemy_Rocket.cpp
  src/Enemy_Truck.cpp
  src/Enemy_WhiteGuard.cpp
  src/Globals.cpp
  src/Main.cpp
  src/ModuleAudio.cpp
  src/ModuleCollision.cpp
  src/ModuleEnemies.cpp
  src/ModuleFadeToBlack.cpp
  src/ModuleFonts.cpp
  src/ModuleInput.cpp
  src/ModuleLvl2.cpp
  src/ModuleParticles.cpp
  src/ModulePlayer.cpp
  src/ModulePowerUp.cpp
  src/ModuleRender.cpp
  src/ModuleSecretAreas.cpp
  src/ModuleTextures.cpp
  src/ModuleWelcome.cpp
  src/ModuleWindow.cpp
  src/PathWhiteGuard.cpp
  src/Runner.cpp
)

# Find SDL2
include (FindPkgConfig)
pkg_check_modules (SDL2 REQUIRED sdl2 SDL2_image SDL2_mixer)

include_directories (${SDL2_INCLUDE_DIRS})
target_link_libraries (Commando-1985-NES-Edition ${SDL2_LIBRARIES})
