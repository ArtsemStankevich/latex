#!/usr/bin/env Rscript
args <- commandArgs(TRUE)
## Read the input data
a<-read.table(args[1])
## Set the output file name/type

png(file="out.png")
## Plot your data
par(bg=toString(a$V6))
curve(a$V1*x^2+a$V2*x+a$V3, from=a$V4, to=a$V5, main=paste(toString(a$V1),"x^2 + ",toString(a$V2),"x + ",toString(a$V3)), xlab="x", ylab="y")
## Close the graphics device (write to the output file)
dev.off()


