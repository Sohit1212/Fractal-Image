#ifndef MANDELBROT_H
#define MANDELBROT_H

namespace fractalProgram {

class Mandelbrot
{
    public:
        static const int MAX_ITERATIONS = 100;


    public:
        Mandelbrot();
        virtual ~Mandelbrot();

    static int getIterations(double x,double y);

};
}
#endif // MANDELBROT_H
