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

color represents the set color to draw on the canvas
```
#################################
# Color
#################################
# - red: unsigned char
# - green: unsigned char
# - blue: unsigned char
#################################
# + Color()
# + Color(red: unsigned char, green: unsigned char, blue: unsigned char)
# + red(): unsigned char
# + green(): unsigned char
# + blue(): unsigned char
# + red(red: unsigned char)
# + green(green: unsigned char)
# + blue(blue: unsigned char)
#################################
```

point represents a point with x and y coordinates
```
#################################
# Point <<struct>>
#################################
# + x: unsigned int
# + y: unsigned int
#################################
```

direction represents the direction of the the snake's movement
```
#################################
# Direction <<enum>>
#################################
# + UP
# + DOWN
# + LEFT
# + RIGHT
#################################
```

canvas represents the drawing canvas
```
#################################
# Canvas
#################################
# - _buffer: std::Vector<std::vector<Color>>
# - penColor: Color
#################################
# + Canvas(with:size_t ,height :size_t)
# + clear()
# + pen_color(color: Color)       set the active drawing color
# + draw_pixel(point: Point)
# + horizontal_line(origin: Point, length: unsigned int)
# + vertical_line(origin: Point, length: unsigned int)
# + rectangle(origin: Point, second: Point)
#
# + pixel(point: Point) :color
# + width() size_t
# + height() size_t
#################################
```

snake represents the snake object
```
#################################
# Snake
#################################
# - snake: std::vector<Point>
# - direction: Direction
# - isMoving: bool
# - START_LENGTH: unsigned int = 3
#################################
# + Snake()       create snake of START_LENGTH
# + up()
# + down()
# + left()
# + right()
# + stop()
# + grow(delta: unsigned int)
# + body(): std::vector<Point>
# + head(): Point
# + update()
#################################
```

game represents the game instance
```
#################################
# Game
#################################
# - snake: Snake
# - canvas: Canvas
# - isPlaying: bool
# - walls: std::vector<Obstacle>
#################################
# + Game()
# - create_walls(void)
# - update()      update entities
# - draw()        draw entities on canvas
# - render()      output canvas to renderer (terminal)
#################################
```


obstacle
```
#################################
# Obstacle
#################################
# - point: Point
#################################
# + obstacle(point: Point)
#################################
```

text renderer
```
#################################
# TextRenderer()
#################################
# + render(canvas * Canvas)      
#################################
```

Later on we will need to add the following classes:

* food 'Apple' (editable)
* Renderer interface + 2 implementations

## License and author info
#TODO 