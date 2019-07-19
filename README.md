# Fractal-Image
Created Fractal Image and wrote it to bitmap file using C++

Used Mandelbrot algorithm to create a fractal image and wrote it to a bitmap file.

Fractals have self similarity and non integer dimensions

Complex Number Fractals

The Mandelbrot set is a set of points on a complex plane. 

To use the mandelbrot set we have to use an algorithm based on the recursive formula :

Z(n) = (Z(n-1))^2 + C

C : it is our current point on the plane.
We stop iterating if we reach the maximum number of iterations or abs(Z) > constant

The number of iterations at each point determine the color and the intensity at those pixels.

The beauty of the fractals is seen when we zoom by fixing some point. Hence there is a functionality for zoom.
It is observed that we can magnify the fractal image as many times but after every step we see the same shape.

