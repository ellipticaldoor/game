# Backlog
- better namespace
- Load script from file system
- Collision system
- Load maps from tiled files
- Connect dialogue system with characters
- Save state of dialogues
- research more about headers
- TODO: Create State struct so its easier to pass to events
- endline support on text / TTF_RenderText_Blended_Wrapped / https://stackoverflow.com/questions/17847818/how-to-do-line-breaks-and-line-wrapping-with-sdl-ttf
- find texture by tile type, 0 should be nothing
- Interact with NPC to trigger dialogues
- Save state into save file
- restore state from save file
- Resolution agnostic graphics
- change resolutions
- hide mouse
- gamepad controller support
- avoid nested switch, improve/refactor events
- limit fps in case vsync fails
- don't render tiles out of the viewport
- retina mode

# Tooling TODO
- detect when to recompile pch.hpp
- avoid compile param duplication on script.sh
- screenshots without shadows of window by default to document process
- reload game on asset/src change
- make a watch commnad that watches changes inside src and recompiles
- shortcut on bettertouch
- include source and link sdl inside the project
- fix
- create mac, windows and linux distributable packages
  * https://icculus.org/~dolson/sdl/
  * https://github.com/fluffrabbit/WeWorkForM
- compile files that changed https://stackoverflow.com/questions/7815400/how-do-i-make-makefile-to-recompile-only-changed-files
- detect unused includes
- learn to debug segmentation faults
- clang-tidy setup
- make vscode warn like compiler does
- run build before starting the debugger on vscode
- create a logger
- switch to vim https://www.youtube.com/watch?v=gnupOrSEikQ

# gameplay mechanincs
- you have body stats
- you can recover health
- to recover health is quite hard in this game
- you need to get food and water
- you have inventory
- you have to scape the town and make the package delivery
- the game is going to make you stay in the town at all cost
- make walking through the desert interesting
- fighting mechanics
- there are guns, but they take space in the inventory, and there are not many bullets in the game
- objects have a percentage of health too, included that backpack
- no fast travel
- autosave
- of you try to go out of the limits of the map you die because of the heat
- there is no map on the game
- try to hide the ui
- dialogue system
