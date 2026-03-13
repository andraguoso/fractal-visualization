/* Mandelbrot Generation */
#include <SFML/Graphics.hpp>
#include <complex>
using namespace std;
/*
    Initialization of parameters:
    - Resolution: 800x800 (int width x int height),
    - Iteration limit: 150 (int MAX),
    - Bounds of the complex plane: (-2.0, 2.0) for Re, (-2.0, 2.0) for Im
*/
const unsigned int width = 900, height = 900, MAX = 550;
int main() {
    sf::Image mandelbrot_image({width, height}, sf::Color(0, 0, 0));
    
    for (unsigned int x = 0; x < width; x++)
        for (unsigned int y = 0; y < height; y++) {
            
            // Adequating pixel scale to the bounds of the complex plane
            double Re = (x - width / 2.0) * 4.0 / width, Im = (y - height / 2.0) * 4.0 / height;
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
                    Mathematical expression : z(n+1) = z(n)*z(n) + c
        
                    In the Mandelbrot fractal, through each iteration 
                    the complex c represents each point in the defined 
                    complex plane.
                */

                z = z * z + c;
                iter++;
            }

            /* 
                Visualization: color choice

                I opted for grayscale because I felt it would allow for much faster computation
                and overall personal choice. 
            */

            if (iter < MAX) {
            // Depending on the number of iterations it took to diverge
                int gray = (double(iter) / MAX) * 255;
                mandelbrot_image.setPixel({x, y}, sf::Color(gray, gray, gray));
            }
            else {
            // If the series never diverges, then it remains bounded
            // and belongs inside the set, colored black.
                mandelbrot_image.setPixel({x, y}, sf::Color(0, 0, 0));
            }
        }

        // Exporting the generated image
        mandelbrot_image.saveToFile("mandelbrot.png");
        if (mandelbrot_image.saveToFile("mandelbrot.png"))
            printf("Successful");
        else
            printf("Unsuccessful");
}