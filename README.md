# BOUNCING CIRCLE IN C (USING SDL2)

## How this works:

1. Window & Renderer: SDL window and renderer are created.
2. Ball Movement: Ball position is updated each frame.
3. Collision Detection: Ball velocity is reversed when it hits a wall.
4. Rendering: The ball is drawn as a filled circle (pixel by pixel in this simple version).
5. Frame Rate Control: SDL_Delay(16) roughly gives 60 FPS.

## Prequisite

1. Ubuntu

   ```bash
   # For only SDL2
   sudo apt update -y
   sudo apt install libsdl2-dev -y
   # Optional but recommended if your project uses other SDL modules:
   sudo apt install libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
   ```

   ```bash
   # then compile as
   gcc -Wall -Wextra -g -o bouncing_circle.out bouncing_circle.c `sdl2-config --cflags --libs` -lm
   ```

2. Windows

   1. **Install MSYS2:**  
      [https://www.msys2.org/](https://www.msys2.org/)

   2. **Install GCC and SDL2 using MSYS2:**

   ```bash
   pacman -S mingw-w64-x86_64-gcc
   pacman -S mingw-w64-x86_64-SDL2
   ```

   3. Compile using

   ```bash
   gcc bouncing_circle.c -o bouncing_circle.exe `sdl2-config --cflags --libs`
   ```

### Tips for improvement:

1. Use SDL2_gfx library to draw a circle more efficiently instead of pixel loops.
2. Add keyboard controls or gravity for more interesting physics.
3. Use SDL_GetTicks() for precise frame timing instead of fixed delay
4. Resizable Window (grid area should update based on bouncing)
