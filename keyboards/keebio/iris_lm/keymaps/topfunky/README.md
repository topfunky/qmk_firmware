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

-   **Standard Dvorak layout** with ergonomic modifications
-   **Mod-tap keys** for common home row modifiers:
    -   `MT(MOD_LCTL, KC_DOT)` - Control when held, dot when tapped
    -   `MT(MOD_LALT, KC_P)` - Alt when held, P when tapped
    -   `MT(MOD_LGUI, KC_E)` - GUI when held, E when tapped
    -   `MT(MOD_LALT, KC_TAB)` - Alt when held, Tab when tapped
-   **Layer-tap keys**:
    -   `LT(1, KC_U)` - Lower layer when held, U when tapped
    -   `LT(2, KC_I)` - Raise layer when held, I when tapped
    -   `LT(2, KC_D)` - Raise layer when held, D when tapped
    -   `LT(1, KC_H)` - Lower layer when held, H when tapped
-   **Special keys**:
    -   `HYPR(KC_NO)` - Hyper modifier (Ctrl+Alt+Shift+GUI)
    -   `MEH(KC_NO)` - Meh modifier (Ctrl+Alt+Shift)
    -   `MO(3)` - Momentary Media layer

#### Lower Layer

-   **Navigation shortcuts**:
    -   `A(KC_D)` - Alt+D
    -   `S(KC_1)` through `S(KC_0)` - Shift+number keys
    -   `KC_PGUP` / `KC_PGDN` - Page up/down
    -   `KC_UP` / `KC_DOWN` / `KC_LEFT` / `KC_RGHT` - Arrow keys
-   **Text editing**:
    -   `KC_DEL` - Delete
    -   `KC_BSPC` - Backspace
    -   `KC_TAB` - Tab
    -   `G(KC_TAB)` - GUI+Tab (application switching)
    -   `G(KC_SPC)` - GUI+Space (spotlight/launcher)
    -   `G(KC_ENT)` - GUI+Enter
-   **Modifier combinations**:
    -   `LSG(KC_LBRC)` - Show previous tab
    -   `LSG(KC_A)` - Search tabs
    -   `LSG(KC_RBRC)` - Show next tab
    -   `LSG(KC_S)` - Left Shift+GUI+S
    -   `LSG(KC_H)` - Left Shift+GUI+H
    -   `LSG(KC_V)` - Left Shift+GUI+V
    -   `LSG(KC_GRV)` - Left Shift+GUI+`
-   **Control combinations**:
    -   `C(KC_A)` - Ctrl+A - navigate to beginning of line
    -   `C(KC_E)` - Ctrl+E - navigate to end of line
    -   `S(KC_EQL)` - Shift+=
    -   `S(KC_SLSH)` - Shift+/

#### Raise Layer

-   **Function keys**: `KC_F1` through `KC_F11`
-   **RGB controls**:
    -   `RGB_TOG` - Toggle RGB on/off
    -   `RGB_MOD` - Cycle RGB modes
    -   `RGB_VAI` - Increase RGB brightness
    -   `RGB_VAD` - Decrease RGB brightness
-   **Text editing shortcuts**:
    -   `A(KC_BSPC)` - Alt+Backspace
    -   `G(KC_Z)` - GUI+Z (undo)
    -   `A(KC_DEL)` - Alt+Delete
-   **Navigation**:
    -   `C(KC_C)` - Ctrl+C - cancel command in terminal
    -   `A(KC_UP)` - Alt+Up
    -   `C(KC_R)` - Ctrl+R - search terminal history
    -   `A(KC_LEFT)` - Alt+Left
    -   `A(KC_DOWN)` - Alt+Down
    -   `A(KC_RGHT)` - Alt+Right

#### Media Layer

-   **Window management**:
    -   `HYPR(KC_ENT)` - Hyper+Enter - maximize window with Rectangle app on macOS
    -   `HYPR(KC_LEFT)` - Hyper+Left Arrow - resize window to 2/3
    -   `HYPR(KC_RGHT)` - Hyper+Right Arrow - resize window to 1/3
    -   `C(KC_UP)` - Ctrl+Up Arrow - macOS show all windows
    -   `C(KC_DOWN)` - Ctrl+Down Arrow - macOS show windows for current application
-   **Media controls**:
    -   `KC_MPRV` - Previous track
    -   `KC_MNXT` - Next track
    -   `KC_VOLU` - Volume up
    -   `KC_MSTP` - Stop
    -   `KC_MPLY` - Play/Pause
    -   `KC_VOLD` - Volume down
-   **Debug/Development**:
    -   `DT_PRNT` - Debug print tapping term
    -   `DT_UP` - Debug increase tapping term
    -   `DT_DOWN` - Debug decrease tapping term
    -   `LAG(KC_H)` - Hide other application windows

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
