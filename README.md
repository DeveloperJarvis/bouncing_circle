# BOUNCING CIRCLE IN C (USING SDL2)

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
