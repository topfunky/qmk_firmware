# Topfunky Iris LM Keymap

A custom keymap for the Keebio Iris LM split keyboard with Dvorak layout and enhanced RGB features.

### Author

Geoffrey Grosenbach (@topfunky) - 2025

## Development

### Format

Format source:

```bash
clang-format -i keyboards/keebio/iris_lm/keymaps/topfunky/keymap.c
```

### Build

To build this keymap:

```bash
qmk compile -kb keebio/iris_lm/g1 -km topfunky
```

Output will be in the `.build` directory as `keebio_iris_lm_g1_topfunky` with `bin` or `elf` or `hex` extension.

Open the QMK Toolbox GUI app and flash the `/Users/topfunky/projects/qmk_firmware/.build/keebio_iris_lm_g1_topfunky.bin` file to the keyboard.

Each half must be flashed (with the same firmware). Plug in the keyboard, tap the reset button on the back (using a screwdriver), and flash with QMK Toolbox.

## Features

### Layout

-   **Base Layer**: Dvorak layout with ergonomic modifications and home row hold mods for gui, layers, ctrl, alt, etc.
-   **Lower Layer**: Navigation and deletion by letter. Also includes some browser key combos.
-   **Raise Layer**: Navigation and deletion by word. Also includes some Zoom shortcuts (mute, share screen, etc.).
-   **Media Layer**: Window management, tapping term adjustments.

### RGB Matrix Features

-   **Default Animation**: Cycle left-right animation at speed 10 (slow)
-   **Layer Colors**: Illuminate all LEDs when a layer is selected.
    -   Default (Dvorak): Cycle animation
    -   Lower: Cyan
    -   Raise: Green
    -   Media: Purple

### Key Features

#### Base Layer (Dvorak)

-   **Standard Dvorak layout** with ergonomic modifications
-   **Mod-tap keys** for common home row modifiers:
    -   `MT(MOD_LCTL, KC_DOT)` - Control when held, dot when tapped
    -   `MT(MOD_LALT, KC_P)` - Alt when held, P when tapped
    -   `MT(MOD_LGUI, KC_E)` - GUI when held, E when tapped
    -   `MT(MOD_LALT, KC_TAB)` - Alt when held, Tab when tapped
-   **Special keys**:
    -   `HYPR(KC_NO)` - Hyper modifier (Ctrl+Alt+Shift+GUI)
    -   `MEH(KC_NO)` - Meh modifier (Ctrl+Alt+Shift)
    -   `MO(3)` - Momentary Media layer

### RGB Matrix Configuration

The keymap includes RGB matrix features.

Layer-specific colors are set in `layer_state_set_user()`:

-   Each layer gets a distinct color for easy identification
-   Default layer maintains the cycle animation
-   Other layers use solid colors when activated
-   There are currently no colors for other modifier keys such as shift, GUI, etc.


