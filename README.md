# miniRT

**miniRT** is a minimalistic Ray Tracer project developed in C, aimed at rendering basic 3D scenes. It follows the specifications for the 42 School's `miniRT` project, focusing on the implementation of simple ray tracing techniques to render scenes with geometric shapes, lights, and camera controls.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Running the Program](#running-the-program)
  - [Controls](#controls)
  - [Scene Files](#scene-files)
- [Supported Objects and Effects](#supported-objects-and-effects)
- [Roadmap](#roadmap)
- [License](#license)

---

## Features

- **Real-time Ray Tracing**: Render 3D scenes with ray tracing, a technique that simulates light as rays, allowing for realistic reflections, refractions, and shadows.
- **Geometric Shapes**: Support for rendering spheres, planes, and cylinders (triangle in the bonus).
- **Lighting**: Implements lighting and shading.
- **Camera Controls**: Configure camera position and orientation within the scene.
- **Minimalistic Design**: Efficient and lightweight implementation in C for low-level system performance.

## Getting Started

### Prerequisites

Before running miniRT, ensure you have the following:

- A Unix-like operating system (Linux or macOS)
- `gcc` (GNU Compiler Collection)
- `make`
- X11 libraries (`libx11` and `libxext`) for window handling on Linux

To install X11 libraries on Linux (if not installed):

```bash
sudo apt-get install libx11-dev libxext-dev
```

### Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/Norias1011/miniRT.git
   cd miniRT
   ```

2. **Build the Project**:

   Use `make` to compile the project:

   ```bash
   make
   ```

   After `make` to compile, use `make bonus` to compile the bonus:

   ```bash
   make bonus
   ```

4. **Run the Ray Tracer**:

   After compilation, you can run the program with a scene file (provided or custom).

   ```bash
   ./miniRT scenes/example.rt
   ```

---

## Usage

### Running the Program

To run `miniRT`, provide it with a scene description file (`.rt` extension). Example scene files are located in the `scenes` directory.

```bash
./miniRT scenes/sample.rt
```

### Controls

- **ESC**: Exit the program
- **Keyboard**: WASD and c,SPACE to go up and down. + and - to zoom in the scene (controls available only in the bonus part)

### Scene Files

Scene files describe the objects, lights, and camera in the scene. They use a simple, human-readable format. Below is an example of a scene file:

```
# Example scene file
A 0.2 255,255,255       # Ambient light
C 0,0,-5 0,0,1 70       # Camera
L 5,5,-10 0.8 255,255,255 # Light

sp 0,0,20 5 255,0,0     # Sphere (center_x, center_y, center_z) (radius) (R,G,B)
pl 0,1,0 0,-1,0 0,255,0 # Plane (center_x, center_y, center_z) (3D vector orientation from -1.0 to 1.0) (R,G,B)
cy 0,0,10 0,0,1 1 5 255,255,0  # Cylinder (center_x, center_y, center_z) (3D vector orientation from -1.0 to 1.0) (cylinder diameter) (cylinder height) (R,G,B)
tr 20,15,14 23,75,89 36,45,75 255,0,255 # Triangle (Point A) (Point B) (Point C) (R,G,B) Only in bonus
```

---

## Supported Objects and Effects

### Geometric Objects

- **Spheres** (`sp`)
- **Planes** (`pl`)
- **Cylinders** (`cy`)
- **Triangles** (`tr`) only for the bonus part

### Lighting

- **Ambient Light** (`A`)
- **Point Light** (`L`)

### Camera

- Define camera position, orientation, and field of view (FOV) using the `C` identifier in scene files.

---

## Roadmap

Planned features for future releases:

- **Additional Shapes**: Support for more complex shapes like cones and triangles.
- **Texture Mapping**: Add support for applying textures to surfaces.
- **Reflection and Refraction**: Implement advanced light effects such as mirrors and transparent objects.
- **Multithreading**: Optimize rendering speed by leveraging multi-core processors.


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Thank you for checking out **miniRT**! Feel free to reach out if you have any questions or suggestions.
