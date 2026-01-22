This project has been created as part of the 42 curriculum by <lud-adam>, <prigaudi>.

---

# 📝 Cube3D

**Cube3D** is a 42 school team project. The goal is to create a video game inspired by **Wolfenstein 3D** (1992, developed by **Muse Software**), one of the first FPS games in video game history.

This project allows students to learn:

- **Raycasting** in 2D to simulate 3D environments
- Working with **MiniLibX** (a minimal graphics library in C)
- Handling **vectors, structures, and arrays** in C
- Game logic and **map parsing**

---

# ⚙️ Instructions

### 1. Pre-requisites

- Linux or macOS
- GCC or clang
- Make installed

### 2. Download MiniLibX

```bash
wget https://cdn.intra.42.fr/document/document/44923/minilibx-linux.tgz
```

Extract it inside the project directory.

### 3. Compile

```bash
make
```

### 4. Run

```bash
./cub3D maps/classic.cub
```

---

# 🗂 Project Structure

```
cub3D/
├─ src/                # Source files
├─ inc/                # Header files
├─ maps/           # .cub map files
├─ textures/      # Wall textures
└─ Makefile
```

---

# 📄 Map Format (`.cub`)

- Walls: `1`
- Empty space: `0`
- Player spawn: `N`, `S`, `E`, `W` (facing direction)
- Example:

```
111111
1N0  1
100001
111111
```

---

# 🎮 Controls

- **W / A / S / D** → Move player
- **Mouse** → Look around / rotate view
- **ESC** → Exit

---

# Parsing

## Configuration elements checking

First, the program checks the number of arguments (one and only one is required) and its extension (.cub is accepted).
Then, the program validates that the path given as an argument can be opened and starts reading the configuration file. An empty file immediately returns an error and stops the program.
Each line is then validated one by one.

The following cases will return an error:

- Invalid element prefix.
- Duplicate definition of a configuration element.
- Missing configuration element.
- Invalid RGB format for the floor or the ceiling.

## Map checking

Once the six configuration elements are successfully parsed, the program starts parsing the map structure. The following cases will return an error:

- Empty line in the map structure.
- Unauthorized character.
- More than one player defined.
- Player outside the map.
- Open map.

# 🎨 Graphics (Raycasting)

Cube3D builds a 3D maze using **raycasting**, a technique to project a 2D map into a 3D perspective.

### What is Raycasting?

Raycasting is an algorithm that **traces rays** from the player’s position to detect walls and render a 3D representation.

### How It Works

1. **Data Structures**
   - Vectors represent positions and directions (`x`, `y`).

2. **Field of View (FOV)**
   - Defines the visible area in front of the player.
   - Combines **direction vector** + **plane vector** to determine the FOV width.

3. **Rays**
   - For each vertical screen column, calculate the ray direction in camera space.

4. **DDA Algorithm**
   - Step along the ray until it hits a wall.
   - Track distance and axis hit for texture mapping.

5. **Wall Strip Height**
   - Distance to the wall determines the vertical slice height on screen.

6. **Texture Mapping**
   - Use linear interpolation to map the wall texture correctly.
   - Repeat for every screen column.

> ⚠️ Note: Texture mapping relies on collision point, wall height, and texture dimensions.

---

# 🔹 Parsing

- Reads `.cub` maps and converts them into data usable for raycasting.
- Detects walls, empty spaces, and player start position.

---

# 🌟 Features

- ⚡ Real-time **frame rate**
- 🎯 **FPS counter**
- 🗺 **Minimap**
- 🖱 **Mouse input**

---

# 📚 Resources

- [Vector rotation in 2D](https://www.alibabacloud.com/blog/the-use-of-vector-rotation-in-a-two-dimensional-space_599766)
- [Cross product calculator](https://www.omnicalculator.com/fr/mathematiques/calculateur-produit-vectoriel)
- [YouTube: Raycasting tutorial 1](https://www.youtube.com/watch?v=mR3Rwyu52rA)
- [YouTube: Raycasting tutorial 2](https://www.youtube.com/watch?v=NbSee-XM7WA)
- [Lodev Raycasting tutorial](https://lodev.org/cgtutor/raycasting.html)
- [MiniLibX hook examples](https://42-cursus.gitbook.io/guide/minilibx/minilibx-hook-examples)
- [Raycasting explanation](https://perso.esiee.fr/~buzerl/sphinx_IMA/80%20raycast/raycast.html)

---

# ⚠️ Known Limitations

- Only 2D maps supported (no diagonal walls)
- Simple wall textures (no dynamic lighting)
- No enemies or shooting mechanics

---
