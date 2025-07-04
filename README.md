# mandelbrot-julia
Simple C program to generate either Mandelbrot or Julia in ppm format.

Instructions:
  1. Change the bool variable named julia to either false or true to switch between generating a Julia set or a Mandelbrot set.
  2. Compile the program to generate your binary: gcc <cprogram>.c -o <binary>
  3. Use the binary to generate the image: ./<binary> <filename>.ppm
  4. View the image using your preferred software. In Windows GIMP can render .ppm files. 
