# STM Projects

A PlatformIO based workspace for cross-platform STM32 development. 

## Setup
- Clone this repository
```
git clone https://www.github.com/raghavakumar8/stm_ws.git
```
- Install PlatformIO:
```
pip install -U platformio
```
- Compile all projects
```
cd stm_ws
pio run
```
- Upload a specific project:
```
pio run -e blink -t upload
```

## Sublime Text Integration

This repository also contains `.sublime-project` files that can be used directly. 
- You may need to edit directory locations in the `.sublime-project` files for everything to work correctly.
- To build, clean or upload, use shortcuts found in the `Ctrl-Shift-P` menu. 
- To enable debugging using Sublime, install `SublimeGDB` using Package Manager. 
- A debugging session can be started by hitting `F5`.
