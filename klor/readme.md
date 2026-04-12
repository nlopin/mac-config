# Klor Keyboard Firmware

Custom QMK firmware for the [Klor](https://github.com/geigeigeist/klor) split ergonomic keyboard (40-key variant: 5+6+6+3 per side).

Designed for macOS with OS-level Colemak DH remapping (keyboard sends QWERTY scancodes).

## Layers

### BASE (QWERTY)
```
  Q     W     E     R     T                 Y     U     I     O     P
 NAV  Ct/A  Sf/S  Al/D  Cm/F   G           H   Cm/J  Al/K  Sf/L  Ct/;  Sf/'
Sf/Tab  Z     X     C     V     B  [mute]       N     M     ,     .     /    Esc
       Alt   Cmd  Meh/Spc                      Ctrl   SYM   NUM
```

Home row mods (tap for letter, hold for modifier): Ctrl, Shift, Alt, Cmd — mirrored on both sides.

### SYM (Symbols)
```
  %     #     |     &     *                 `     '     "     ;     :
  _     <     /     =     >     +           -     [     ]     {     }     |
  _     ^     @     ?     !     $  [mute]         _     (     )     ~     /     \
       ___   ___   ___                           ___   ___   ___
```

### NAV (Navigation)
```
  _     _    F15   F16    _               Del   PgUp   Up   Home    _
  _    Ctrl  Sft   Alt   Cmd    _         Bksp  Left  Down  Right  Enter   _
  _     _     _     _     _     _  [mute]         _   PgDn    _    End    _     _
       ___   ___   ___                           ___   ___   ___
```

### NUM (Numpad + F-keys)
```
  _    F1    F2    F3    F4                *     7     8     9     /
  _    F5    F6    F7    F8   Bksp        +     4     5     6     0     =
  _    F9   F10   F11   F12    _  [mute]        -     1     2     3     .     ,
       ___   ___   ___                          ___   ___   ___
```

## Features

- **Home row mods** on BASE layer (Ctrl/Shift/Alt/Cmd)
- **Mod-tap keys**: Left Shift/Tab, Right Shift/Quote, Meh/Space
- **OLED displays**: Left shows layer name in big font, right shows active modifiers in 4 quadrants
- **Encoders**: Left rotary = volume (push = mute), right rotary = scroll
- **Custom big font** in `glcdfont.c` for OLED layer/modifier display (14 letters: A-F, L-N, S-V, Y)
- RGB and haptic disabled to save flash and avoid I2C delays

## Installation

Copy this folder to your QMK tree:

```sh
cp -r klor ~/qmk_firmware/keyboards/geigeigeist/klor
```

Build and flash:

```sh
qmk compile -kb geigeigeist/klor -km default
qmk flash -kb geigeigeist/klor -km default
```

## Bootloader

Enter the bootloader in 2 ways:

- **Bootmagic reset**: Hold down the key at (0,0) in the matrix
- **Physical reset button**: Briefly press the button on the PCB
