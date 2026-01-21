 This project has been created as part of the 42 curriculum by <lud-adam>, <prigaudi>.
 
 # Description
Cube3d is a 42 school team project, the goal is to do a video game like **Wolfenstein 3D** released in 1992 developped by **Muse Software**, the first FPS is the world of videogame.
## Decomposition of the project
There are two main parts inside the projects, the traitements of input datas and the graphic.
#### Technic explication
### Graphic
The  graphic part consist to build a maze in a 3D form thanks to **raycasting**.
#### What is a raycasting ?
It an algorithm that allow to trace **rays** in order to scan the envirronements and display in a **3D** **representation**.
#### Technic explanation
In order to do a raycasting there are multiple steps to execute, the first things is the **field of view**, then with this on and for each x's of the screen we trace a ray, once the ray was did, keep the distance recover and the exact position of the collide on the wall, **the distance** will give the size of strip to display and the exact position on the wall will allow to do the **mapping of according texture**.
##### Step
###### 1. Define the structure of the data
The main structure was the vectors in order to represent the player, the differents elements of the project because we used a lot of x (abcisse) and y (ordinate), so the usefulness of a vector was pertinent.
**What is a vector ?**
A vector is mathematical structure, we're store n dimension, for cube3D it will be only **x** and **y**.
###### 2. Define the  FOV
**What is a FOV** ? (Field of View)
It refers to the observable area visible to a user when looking straight ahead, typically measured in **degrees.
**How to do the FOV ?**
So the player have a position in the 2D Map, that we recover, with this position we add a direction vector to constitute the direction  and a plane vector that will define the larger of the **field of view**.
###### 3. Define a ray
The main of the raycasting is to create
then we map x on the screen in order to constitute a vector camera.
##### 2. DDA (Digital Differential Analyzer)
The main algorithm to compute the rays was the DDA, it allow  to compute the size of each ray, for each x of the screen.  It consist to move in the space of 1 unit on x and y and take the smallest size step, and gradually increase the size of the ray. Once the ray collide a wall in the 2D map, we stop and we recover the value, in order to trace one strip of the wall.
#### Mapping of textures
### Parsing

# Instruction

# Resources


➠ Additional sections may be required depending on the project (e.g., usage
examples, feature list, technical choices, etc.).
