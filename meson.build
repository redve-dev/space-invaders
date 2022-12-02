project('space invaders', 'cpp',
  default_options: ['warning_level=3', 'cpp_std=c++20'])

src = [
'src/main.cpp',
'src/Window.cpp',
'src/Object.cpp',
'src/Logger.cpp',
'src/Enemy.cpp',
'src/Player.cpp'
]

deps = [dependency('sdl2'), dependency('glm')]

executable('game', sources: src, dependencies: deps)
