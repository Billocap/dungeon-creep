#!/bin/bash

# Simple command for building the project

HOME_FOLDER=$(pwd)
BIN_FOLDER=$HOME_FOLDER/bin

MAIN_FILE=$HOME_FOLDER/main.cpp
OUTPUT_FILE=$BIN_FOLDER/dungeon_creep

g++ $MAIN_FILE -o $OUTPUT_FILE -l ncurses

