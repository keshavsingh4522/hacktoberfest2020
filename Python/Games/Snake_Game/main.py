from turtle import Turtle, Screen
from scoreboard import Scoreboard
from food import Food
import time


class snake:
    def __init__(self):
        self.segments = []
        self.position = [(0, 0), (-20, 0), (-40, 0)]
        self.create()
        self.head = self.segments[0]
        self.head.color("Green")

    def create(self):
        for i in self.position:
            self.addsegment(i)

    def addsegment(self, i):
        new_seg = Turtle("square")
        new_seg.penup()
        new_seg.goto(i)
        self.segments.append(new_seg)

    def extend(self):
        self.addsegment(self.segments[-1].position())

    def reset_snake(self):
        for seg in self.segments:
            seg.goto(1000, 1000)
        self.segments.clear()
        self.create()
        self.head = self.segments[0]
        self.head.color("Green")

    def move(self):

        for seg in range(len(self.segments) - 1, 0, -1):
            self.segments[seg].goto(self.segments[seg - 1].xcor(), self.segments[seg - 1].ycor())
        self.segments[0].forward(20)

    def up(self):
        if self.head.heading() != 270:
            self.head.setheading(90)

    def down(self):
        if self.head.heading() != 90:
            self.head.setheading(270)

    def left(self):
        if self.head.heading() != 0:
            self.head.setheading(180)

    def right(self):
        if self.head.heading() != 180:
            self.head.setheading(0)


screen = Screen()
screen.setup(width=600, height=600)
screen.tracer(0)

snakes = snake()
food = Food()
scoreboard = Scoreboard()

screen.listen()
screen.onkey(snakes.up, "w")
screen.onkey(snakes.down, "s")
screen.onkey(snakes.left, "a")
screen.onkey(snakes.right, "d")

playing = True

while playing:
    screen.update()
    time.sleep(.1)
    snakes.move()

    if snakes.head.distance(food) < 15:
        food.refresh()
        snakes.extend()
        scoreboard.addscore()
    if snakes.head.xcor() > 280 or snakes.head.xcor() < -300 or snakes.head.ycor() > 280 or snakes.head.ycor() < -280:
        scoreboard.reset_game()
        snakes.reset_snake()

    for segs in snakes.segments[1:-1]:
        if snakes.head.distance(segs) < 10:
            scoreboard.reset_game()
            snakes.reset_snake()

screen.exitonclick()
