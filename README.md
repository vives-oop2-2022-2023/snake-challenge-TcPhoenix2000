# Sliding Slug - Snake Challenge - C++
## About The Project
This project was made as an assignment or challenge.
The goal of this project was to see how to create a snake-like game in the terminal or (some where else).

## How to install it
using linux
```
make
```
## How to run it
```
./bin/program
```
## Example usage
#TODO 

## Screenshots
#TODO

## How to set up the dev environment
#TODO 

## UML Diagrams
---
### Game Objects
- The `collisionDetection` is a class that provides methods for detecting collisions between objects.
```c
+--------------------+
| collisionDetection |
+--------------------+
| - static bool detectCollision(GameObject object1, GameObject object2)
| - static bool detectCollision(Point point, GameObject object2)
+--------------------+
```
- The `Edible` class represents a game object that can be eaten by a snake, and it has a `growth_delta` value indicating the amount by which the snake will grow when it eats the object.
- The `Obstacle` class represents a game object that can block the movement of a snake.
- The `GameObject` class represents a basic game object that has a position in the game world, and it has a `point` value indicating its position.
```c
                    +-----------------+
                    |     Edible      |
                    +-----------------+
                    | - _point: Point
                    | - growth_delta: int
                    +-----------------+
                    | + Edible(Point point, int growth_delta)
                    | + growth(): int
                    +-----------------+
                            ^
                            |
                            |
+---------------------------+---------------------------+
|                                                       |
|                       GameObject                      |
|                                                       |
+---------------------------+---------------------------+
| + GameObject(Point point)                             |
| + point(): Point                                      |
| + point(Point point)                                  |
+---------------------------+---------------------------+
                            |
                            |
                            v
                    +-----------------+
                    |    Obstacle     |
                    +-----------------+
                    | + Obstacle(Point point)
                    +-----------------+
```
---
### Helpers
- the `BitmapGenerator` class is a utility class that provides methods for generating a bitmap image file from raw image data. It has methods for creating the file header and info header of the bitmap file, as well as a method for generating the file itself. The class also has several private constants that are used in the generation process.
```c
+-----------------+
| BitmapGenerator |
+-----------------+
| + generate(unsigned char* image, size_t height, size_t width, const char* imageFileName)
| + create_file_header(size_t height, size_t stride): std::vector<unsigned char>
| + create_info_header(size_t height, size_t width): std::vector<unsigned char>
+-----------------+
| - BYTES_PER_PIXEL: size_t
| - FILE_HEADER_SIZE: size_t
| - INFO_HEADER_SIZE: size_t
+-----------------+
```
---
### Libraries
- The `IndexOutOfBoundException` class represents an exception that is thrown when an index is accessed that is outside the valid range of indices for a container or data structure.
- The `NullPointerException` class represents an exception that is thrown when a null pointer is encountered in a program.
```c
                                +--------------------+
                                | std::runtime_error |
                                +--------------------+
                                | + runtime_error(std::string message)
                                +--------------------+
                                | - message: std::string
                                +--------------------+
                                |
                                |
                                |
+---------------------------+---------------------------+
|                                                       |
|                     IndexOutOfBoundException          |
|                                                       |
+---------------------------+---------------------------+
| + IndexOutOfBoundException(std::string message)       |
+---------------------------+---------------------------+
|
|
|
+---------------------------+---------------------------+
|                                                       |
|                     NullPointerException              |
|                                                       |
+---------------------------+---------------------------+
| + NullPointerException(std::string message)           |
+---------------------------+---------------------------+
```
- The `displayMenu` class represents a menu that is displayed to the user in a game, and it has a member variable of type `linkedList<std::string>` that holds the menu items.
- The `OptionsMenu` class represents an options menu in a game, and it has a member variable of type `linkedList<std::string>` that holds the options.
```c
                                        +-----------------+
                                        |       Game      |
                                        +-----------------+
                                        | + Game()        |
                                        +-----------------+
                                        |
                                        |
                                        |
+---------------------------+---------------------------+
|                                                       |
|                      displayMenu                      |
|                                                       |
+---------------------------+---------------------------+
| - game: VIVES::Game                                   |
| - menu: linkedList<std::string>                       |
| + displayMenu()                                       |
+---------------------------+---------------------------+
|
|
|
+---------------------------+---------------------------+
|                                                       |
|                     OptionsMenu                       |
|                                                       |
+---------------------------+---------------------------+
| - game: VIVES::Game                                   |
| - optionsMenu: linkedList<std::string>                |
| + OptionsMenu()                                       |
+---------------------------+---------------------------+
```
- The `linkedList` class template is a generic class that represents a singly linked list data structure, and it provides methods for adding and removing elements from the list, accessing elements in the list by index, and getting the length of the list. It also has a destructor that clears the list when an object of the class is destroyed.
```c
+-----------------+
|    linkedList   |
+-----------------+
| - head: Node<T>*
+-----------------+
| + linkedList()
| + push_front(T data)
| + push_back(T data)
| + getNode(size_t index): Node<T>*
| + get(size_t index): T
| + tail(): Node<T>*
| + length(): size_t
| + remove(size_t index): T
| + insert(size_t index, T data)
| + clear()
| + ~linkedList()
+-----------------+
```
- The `Node` class template represents a node in a singly linked list data structure, and it has member variables for storing the data for the node, a pointer to the next node in the list, and a selection status flag. It also has methods for accessing and modifying these member variables.
```c
+-----------------+
|       Node      |
+-----------------+
| - _next: Node<T>*
| - _data: T
| - _selected: bool
+-----------------+
| + Node(T data)
| + Next(): Node<T>*
| + Next(Node<T>* node)
| + data(T data)
| + data(): T
+-----------------+
```
- The `Terminal` class provides static methods for manipulating the terminal screen and cursor, setting the text and background colors, and detecting key presses on the keyboard. It also has a map of named colors and a key code map for handling key presses on Linux systems.
```c
+-------------------+
|      Terminal     |
+-------------------+
| - colors: map<string, string>
| - key_map: map<Key, vector<int>>
+-------------------+
| + clear(): void
| + flush(): void
| + hide_cursor(): void
| + show_cursor(): void
| + move_cursor(unsigned int, unsigned int): void
| + foreground_color(string, bool): void
| + reset_foreground_color(): void
| + background_color(string, bool): void
| + reset_background_color(): void
| + get_key_press(): Key
+-------------------+
```
---
### Renderers
<!--
- The `BitmapRenderer` class is a class that is used to generate a bitmap image file from data stored in a `Canvas` object. It has member variables that store the image data and the name of the output file, and it has a constructor and a `render` method to initialize and generate the image, respectively. It also has a destructor that deallocates memory used by the `buffer` array.
```c
+---------------------------+
|     BitmapRenderer        |
+---------------------------+
| - PIXEL_DEPTH: unsigned int
| - buffer: unsigned char*
| - filename: string
+---------------------------+
| + BitmapRenderer(size_t, size_t, string): void
| + render(Canvas*): void
| + ~BitmapRenderer(): void
+---------------------------+
```-->
- The `IRender` class is an interface that defines a `render` method which takes in a pointer to a `Canvas` object as an argument. This method must be implemented by any class that implements the `IRender` interface.
```c
+----------------------------+
|  IRender                   |
+----------------------------+
|  + render(Canvas*)         |
+----------------------------+
```
<!--
- The `SenseHatRenderer` class is an implementation of the `IRender` interface that is used to render a `Canvas` object onto the Sense Hat LED matrix display.
```c
+----------------------------+
|  SenseHatRenderer          |
+----------------------------+
|  + render(Canvas*)         |
+----------------------------+
|  IRender                   |
|  + render(Canvas*)         |
+----------------------------+
``` -->
- The `TextRenderer` class is an implementation of the `IRender` interface that is used to render a `Canvas` object as text in the console window.
```c
+----------------------------+
|  TextRenderer              |
+----------------------------+
|  + render(Canvas*)         |
+----------------------------+
|  IRender                   |
|  + render(Canvas*)         |
+----------------------------+
```
---
### Source code
- The `Canvas` class is responsible for storing and drawing pixel data on a two-dimensional grid with a specified width and height. It has methods for setting the active drawing color, drawing pixels, lines, and rectangles, and clearing the canvas. It also has methods for accessing the width and height of the canvas and the color of individual pixels.
```c
+---------------+
|  Canvas       |
+---------------+
| - _buffer: std::vector<std::vector<Color>>
| - penColor: Color
+---------------+
| + Canvas(width: size_t, height: size_t)
| + clear(): void
| + pen_color(color: Color): void
| + draw_pixel(point: Point): void
| + horizontal_line(origin: Point, length: unsigned int): void
| + vertical_line(origin: Point, length: unsigned int): void
| + rectangle(origin: Point, second: Point): void
| + pixel(point: Point): Color
| + width(): size_t
| + height(): size_t
+---------------+
```
- The `Color` class represents a color with red, green, and blue values and provides functions for accessing and modifying these values as well as functions for comparing colors and accessing predefined colors.
```c
+---------------+
| Color         |
+---------------+
| - red_: unsigned char
| - green_: unsigned char
| - blue_: unsigned char
+---------------+
| + red(): unsigned char
| + green(): unsigned char
| + blue(): unsigned char
| + red(unsigned char): void
| + green(unsigned char): void
| + blue(unsigned char): void
| + equals(Color): bool
| + Color()
| + Color(unsigned char,unsigned char,unsigned char)
+---------------+
| + BLACK: Color
| + WHITE: Color
| + RED: Color
| + GREEN: Color
| + BLUE: Color
+---------------+
```
- The `Direction` class is an enumeration that defines four possible values: `UP`, `DOWN`, `LEFT`, and `RIGHT`.
```c
+---------------+
| Direction     |
+---------------+
| + UP
| + DOWN
| + LEFT
| + RIGHT
+---------------+
```
- The `Game` class is a class that represents a game, including its state (e.g. whether it is currently being played or not) and behavior (e.g. how to update and draw the game's entities).
```c
+---------------+
| Game|
+---------------+
| - snake: Snake
| - canvas: Canvas
| - _render: IRender
| - _walls: vector<Obstacle>
| - edibles: vector<Edibles>
| - _isPlaying: bool
+---------------+
| + Game()
| + start(): void
| + stop(): void
| + StartupSign(): void
| + setRenderer(render: IRender): void
| + keyCheck(): void
| + walls(): void
| + update(): void
| + draw(): void
| + renderer(): void
| + createEdible(): void
+---------------+
```
- The `Point` struct is a simple data structure that represents a point in two-dimensional space, with `x` and `y` coordinates.
```c
+------------------+
| Point <<struct>> |
+------------------+
| - x: size_t   
| - y: size_t   
+------------------+
```
- The `Snake` class represents a snake in a game and has behavior for moving the snake, growing the snake, and updating the snake's position. It also has methods for accessing various parts of the snake, such as its body and head.
```c
+---------------+
| Snake         |
+---------------+
| - snake: vector<Point>
| - direction: Direction
| - isMoving: bool
| - START_LENGTH unsigned int
+---------------+
| + Snake()     
| + up(): void  
| + down(): void
| + left(): void
| + right(): void
| + start(): void
| + stop(): void 
| + grow(unsigned int delta): void
| + body(): vector<Point>
| + head(): Point
| + nextSnakeHeadPosition(): Point
| + update(): void
+---------------+
```
Later on we will need to add the following classes:

* SensehatRenderer #TODO
* BitmapRenderer #TODO
* ^ Renderer interface + 2 implementations

## License and author info
#TODO 