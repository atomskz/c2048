# c2048

Terminal-based [2048](https://en.wikipedia.org/wiki/2048_(video_game)) game
written in C. This repository currently contains only the **project skeleton**:
a clean, extensible foundation with module stubs. The game logic itself is not
implemented yet.

## Requirements

- A C11-capable compiler (GCC, Clang, or MSVC)
- CMake 3.15 or newer

No third-party libraries are used.

## Project structure

```text
c2048/
├── CMakeLists.txt      # Build configuration
├── README.md
├── .gitignore
├── include/            # Public headers, one per module
│   ├── board.h         # Game board representation
│   ├── game.h          # Game state and high-level flow
│   ├── render.h        # Terminal rendering
│   └── utils.h         # Shared helpers
└── src/                # Implementation
    ├── main.c          # Entry point
    ├── board.c
    ├── game.c
    ├── render.c
    └── utils.c
```

Headers live in `include/` and sources in `src/`. Separating the public
interface from the implementation keeps modules easy to reuse and makes the
include path explicit in the build.

## Build

```sh
cmake -S . -B build
cmake --build build
```

## Run

```sh
./build/c2048
```

Expected output:

```text
c2048 project initialized.
```

## Where the game logic will go

- **Board mechanics** (grid state, spawning tiles, moving/merging) →
  `src/board.c` / `include/board.h`
- **Game flow** (turn loop, score, win/lose detection, input handling) →
  `src/game.c` / `include/game.h`
- **Terminal drawing** (rendering the grid, screen refresh) →
  `src/render.c` / `include/render.h`
- **Shared helpers** (small reusable utilities) →
  `src/utils.c` / `include/utils.h`

`main.c` should stay thin: it wires the modules together and starts the game.

## Next steps

1. Define the board data structure in `board.h` and implement grid
   initialization and tile movement/merging in `board.c`.
2. Build the game loop in `game.c`: read input, apply a move, spawn a tile,
   check win/lose conditions.
3. Implement rendering in `render.c` to draw the grid to the terminal.
4. Add tile spawning with (pseudo)random placement.
5. Once the core is stable, consider adding unit tests and richer input
   handling (e.g. raw terminal mode).
