#!/bin/bash

mkdir build/
mkdir build/bin


cp -r source/bash/latex_output/ build/bin/
cp -r source/bash/src/ build/bin/src
cp source/bash/chart.r build/bin/
cp source/bash/generate_latex.sh build/bin/
cp source/bash/start.sh build/bin/

cmake .
make
cp roots build/bin/



chmod +x build/bin/roots
chmod +x build/bin/start.sh
chmod +x build/bin/generate_latex.sh




ls | grep -P ".*make" | xargs -d"\n" rm -r
