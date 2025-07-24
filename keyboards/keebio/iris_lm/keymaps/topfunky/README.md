# Topfunky Iris LM Keymap

A custom keymap for the Keebio Iris LM split keyboard with Dvorak layout and enhanced RGB features.

## Features

### Layout

-   **Base Layer**: Dvorak layout with ergonomic modifications and home row hold mods for gui, layers, ctrl, alt, etc.
-   **Lower Layer**: Navigation and deletion by letter. Also includes some browser key combos and Zoom key combos for mute, share screen, etc.
-   **Raise Layer**: Navigation and deletion by word.
-   **Media Layer**: Advanced media controls and window management.

### RGB Matrix Features

-   **Default Animation**: Cycle left-right animation at speed 10 (slow)
-   **Layer Colors**: Illuminate all LEDs when a layer is selected.
    -   Default (Dvorak): Cycle animation
    -   Lower: Cyan
    -   Raise: Green
    -   Media: Purple

### Key Features

#### Base Layer (Dvorak)

-   Standard Dvorak layout with ergonomic modifications
-   Mod-tap keys for common modifiers:
    -   `MT(MOD_LCTL, KC_DOT)` - Control when held, dot when tapped
    -   `MT(MOD_LALT, KC_P)` - Alt when held, P when tapped
    -   `MT(MOD_LGUI, KC_E)` - GUI when held, E when tapped
-   Layer-tap keys:
    -   `LT(1, KC_U)` - Lower layer when held, U when tapped
    -   `LT(2, KC_I)` - Raise layer when held, I when tapped
-   Special keys:
    -   `MT(MOD_LSFT, KC_TAB)` - Shift when held, Tab when tapped
    -   `HYPR(KC_NO)` - Hyper modifier (Ctrl+Alt+Shift+GUI)
    -   `MEH(KC_NO)` - Meh modifier (Ctrl+Alt+Shift)

#### Lower Layer

-   Navigate by character
-   Delete one character at a time (backspace, delete)
-   Next/previous browser tab (or any app that uses tabs)
-   Search browser tabs
-   Zoom controls (mute microphone, turn off video, share screen, raise hand)
-   Check off task in VSCode Todo+ Markdown plugin

#### Raise Layer

-   Function keys (F1-F11)

#### Media Layer

-   Window management shortcuts:
    -   `HYPR(KC_ENT)` - Hyper + Enter
    -   `HYPR(KC_LEFT)` - Hyper + Left Arrow
    -   `HYPR(KC_RGHT)` - Hyper + Right Arrow
    -   `C(KC_UP)` - Ctrl + Up Arrow
    -   `C(KC_DOWN)` - Ctrl + Down Arrow
-   Media controls:
    -   `KC_MPRV` - Previous track
    -   `KC_MNXT` - Next track
    -   `KC_VOLU` - Volume up
    -   `KC_MSTP` - Stop
    -   `KC_MPLY` - Play/Pause
    -   `KC_VOLD` - Volume down
-   Tapping term
    -   Print current tapping term
    -   Increment, decrement

### RGB Matrix Configuration

The keymap includes RGB matrix features.

Layer-specific colors are set in `layer_state_set_user()`:

-   Each layer gets a distinct color for easy identification
-   Default layer maintains the cycle animation
-   Other layers use solid colors when activated
-   There are currently no colors for other modifier keys such as shift, GUI, etc.

### Build Configuration

Format source with `make format` or:

```bash
clang-format -i keyboards/keebio/iris_lm/keymaps/topfunky/keymap.c
```

To build this keymap:

```bash
qmk compile -kb keebio/iris_lm -km topfunky
```

### Author

Geoffrey Grosenbach (@topfunky) - 2025
