#include<iostream>
#include "FractalCreator.h"
#include"Bitmap.h"
#include"assert.h"
#include"Mandelbrot.h"

namespace fractalProgram {

void FractalCreator::addRange(double rangeEnd, const RGB &rgb) {

    m_ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS);
    m_colors.push_back(rgb);

    if(m_bGotFirstRange) {
        m_rangeTotals.push_back(0);
    }
    m_bGotFirstRange = true;

}

void FractalCreator::addZoom(const Zoom& zoom){

    m_zoomlist.add(zoom);
}

void FractalCreator::run(string file_name) {

    calculateIterations();
    calculateTotalIterations();
    calculateRangeTotals();
    drawFractal();
    writeBitmap(file_name);

}

FractalCreator::FractalCreator(int width, int height): m_width(width),m_height(height),
                                m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),m_fractal(new int[m_width*m_height]{0}),
                                    m_bitmap(m_width,m_height),m_zoomlist(m_width,m_height)
{
    m_zoomlist.add(Zoom(m_width/2,m_height/2,4.0/m_width));
}

FractalCreator::~FractalCreator()
{
    //dtor
}

void FractalCreator::calculateRangeTotals() {
    int rangeIndex = 0;

    for(int i=0;i < Mandelbrot::MAX_ITERATIONS;i++) {
        int pixels = m_histogram[i];

        if(i >= m_ranges[rangeIndex+1]) rangeIndex++;

        m_rangeTotals[rangeIndex] += pixels;
    }

}

void FractalCreator::calculateIterations() {

    for(int y=0;y<m_height;y++)
        for(int x=0;x<m_width;x++) {

            pair<double,double> coords = m_zoomlist.doZoom(x,y);

            int iterations = Mandelbrot::getIterations(coords.first,coords.second);

            m_fractal[y*m_width+x] = iterations;

            if(iterations != Mandelbrot::MAX_ITERATIONS)
                m_histogram[iterations]++;
        }
}

void FractalCreator::calculateTotalIterations() {

    for(int i=0; i<Mandelbrot::MAX_ITERATIONS;i++) m_total+=m_histogram[i];

}

void FractalCreator::drawFractal() {

    for(int y=0;y<m_height;y++)
        for(int x=0;x<m_width;x++) {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;


            int iterations = m_fractal[y*m_width+x];

            int range = getRange(iterations);
            int rangeTotal = m_rangeTotals[range];
            int rangeStart = m_ranges[range];

            RGB& startColor = m_colors[range];
            RGB& endColor = m_colors[range+1];
            RGB colorDiff = endColor-startColor;

            //double hue = 0.0;
            if(iterations != Mandelbrot::MAX_ITERATIONS) {

                int totalPixels = 0;
//                double hue = 0.0;

                for(int i=0/*rangeStart*/;i<=iterations;i++)  {
//                    hue += ((double)m_histogram[i])/m_total;
                    totalPixels += m_histogram[i];
                }

                red = startColor.r + colorDiff.r * ((double)totalPixels) / rangeTotal;
                green = startColor.g + colorDiff.g* ((double)totalPixels) / rangeTotal;
                blue = startColor.b + colorDiff.b * ((double)totalPixels) / rangeTotal;

/*
                if(hue >= 0.95) {
                        if(hue >=0.95 && hue < 0.97) {
                            green = pow(55,hue);
                            red = pow(255,hue);
                            blue = pow(200,hue);
                        } else if(hue>=0.97&& hue<0.98) {
                            green = pow(100,hue);
                            red = pow(200,hue);
                            blue = pow(250,hue);

                        } else {
                            green = pow(100,hue);
                            red = pow(250,hue);
                            blue = pow(250,hue);
                        }
                }
                else if(hue > 0.85 && hue < 0.95) {
                    green = pow(50,hue);
                    red = pow(150,hue);
                    blue = pow(250,hue);
                }
*/

            }
            m_bitmap.setPixel(x,y,red,green,blue);

        }

}
int FractalCreator::getRange(int iterations) const {

    int range = 0;

    for(int i=1; i< m_ranges.size();i++) {
        range = i;

        if(m_ranges[i] > iterations) break;
    }

    range--;

    assert(range > -1);
    assert(range < m_ranges.size());

    return range;

}

void FractalCreator::writeBitmap(string name){
    m_bitmap.write(name);
}

}
