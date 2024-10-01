from turtle import Turtle


class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.score = 0
        self.highscore = 0
        self.hideturtle()
        self.penup()
        self.goto(0, 270)
        self.writescore()

    def reset_game(self):
        if self.score > self.highscore:
            self.highscore = self.score
            with open("Highscore.text", "w") as file:
                file.write(str(self.highscore))
        self.score = 0
        self.writescore()

    def writescore(self):
        self.clear()
        with open("Highscore.text", "r") as file:
            highscore = file.read()

        Turtle.write(self, f"Score: {self.score} High Score: {highscore}", False, "center",
                     ("Verdana", 15, "normal"))

    def addscore(self):
        self.score += 1
        self.writescore()
