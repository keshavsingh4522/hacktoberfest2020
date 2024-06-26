import turtle
s = turtle.Turtle()
s.speed(10)
screen = turtle.Screen()
screen.title("SnowMan :)")
screen.bgcolor("sky blue")

# circles


def circles(color, radius, x, y):
    s.penup()
    s.fillcolor(color)
    s.goto(x, y)
    s.pendown()
    s.begin_fill()
    s.circle(radius)
    s.end_fill()


circles("white", 50, 0, 40)
circles("white", 80, 0, -110)
circles("white", 110, 0, -280)

# eyes

circles("black", 8, -17, 100)
circles("black", 8,  17, 100)


def mouth(x, y, a, length):
    s.penup()
    s.fillcolor("#ff6004")
    s.goto(x, y)
    s.setheading(a)
    s.pendown()
    s.begin_fill()
    s.forward(length)
    s.setheading(a-100)
    s.forward(length+30)
    s.setheading(a+104)
    s.forward(length+31)
    s.end_fill()

# mouth


mouth(2, 70, 90, 20)

# buttons

circles("black", 6, 0, 30)
circles("black", 6, 0, 2)
circles("black", 6, 0, -30)

# hands


def hands(leng, ang, x, y):
    s.penup()
    s.goto(x, y)
    s.setheading(ang)
    s.pendown()
    s.forward(leng)
    s.setheading(ang + 20)
    s.forward(20)
    s.penup()
    s.back(20)
    s.pendown()
    s.setheading(ang - 20)
    s.forward(20)
    s.penup()


hands(80, 160, -80, -20)
hands(80, 20, 80, -20)


s.hideturtle()
turtle.mainloop()
