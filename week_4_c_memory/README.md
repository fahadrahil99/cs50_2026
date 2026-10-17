Volume

A program that changes the volume of a WAV audio file by a given factor.

Description

volume reads a WAV file as input, multiplies each audio sample by a scaling factor provided on the command line, and writes the result to a new WAV file. A factor greater than 1 makes the audio louder, while a factor between 0 and 1 makes it quieter. The 44-byte WAV header is copied unchanged, and only the 16-bit samples that follow are scaled.

Usage
./volume input.wav output.wav factor
input.wav: the WAV file to read
output.wav: the WAV file to create
factor: the number by which to scale the volume (e.g. 2.0 doubles it, 0.5 halves it)
Example
./volume input.wav output.wav 2.0

This creates output.wav with the volume of input.wav doubled.

Notes
The program expects exactly three command-line arguments and exits with a message if they are missing or incorrect.
Input and output files are handled in binary mode.