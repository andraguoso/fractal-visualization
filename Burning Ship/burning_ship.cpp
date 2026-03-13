/* Burning Ship fractal generation */
#include <SFML/Graphics.hpp>
#include <complex>
using namespace std;
const unsigned int width = 800, height = 800, MAX = 390;
int main() {
    sf::Image burning_ship_image({width, height}, sf::Color(0, 0, 0));
    
    for (unsigned int x = 0; x < width; x++)
        for (unsigned int y = 0; y < height; y++) {
            
            // Adequating pixel scale to the bounds of the complex plane
            // The reason for multiplying a (-) to the conversion in Im is
            // that in order to see the traditional image of the Burning Ship,
            // it must be inverted.
            double Re = (double(x) / width) * 3.2 - 2.2, Im = (double(y) / height) * 3.2 - 1.8;
            int iter = 0; // Variable to count number of iterations, reset for every pixel
            complex<double> c(Re, Im); // Initializing c at every pixel
            complex<double> z(0,0);
            
            /* 
                Iterative Computation: 
                Fractal nature is determined by iterative transformations
                applied to a set of points. In order to emulate this, the 
                while loop is written with the conditionals (abs(z) < 2.0)
                and (iter < MAX), respectively:
                    - The complex z's module must always be less than 2,
                    - The maximum number of iterations has not yet been 
                      reached.
            */
            
            while (abs(z) < 2.0 && iter < MAX) {
                /*
                    Mathematical expression: 
                        z(n+1) = (|Re(z(n))| - i * |Im(z(n))|)^2  + c

                    The Burning Ship fractal is a variation of the Mandelbrot,
                    evidentiated through the initialization and iterating values.
                    In each variation, c represents each point of the complex plane,
                    and z starts at zero.
                */
                double real = abs(z.real()), imag = abs(z.imag());
                z = complex<double>(real*real - imag*imag, 2*real*imag) + c;
                iter++;
            }

            if (iter < MAX) {
            // Depending on the number of iterations it took to diverge
                int gray = (double(iter) / MAX) * 255;
                burning_ship_image.setPixel({x, y}, sf::Color(gray, gray, gray));
            }
            else {
            // If the series never diverges, then it remains bounded
            // and belongs inside the set, colored black.
                burning_ship_image.setPixel({x, y}, sf::Color(0, 0, 0));
            }
        }

        // Exporting the generated image
        if (burning_ship_image.saveToFile("burning_ship.png"))
            printf("Successful");
        else
            printf("Unsuccessful");
}