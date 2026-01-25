*This project has been created as part of the 42 curriculum by authomas, gchauvet.*

# CUB3D

## DESCRIPTION
Cub3D is a 42 graphic design project in C. It consists of making a graphical engine based on the one from the game "Wolfeinstein 3D" : a raycasting. This project requires to look for documentation on the internet to learn how to make such an engine, and the mathematical theory behind it.

This project’s objectives are similar to all the first year’s projects objectives: rigor, use of C, basic algorithms, information research, etc. It also helped us improving skills in these areas: manipulating the minilibx library, creating windows with it, processing colors in RGB and int format, keyboard/mouse events, drawing on and displaying a frame buffer,  data parsing, etc.

In conclusion, cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.

## INSTRUCTION
### Compiling and installation
In order to be able to launch the project on your machine, you must clone the repository from github or the vogosphere.

The machine must have the compiler **cc** linked to **clang 12.0.1 / gcc 13.3.0 or newer** for optimal compilation and the **build-essentials** apt package installed.

You can install it with the command :  
`sudo apt install build-essentials`

And you can check your compiler version and the cc linkage with the commands:  
`cc -v `

As the **minilibx** and the **libft** library directories are already included in the project files, there's no need to import them. They are also going to be compiled with the project using the Makefile provided.

To compile an executable for the mandatory part, run the command:  
`make`

To compile an executable for the bonus part, run the command:  
`make bonus`

Compiling both the mandatory part and the bonus part will give you two separate executables that can be launched independently, as the bonus one contains all the features of the mandatory one.

To delete easily the compilation files, run the command:  
`make clean`

To delete the executables, run the command:  
`make fclean`
Careful, this will delete **both** executables.

To recompile the whole project without worrying about removing the compilation files, run the command:  
`make re`

## Lauching the project

Now that the project is compiled and ready to be launched, you can now run it:  
`./cub3D <path to a .cub> `  
or  
`./cub3D_bonus <path to a .cub> `

(for .cub specification, cf. Feature list)
## RESSOURCES

The ressources used for this projects are: 
* https://lodev.org/cgtutor/raycasting.html used as reference for the main raycasting part.  
* https://lodev.org/cgtutor/raycasting2.html used as reference for the sprites display in the bonus part.  
* https://fr.wikipedia.org/wiki/Rotation_vectorielle used as a tool to understand vectorial rotations and the equation.  
* https://fr.wikipedia.org/wiki/Th%C3%A9or%C3%A8me_de_Pythagore used as a complementary tool for the raycasting equations.  

AI had a very minimal use in the project. It allowed us to have a quick access to documentation on functions (man), to make repetitive tasks like making lists of similar strings or sorting the source files for the Makefile.

The sprites and textures have been drawn by hand by gchauvet using the software GIMP except for this one : [kiwi](https://tenor.com/fr/view/kiwi-plus-spin-meme-gif-21106906)

## FEATURE LIST
As cub3D is a feature oriented project, here is a list of implemented feature, separated as part of mandatory or bonus:

* **Mandatory**
	- Raycasting
	- Color processing (floor and ceiling texture)
	- Texture display
	- Keyboard control

* **Bonus**
	- Collision
	- Doors
	- Mouse control
	- Minimap
	- Entity
		- Projectile
		- Item
		- Collectible
		- Enemies ([spin kiwi](https://tenor.com/fr/view/kiwi-plus-spin-meme-gif-21106906))

The executable cub3D takes in parameter a **.cub** file. It is a file containing elements for the program to know what to display (a map, path to textures, colors in rgb).

The file has to be formatted this way:
```
// Wall texture definition:
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture 

// Floor and ceiling color definition:
F 220,100,0
C 225,30,0

// Map definition :
        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
``` 

As the walls must have a different texture depending of their orientation, 4 textures are required. they must be preceded by an identifier (NO for north, SO for south...). The texture path can be the same, but it have to appear 4 times with the identifiers.

The floor and ceiling colors are inputed in the same way. There need to be 2 identifiers (C for ceiling and F for floor) followed by 3 numbers separated by commas. The numbers can't be above 255 because each component of RGB colors are encoded on 8 bits.

There can be spaces between the identifier and the texture path/color, but tabs are not processed as you can't know in advance the size of a tab, as it depends on the text editor/OS/system files used. 

The map formatting varies depending on if you want to launch the map with the mandatory or bonus executable:

- For mandatory:
	- 1 is a wall, 0 is a empty space, the player is defined with a letter depending in it's orientation (N for north, S for south...).
	- The map needs to be closed, but it can be splitted in islands as long as there is no "0"s adjacent to void.
	- Other characters in the map are not accepted.
Tabs are forbidden in the map for the same reason as specified above.

- For bonus:
	All the mandatory map specifications are still relevant.
	There is additional characters to specify map placement for the following:
	- Standard doors are represented by the character "D".
	- Colored doors are representated by the characters "R, G, B, Y" depending on their colors ( R for red, B for blue...) and the corresponding keys are represented by the corresponding letters in lowercase.
	- Collectibles are represented with the letter "c" in lowercase.
	- Enemies are represented with the letter "k" in lowercase.
	- Items are represented with the letter "m" in lowercase.
