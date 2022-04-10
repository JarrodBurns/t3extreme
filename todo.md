# T^3 eXtreme

## Update log
- 04/10/2022 - Stable build committed to git.

## To Do

### Main.cpp
[] Write logic to remove scroll bar
[] Set file icon

### GFX.hpp
[] DRY: Investigate decorator / wrapper *see notes*
[] Clean up any escaped backslashes

### TicTacToe.hpp
[] declare marker attribute *see notes*

## Notes

### Investigate decorator
May of the methods in GFX.hpp are redundant, the typical implementation is Python is to write a wrapper and set it as decorator for each subsequent method. *Investigate the c++ implementation of this.*

### Declare Marker Attribute
The player marker 'X' or 'O' is represented in (3) three places:

- Main.cpp Declared in the session loop
- TicTacToe.hpp (Method) assert_invalid_move
- TicTacToe.hpp (Method) board_update

With the current implementation, to change the marker an update of these three locations will be required. 

Proposed fix: set marker attribute and rewrite the methods to reference the data.

## Build
- g++ (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0
- Win10