# Fake Keyboard/Mouse Checker

Simple keyboard and mouse hook that detects synthetic input.

Examples of synthetic input include: macros, autoclickers, any call to SendInput()

Examples of non-synthetic input: input directly sent by the driver (eg. Razer Synapse macros), real user input

## Usage
1. Run the program (preferably without any other programs that interefere with mouse/keyboard hooks)
2. The program will print `KB Injected: 0/1` and `Mouse Injected 0/1` whenever you press a key or click with the left/right mouse buttons.
3. If `KB Injected` or `Mouse Injected` is 1, then that means synthetic input was detected.