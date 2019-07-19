#include<complex>
#include "Mandelbrot.h"

using namespace std;

namespace fractalProgram {

Mandelbrot::Mandelbrot()
{
    //ctor
}

Mandelbrot::~Mandelbrot()
{
    //dtor
}

int Mandelbrot::getIterations(double x,double y){

    complex<double> z(x,y);
    complex<double> c(-0.79,0.15);

    int iterations = 0;

    while(iterations < MAX_ITERATIONS) {
        z = z*z+ c;
        if(abs(z) > 2) break;

        iterations++;
    }

    return iterations;
}

}
