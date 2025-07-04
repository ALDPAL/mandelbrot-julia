#include <stdio.h>
#include <stdbool.h>

const int image_width = 500, image_height = 500; //Dimensiones de imagen
bool julia = false;

const double julia_startR = 0;
const double julia_startI = 0.8;
double map(int pix, int minIn, int maxIn, double minOut, double maxOut);
double sqr(double num);

int main(void) {

    printf("P3\n%d %d\n255\n", image_width, image_height);

    for (int i = 0; i < image_width; i++) {
        for (int j = 0; j < image_height; j++) {

            double startR = map(i, 0, image_width,-2, 2);
            double startI = map(j, 0, image_height,-2, 2);

            double newR = julia ? startR : 0;
            double newI = julia ? startI : 0;

            int n = 0;
            while(n < 100) {
                double currR = sqr(newR) - sqr(newI);
                double currI = 2 * newR * newI;

                newR = julia ? (currR + julia_startR) : (currR + startR);
                newI = julia ? (currI + julia_startI) : (currI + startI);

                if(sqr(newR) + sqr(newI) > 4)
                    break;

                n++;
            }

            double bright = map(n, 0, 100, 0, 255);

            bright = julia ? bright : 255 - bright;



            printf("%d %d %d\n", (int)bright, (int)bright, (int)bright);
        }
    }

    return 0;
}

double map(int pix, int minIn, int maxIn, double minOut, double maxOut) {
    return (double)(pix - minIn) / (maxIn - minIn) * (maxOut - minOut) + minOut;
}

//Funcion que devuelva el cuadrado de un parametro, ej. sqr(newR);
double sqr(double num){
    return num * num;
}
