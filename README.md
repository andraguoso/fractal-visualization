# Fractal Visualization
Visualization of complex-plane-based fractals in grayscale using SFML.
### Why Burning Ship
I chose the Burning Ship fractal as my third implementation because of its derivation from the Mandelbrot set. I wanted the three fractals to be based in the complex plane. The Burning Ship's variation relies on taking the absolute values of the real and imaginary components before each iteration. This eliminates the original symmetry of the Mandelbrot set, creating a completely new pattern. While the color scheme I picked did not fully capture the level of detail of this piece, nor did the default image reveal its most popular section, I wanted to highlight the bigger picture and its border.
### Compiling
For macOS:
Assuming SFML was installed using the package manager Homebrew,

g++ -std=c++17 file_name.cpp -o file_name \
-I$(brew --prefix sfml)/include \
-L$(brew --prefix sfml)/lib \
-lsfml-graphics -lsfml-window -lsfml-system

./file_name
