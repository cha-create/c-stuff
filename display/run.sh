#! /bin/bash

gcc $1.c -o $1 lib/$2
./$1
