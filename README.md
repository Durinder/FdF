# FdF
This project is about creating a simplified graphic “wireframe” representation of a relief landscape linking various points (x, y, z) via segments. 

![Screen shot of FdF](https://github.com/Durinder/FdF/blob/master/Screen%20Shot%202020-02-19%20at%202.46.53%20PM.png)

A valid input is an .fdf file, which contains numbers indicating z (height), seperated by spaces. Their relative positioning marks the x and y coordinates.

Eg. input for the image above is:\
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0\
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0\
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0\
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0\
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0\
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0\
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0\
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0\
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0\
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0\
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

Image can be moved with the arrow keys. Height differences may be flattened with the / key or elevated with the * key. Zooming is done with - and + for smaller and larger image respectively. Perspective can be switched into a top down view and back with the space bar.
