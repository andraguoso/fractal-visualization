/* Julia Set Generation */
#include <SFML/Graphics.hpp>
#include <complex>
using namespace std;
/*
    Initialization of parameters:
    - Resolution: 800x800 (int width x int height),
    - Iteration limit: 150 (int MAX),
    - Bounds of the complex plane: (-2.0, 2.0) for Re, (-2.0, 2.0) for Im
*/
const unsigned int width = 800, height = 800, MAX = 550;
int main() {
    sf::Image julia_image({width, height}, sf::Color(0, 0, 0));
    
    complex<double> c(-0.4, 0.6); // Setting c to -0.4 + 0.6i for a specific level of detail
    
    for (unsigned int x = 0; x < width; x++)
        for (unsigned int y = 0; y < height; y++) {
            // Adequating pixel scale to the bounds of the complex plane
            double Re = (x - width / 2.0) * 4.0 / width, Im = (y - height / 2.0) * 4.0 / height;
            int iter = 0; // Variable to count number of iterations, reset for every pixel
            complex<double> z(Re, Im); // Initializing z at every pixel
            
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
        
                    The main difference between the Mandelbrot generation code and
                    this one is that they are reversed: in the first the complex z
                    starts at zero and c is variating, representing each point in
                    the complex plane. For the latter, it's the opposite: c is fixed,
                    and z represents each point in the complex plane.
                */

                z = z * z + c;
                iter++;
            }

            if (iter < MAX) {
            // Depending on the number of iterations it took to diverge
                int gray = (double(iter) / MAX) * 255;
                julia_image.setPixel({x, y}, sf::Color(gray, gray, gray));
            }
            else {
            // If the series never diverges, then it remains bounded
            // and belongs inside the set, colored black.
                julia_image.setPixel({x, y}, sf::Color(0, 0, 0));
            }
        }

        // Exporting the generated image
        if (julia_image.saveToFile("julia_set.png"))
            printf("Successful");
        else
            printf("Unsuccessful");
}
