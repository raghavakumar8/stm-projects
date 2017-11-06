[![Build Status](https://travis-ci.org/raghavakumar8/stm-projects.svg?branch=master)](https://travis-ci.org/raghavakumar8/stm-projects)
# STM Projects
A PlatformIO based workspace for cross-platform STM32 development. 

## Setup
- Clone this repository
```
git clone https://github.com/raghavakumar8/stm-projects.git
```
- Install PlatformIO:
```
pip install -U platformio
```
- Compile all projects
```
cd stm-projects
pio run
```
- Upload a specific project:
```
pio run -e blink -t upload
```

## IDE Integration

PlatformIO integrates well with a number of IDEs. To see a list of available IDEs and configure your project:
```
cd stm-projects && pio init -h
pio init --ide <chosen-ide>
```
