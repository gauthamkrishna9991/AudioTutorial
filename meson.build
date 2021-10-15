project(
  'AudioTutorial',
  'cpp',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'cpp_std=c++14'
  ]
)

project_srcs = []

subdir('src')

# DEPENDENCIES
# - SDL2
# If SDLs exists in the system, use the system provided SDL2 Library
SDL2 = dependency(
  'sdl2',
  # fallback: 'sdl2',
  required: true
)

exe = executable(
  'audiotutorial',
  project_srcs,
  dependencies: [
    SDL2
  ],
  install : true
)

test('basic', exe)
