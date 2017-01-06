import turtle
wn = turtle.Screen()
alex =  turtle.Turtle()
alex.speed(100)
alex.pen(fillcolor = "white", pensize = 10)
wn.bgcolor("blue")

#Sets the pen size and the position for the circle
alex.pensize(10)
alex.up()
alex.setposition(0,100)
alex.down()



# First Circle
alex.begin_fill()
for i in range (313):
    alex.forward(2)
    alex.left(1.15)
alex.end_fill()


# Second Circle
alex.pen(fillcolor = "white", pensize = 10)
alex.begin_fill()
for j in range (313):
    alex.forward(2)
    alex.right(1.15)
alex.end_fill()

# Reposition Third Circle
alex.up()
alex.setposition(-20,-100)
alex.down()

# Third Circle
alex.pen(fillcolor = "white", pensize = 10)
alex.begin_fill()
for i in range (313):
    alex.forward(2)
    alex.right(1.15)
alex.end_fill()

# Eyes
alex.fillcolor("black")
alex.up()
alex.shape("circle")
alex.setposition(-50,200)
alex.stamp()
alex.setposition(50,200)
alex.stamp()
alex.shape("arrow")
alex.down()

# Nose
alex.fillcolor("green")
alex.up()
alex.shape("circle")
alex.setposition(0,150)
#alex.width(500)
alex.stamp()
alex.down()

# Buttons
alex.fillcolor("red")
alex.up()
alex.setposition(0,20)
alex.stamp()
alex.setposition(0,-20)
alex.stamp()
alex.setposition(0,-60)
alex.stamp()
alex.down()





wn.mainloop()