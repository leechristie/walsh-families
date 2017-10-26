# Walsh Families 1.0.0

This data set lists 3-bit classes and their Walsh structures as define by [Christie, Lee A. (2016)](https://openair.rgu.ac.uk/handle/10059/1567). The repository contains the source code for generating the data.

## Description of Generated Data Files

The generated output files `classes.txt` and `families.txt` are available from the [Releases](https://github.com/leechristie/walsh-families/releases) page of this repository.

### 3-Bit Classes

`classes.txt` contains list of 3-bit classes, one per line, with elements space-separated.

For example, `0 5 6 2 2 1 4 6` corresponds to the class \[0  5  6  2  2  1  4  6\].

This file is terminated by the string `"END\n"`.

### Walsh Families

`families.txt` contains a the list of 3-bit classes with their Walsh family separated by a tab, one per line.

For example, `[3, 2, 3, 0, 5, 0, 7, 6] {3F, 6F, 7B, 7F}` indicates that the class \[3 2 3 0 5 0 7 6\] belongs to the Walsh family {3F, 6F, 7B, 7F}.

## Generating Classes and Families

The list of 3-bit classes can be run from the command line using the Python 3
interpreter. The classes are printed to standard output and can be redirected to
a file. For example, if the source file is named classes.py, output can be sent
to a file as such:

    python3 classes.py >classes.txt

The 3-Bit families can be compiled using GCC or any other standard C compiler.
For examples, if the source file is named families.c:

    gcc families.c -o families

The 3-bit families can be calculated by reading in lines of text from standard
input representing ranks separated by spaces. The program will output the Walsh
family to standard output of the input class, then wait for another class. The
program will terminate on receiving another line of text such ad the terminator
"END". The output of the Python script for generating all 3-bit classes is in
this format, and thus can be piped to the families generating program as
follows:

    families <classes.txt >families.txt

Alternatively, both programs may be run together using a pipe operator:

    python3 classes.py | family >families.txt
