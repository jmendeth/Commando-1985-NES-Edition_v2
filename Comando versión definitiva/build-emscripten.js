#!/bin/bash

cd build && emcc -O3 \
  -s ALLOW_MEMORY_GROWTH=1 \
  -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' \
  -s USE_SDL=2 -s LEGACY_GL_EMULATION=1 \
  -std=c++11 -Wno-writable-strings ../src/*.cpp \
  -o output.min.js --preload-file ../assets@/
