from turtle import Turtle, Screen
import pandas

turtle = Turtle()
screen = Screen()

image = "blank_image_india.gif"
screen.addshape(image)
turtle.shape(image)

data = pandas.read_csv("state_list.csv")
states_list = data.state.to_list()
guessed_state = []

while len(guessed_state) < 50:
    answer_state = screen.textinput(title=f"{len(guessed_state)}/29 States Correct",
                                    prompt="Guess the state of India :").title()

    if answer_state in states_list:
        guessed_state.append(answer_state)
        t = Turtle()
        t.hideturtle()
        t.penup()
        state_data = data[data.state == answer_state]
        t.goto(int(state_data.x), int(state_data.y))
        t.write(answer_state)

if len(guessed_state) == 50:
    turtle.write("You Got It!")

