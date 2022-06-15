42 Paris project - miniRT

![Screenshot 1](./saves/cylinder.bmp?raw=true)

A basic RayTracer using minilibX

<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cl4cq9w7c004409k3asnbj82v/project/1633981" alt="alienard's 42 miniRT Score" /></a>



Goals :	
- introduct us to the RayTracing algorithms
- to the implementation of mathematics formulas
- step up in terms of parsing and error handling

The configuration file had very precise restrictions, which lead me to implement my very first testing automation : [invalid_rt_file_tester](https://github.com/lienardale/invalid_rt_file_tester)

Stack :  

<a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> 
	<img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> 
</a> 

Handles :

- clean window handling (no problem when resizsd, minimized or so on)

- 5 simple geometric objects (plan, sphere, cylinder, square, triangle)

- multiple light spots (intensity, shadows, ambiant light)

- multiple cameras (pov)

- objects intersection

- color and size of objects are defined in parsing and can be modified in the input file

- transformations (translation and rotation)

- "- save" option that saves the outpout into a .bmp file

- exiting wiht the 'esc' key or the red cross button

- changing the pov with the 'space' key

- low resolution mode with the 'r' key (pressing it again will make the resolution go back to high)

- mooving the pov forward, back, left and right with the 'w', 's', 'a' and 'd' keys

- mooving the pov up and down with the 'page up' and 'page down' keys

- rotating the pov up, down, left, right with the corresponding arrow keys

Screenshots :

![Screenshot 2](./saves/example.bmp?raw=true)
![Screenshot 3](./saves/lights.bmp?raw=true)
![Screenshot 4](./saves/objects.bmp?raw=true)
![Screenshot 5](./saves/triangle.bmp?raw=true)