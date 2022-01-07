#!/bin/bash

mkdir build/
mkdir build/bin


cp -r source/bash/latex_output/ build/
cp -r source/bash/src/ build/bin/src
cp source/bash/chart.r build/bin/
cp source/bash/generate_latex.sh build/bin/
cp source/bash/start.sh build/bin/

#roots must be in /build/bin/
#add which call cmake and compile roots and copy binary in /build/bin/


