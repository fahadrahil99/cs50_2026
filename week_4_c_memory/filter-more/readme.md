# Filter

A C program that applies image filters to 24-bit BMP files.

## Filters

- **Grayscale** (`-g`): replaces each pixel with the rounded average of its red, green and blue values.
- **Reflect** (`-r`): flips the image horizontally.
- **Blur** (`-b`): replaces each pixel with the average of the pixels in its 3x3 neighborhood.
- **Edges** (`-e`): detects edges using the Sobel operator.

## How it works

- Blur and edges read from a copy of the original image, so already-modified pixels never affect later calculations.
- Pixels outside the image boundary are skipped (blur) or treated as black (edges), so edges and corners need no special cases.

## Build and run

    make filter
    ./filter -g images/yard.bmp out.bmp

Replace `-g` with `-r`, `-b` or `-e` to pick a different filter.

## What I learned

Write a few lines in your own words about the snapshot idea, bounds checking, and anything that tripped you up.