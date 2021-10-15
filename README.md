# Audio Tutorial

This is the [Audio Programming Tutorial Series](https://github.com/BennyQBD/AudioTutorial/) by [thebennybox](https://www.youtube.com/channel/UCnlpv-hhcsAtEHKR2y2fW4Q) Implemented in [Meson](https://mesonbuild.com).

# Building and Running

## Install Dependencies

Ubuntu

```bash
sudo apt-get update && \
sudo apt-get install gcc meson ninja libsdl2-dev -y # Add `clang` for LLVM Clang
```

Fedora

```bash
sudo dnf install gcc meson ninja-build SDL2-devel -y # Add `clang` for LLVM Clang
```

## Set Up Project

```bash
meson setup build
```

## Build Your Applications

```bash
meson compile -C build
```

## Run Your Applications

```bash
./build/audiotutorial
```