#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H
#include<string>
#include"Zoom.h"
#include"Mandelbrot.h"
#include<cstdint>
#include<memory>
#include<math.h>
#include"ZoomList.h"
#include"Bitmap.h"

using namespace std;

namespace fractalProgram {

class FractalCreator
{
    private:
        int m_width;
        int m_height;
        int m_total;
        unique_ptr<int[]> m_histogram;
        unique_ptr<int[]> m_fractal;
        Bitmap m_bitmap;
        ZoomList m_zoomlist;

    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();

        void calculateIterations();
        void calculateTotalIterations();
        void drawFractal();
        void addZoom(const Zoom& zoom);
        void writeBitmap(string name);
};

}
#endif // FRACTALCREATOR_H
