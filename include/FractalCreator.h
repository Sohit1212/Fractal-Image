#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H
#include<string>
#include<vector>
#include"Zoom.h"
#include"Mandelbrot.h"
#include<cstdint>
#include<memory>
#include<math.h>
#include"ZoomList.h"
#include"Bitmap.h"
#include"RGB.h"

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
        vector<int> m_ranges;
        vector<RGB> m_colors;
        vector<int> m_rangeTotals;
        bool m_bGotFirstRange = false;

        void calculateRangeTotals();
        void calculateIterations();
        void calculateTotalIterations();
        int getRange(int iterations) const;
        void drawFractal();
        void writeBitmap(string name);

    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();
        void addRange(double rangeEnd, const RGB& rgb);
        void addZoom(const Zoom& zoom);
        void run(string name);


};

}
#endif // FRACTALCREATOR_H
