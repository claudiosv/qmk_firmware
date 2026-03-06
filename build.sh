#!/usr/bin/env bash
qmk compile -kb annepro2/c18 -km claudiosv --compiledb

qmk compile -kb keychron/v2/ansi_encoder -km claudiosv --compiledb
# Run qmk compile -kb <keyboard> -km <keymap> --compiledb to generate the compile_commands.json.
# Inside VS code, press Ctrl + Shift + P (macOS: Command + Shift + P) to open the command palette.
# Start typing clangd: Download Language Server and select it when it appears. Note that this only needs to be done once on clangd extension installation, if it didn't already ask to do so.
# Inside VS code, press Ctrl + Shift + P (macOS: Command + Shift + P) to open the command palette.
# Start typing clangd: Restart Language Server and select it when it appears.
# Now you're ready to code QMK Firmware in VS Code!
