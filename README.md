# iWUDD - Integrated Wii U Disc Dumper
A fork of WUDD intended to be integrated within [bariista](https://github.com/Crudefern/Bariista).
WUDD is inspired by [wudump](https://github.com/FIX94/wudump) from FIX94.

Features:
- Dump a Wii U Disc in WUD (uncompressed) or [WUX](https://gbatemp.net/threads/wii-u-image-wud-compression-tool.397901/) (loseless compression) format (including the game.key)
- Dump the GM Partitions (Game, Updates, DLCs) of an Wii U Disc as *.app,*.h3, .tmd, .tik, .cert files
- Supports dumping to SD (FAT32) and USB (NTFS only). When dumping to SD the files get slitted in 2 GiB parts. 

Files will be dumped to `/wudump/[DISC-ID]/`. The disc id of a game can be found on the disc (e.g. WUP-P-ARDP for the EUR version of Super Mario 3D World). If WUDD fails to determine the disc id, "DISC" with a timestamp will be used instead.

## How to merge splitted files

When you dump a .wux or .wud to the SD card it gets splitted into 2 GiB parts (FAT32 limitation). To merge them you can use the `copy` cmd tool.

Example:
`copy /b game.wux.part1 + game.wux.part2 game.wux`

## Dependencies
Requires an [Environment](https://github.com/wiiu-env/EnvironmentLoader) (e.g. Tiramisu or Aroma) with [MochaPayload](https://github.com/wiiu-env/MochaPayload) (Nightly-MochaPayload-20220725-155554 or newer)

- [wut](https://github.com/devkitPro/wut)
- [libmocha](https://github.com/wiiu-env/libmocha)
- [libntfs](https://github.com/wiiu-env/libntfs)

## Building
iWUDD is not intended to be built by itself, for building instructions see [bariista](https://github.com/Crudefern/Bariista).
