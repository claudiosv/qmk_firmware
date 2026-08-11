#!/usr/bin/env bash

mkdir -p jsons
mkdir -p svgs

# qmk c2json keyboards/keychron/v2/ansi_encoder/keymaps/claudiosv/keymap.c --no-cpp | keymap parse -c 10 -q - >keychron_v2_keymap.yml

echo "Annepro2"
rm jsons/annepro2_keymap.json
# rm svgs/annepro2_keymap.svg
rm svgs/annepro2_keymap.yml
qmk c2json --keyboard annepro2/c18 --keymap claudiosv --no-cpp --output jsons/annepro2_keymap.json
keymap parse --layer-names BASE FN1 FN2 --qmk-keymap-json jsons/annepro2_keymap.json --columns 10 --output svgs/annepro2_keymap.yml
keymap draw --qmk-keyboard annepro2/c18 svgs/annepro2_keymap.yml > svgs/annepro2_keymap.svg

# usage: qmk c2json [-h] [-km KEYMAP] [-kb KEYBOARD] [-q] [-o OUTPUT] [--no-cpp] [filename]

# positional arguments:
#   filename              keymap.c file

# options:
#   -h, --help            show this help message and exit
#   -km, --keymap KEYMAP  The keymap's name
#   -kb, --keyboard KEYBOARD
#                         The keyboard's name
#   -q, --quiet           Quiet mode, only output error messages
#   -o, --output OUTPUT   File to write to
#   --no-cpp              Do not use 'cpp' on keymap.c

# qmk c2json keyboards/annepro2/keymaps/claudiosv/keymap.c --no-cpp > jsons/annepro2_keymap.json
# qmk c2json --keyboard annepro2/c18 --keymap claudiosv --no-cpp --output jsons/annepro2_keymap.json
# keymap parse --qmk-keymap-json jsons/annepro2_keymap.json --columns 10 --output svgs/annepro2_keymap.svg

echo "Keychron V2"
rm jsons/keychron_v2_keymap.json
# rm svgs/keychron_v2_keymap.svg
rm svgs/keychron_v2_keymap.yml
# qmk c2json keyboards/keychron/v2/ansi_encoder/keymaps/claudiosv/keymap.c --no-cpp > jsons/keychron_v2_keymap.json
qmk c2json --keyboard keychron/v2/ansi_encoder --keymap claudiosv --no-cpp --output jsons/keychron_v2_keymap.json
# --config keymap_config.yml
keymap -c keymap_config.yml parse --layer-names MAC_BASE WIN_BASE FN1 FN2 FN3 --qmk-keymap-json jsons/keychron_v2_keymap.json --columns 10 --output svgs/keychron_v2_keymap.yml
keymap -c keymap_config.yml draw --qmk-keyboard keychron/v2/ansi_encoder svgs/keychron_v2_keymap.yml > svgs/keychron_v2_keymap.svg

# keymap parse -c 10 -q - > svgs/annepro2_keymap.yml
