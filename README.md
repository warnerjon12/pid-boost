# Introduction

pid-boost is an implementation of a boost converter regulated using a PID control loop. Control code is written for the Raspberry Pi Pico W, and hardware files are included for use with KiCad. VS Code configuration files are also included.

# Setup

```bash
git clone --recurse-submodules https://github.com/warnerjon12/pid-boost.git
cd pid-boost
```

# Build

```bash
cmake -G Ninja -B build
ninja -C build
```

# Upload

```
picotool load -f build/src/pid_boost.elf
```