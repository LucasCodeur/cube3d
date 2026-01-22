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

## 1. Pre-requisites

- Linux or macOS
- GCC or clang
- Make installed

## 2. Download MiniLibX

```bash
wget https://cdn.intra.42.fr/document/document/44923/minilibx-linux.tgz
```

Extract it inside the project directory.

## 3. Compile

```bash
make
```

## 4. Run

```bash
./cub3D maps/classic.cub
```

---

# 📄 Map Format (`.cub`)

- Walls: `1`
- Empty space: `0`
- Player spawn: `N`, `S`, `E`, `W` (facing direction)
- Space : ` `
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

## What is Raycasting?

Raycasting is an algorithm that **traces rays** from the player’s position to detect walls and render a 3D representation.

## Algorithm

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

# 🪜 In-depth explanation 

---

## 🧩 Technical Explanation

To implement raycasting, multiple steps are required.
First, we define the **field of view**. Then, for each x coordinate of the screen, we trace a ray.
Once a ray hits a wall, we keep:

* the **distance** to the wall
* the **exact collision position**

The distance determines the height of the wall strip to display, and the collision position allows correct **texture mapping**.

### 1️⃣ Define the data structures

The main structures used are **vectors**, which represent the player and all elements of the project.

Since we manipulate many **x (abscissa)** and **y (ordinate)** values, vectors are the most relevant structure.

**What is a vector?**
A vector is a mathematical structure that stores coordinates in *n* dimensions.
For Cube3D, we only use **2 dimensions: x and y**.

---

### 2️⃣ Define the FOV

**What is the FOV (Field of View)?**
The FOV refers to the observable area visible to the player when looking straight ahead. It is usually measured in **degrees**.

**How is the FOV defined?**
The player has a position in the 2D map.
From this position:

* a **direction vector** defines where the player is looking
* a **plane vector** defines the width of the field of view

Together, these vectors define the player’s FOV.

---

### 3️⃣ Define a ray

The core of raycasting is to create rays in order to scan the environment.

First, we must define the **direction of each ray** according to the player’s FOV.

**How to define the ray direction?**
We convert a **screen x coordinate** into a **camera space coordinate**.

The raycasting camera does not work directly with screen pixels.
Instead:

* the screen space goes from `0` to `screen_width`
* the camera space goes from `-1` to `1`

So we convert the screen x coordinate into a **mathematical plane coordinate**.

Once this is done, we obtain a **camera vector** corresponding to the current screen column.
By combining this camera vector with the player’s direction and plane vectors, we get the **final ray direction**.

After defining the ray direction, we need to compute the distance until the ray hits a wall.
To do this, we use the **DDA algorithm**.

---

### 4️⃣ DDA (Digital Differential Analyzer)

The DDA algorithm is a line-drawing algorithm used in computer graphics to generate a line between two points.

It works by computing incremental distances along the **x** and **y** axes.

In Cube3D:

* we compute the incremental distances of x and y along the ray
* this corresponds to the slope of the ray
* we then step through the map grid until the ray collides with a wall

At each iteration:

* we check the 2D map to see if the current cell is a wall
* if it is, we stop the loop

At each step, we choose the smallest distance needed to reach the next grid cell, either on the x-axis or the y-axis.
We also store which axis was crossed, as this information is useful later for texture mapping.

---

### 5️⃣ Compute the height of a wall strip

Once we know the distance between the player and the wall collision point, we can compute the height of the wall strip to draw.

The logic is simple:

* the greater the distance, the smaller the wall appears on screen

The computed distance gives a ratio that is applied to the window height to determine the wall height.
Then, we compute the **top** and **bottom** positions of the wall strip on the screen.

---

### 6️⃣ Draw the wall strip

To draw the wall strip, we need to map the correct texture onto it.

Each wall corresponds to a specific texture, and texture mapping is done using **linear interpolation**.

Required information:

* exact collision position on the wall
* texture dimensions
* wall strip height

Steps:

1. **Compute the texture step**
   The step is calculated as the texture height divided by the wall strip height.

2. **Compute the texture x coordinate**
   We use the fractional part of the collision position multiplied by the texture width.
   If the ray hits the wall from the wrong side, we invert the x coordinate to avoid a mirrored effect.

3. **Compute the texture y coordinate**
   The y coordinate is computed using the current pixel position relative to the top of the wall strip, multiplied by the texture step.

Finally, we loop from the top of the wall strip to the bottom:

* retrieve the corresponding pixel from the texture buffer
* write it into the image buffer

This process is repeated for every x coordinate of the screen.

---

# 🌟 Features

- ⚡ Real-time **frame rate**
- 🎯 **FPS counter**
- 🗺 **Minimap**
- 🖱 **Mouse input**
- ✈  **upward and downward view**
