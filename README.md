# Sega Mega CD PCM Converter

[![Build Status](https://github.com/devon-artmeier/mcdpcm/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/devon-artmeier/mcdpcm/actions/workflows/cmake-multi-platform.yml)

This is a tool to convert 8-bit mono WAV files into Sega Mega CD PCM sample files.

## Usage

    mcdpcm [input] [output]

        [input]  - Input file (Must be 8-bit mono WAV format)
        [output] - Output file

## Build Instructions

CMake is required to build this.

* On Windows, you can run "make.bat" and the built executable will be put in the "out/bin" folder.
* On other systems, you can call "make" and then "make install".
