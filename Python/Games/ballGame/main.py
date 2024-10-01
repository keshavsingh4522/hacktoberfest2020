import pygame as pg
from random import randint, choice

gameTitle='PUBG 2.0'
gt=gameTitle

pg.init()

#display settings
dw=600
dh=500

#colours
gold=(220,226,32)
black=(0,0,0)
white=(255,255,255)
transparent=(0,0,0,0) 
blue = (71,224,255)
red = (255,71,150)
tred = (255,71,150,50)
green = (116,225,191)
lgreen = (200,239,231)
dgreen = (48, 126,109)
pink = (230,146,105)
 
#lives bar
lbpos = (10,10)
lbsize = (160,16)

#speed
speed=3

#ball
ballSize=7
bs=ballSize

# board
bh = 10
bw = 100
# start screen
ssPos = (int(dw/2),int(dh/2)-60)
smSize = 90
omSize = 30
hintSize = 16
om1Pos = (int(dw/2)-80,int(dh/2)+20)
om2Pos = (int(dw/2)+60,int(dh/2)+20)
om3Pos = (int(dw/2),int(dh/2)-60)
hintPos = (int(dw/2),int(dh/2)+150)

#thank screen
timg = pg.image.load('ThankScreen.png')
timg = pg.transform.scale(timg,(dw,dh))

# retry box
rbx = int(dw/2)-80
rby = int(dh/2)+30
rbSize = (162,65)
rtSize = 60
# tob box
red_image = pg.Surface((int(dw),int(bs+25)))
red_image.set_colorkey(black)


#   audio
pg.mixer.music.load('backMusic.mp3')
pg.mixer.music.set_volume(0.3)
pg.mixer.music.play(-1)


livelMusic = pg.mixer.Sound('lifelSound.wav')

clickMusic = pg.mixer.Sound('clickSound.wav')

hoverMusic = pg.mixer.Sound('hoverSound.ogg')

gameDisplay = pg.display.set_mode((dw,dh))

# setting window name
pg.display.set_caption(gt)



bd=[1,1]
dp=(160,390)

lives=7
score=0
Emode = -1
Imode = 0

cmode = 1     #one for easy mode and zero for impossible mode

clevel = 0
levelInc = .0007
socreInc = .003

#list of ball instances
ballList=[]


played = False

start = False
gameO=False
crashed = False
clock = pg.time.Clock()

class Ball:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.movex = 0
        self.movey = 0
        self.img = pg.Surface([10,10])
        self.img.fill(black)
        self.rect = self.img.get_rect()
    def show(self):
        pg.draw.circle(gameDisplay,blue, [int(ball.x), int(ball.y)],bs)
class Board:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.move=5
        self.img = pg.Surface([bw,bh])
        self.img.fill(green)
        self.rect = self.img.get_rect()
    def show(self):
        gameDisplay.blit(self.img, (self.x,self.y))
    def col(self,ball):
        if ball.y >= dh-bs-bh:
            if self.x <= ball.x:
                if ball.x - self.x <= bw:
                    return 1
                else:
                    return 0
            else:
                return 0
        else:
            return 0

        
board = Board()
board.x = int(dw/2)-int(bw/2)
board.y = dh-bh
    
def ballspawn():
    ball = Ball()
    bd[0]=choice([-1,1])
    bd[1]=-1
    ball.x = randint(bs,dw)
    ball.y = randint(bs*2 +25,dh)
    ball.movex = bd[0]*speed
    ball.movey = bd[1]*speed
    return ball
#creating new ball object and saving them in list
ball = ballspawn()
ballList.append(ball)

# main game loop
while not crashed:
    for event in pg.event.get():
        if event.type == pg.QUIT:
            crashed = True
    gameDisplay.fill(white)
    
# start screen and elements
    if not start:
        font=pg.font.SysFont('calibri', smSize, bold = True)
        renderStart = font.render('Start',True,red,white)
        startBox = renderStart.get_rect()
        startBox.center = ssPos
        gameDisplay.blit(renderStart,startBox)


        font=pg.font.SysFont('calibri', omSize)
        renderom = font.render('Easy',True,green,white)
        omBox = renderom.get_rect()
        omBox.center = om1Pos
        gameDisplay.blit(renderom,omBox)
        pg.draw.rect(gameDisplay,green,((om1Pos[0]-45,om1Pos[1]-20),(90,40)),Emode)
        
        
        font=pg.font.SysFont('calibri', omSize)
        renderom = font.render('Impossible',True,green,white)
        omBox = renderom.get_rect()
        omBox.center = om2Pos
        gameDisplay.blit(renderom,omBox)
        pg.draw.rect(gameDisplay,green,((om2Pos[0]-80,om2Pos[1]-20),(160,40)),Imode)

        font=pg.font.SysFont('calibri', hintSize)
        renderHint = font.render('Click on blue tab to change between game modes',True,black,white)
        hintBox = renderHint.get_rect()
        hintBox.center = hintPos
        gameDisplay.blit(renderHint,hintBox)
        hintPos=(hintPos[0],hintPos[1]+20)

        renderHint = font.render('Use left and right arrow keys to move board in game and spacebar for boost',True,black,white)
        hintBox = renderHint.get_rect()
        hintBox.center = hintPos
        gameDisplay.blit(renderHint,hintBox)
        hintPos=(hintPos[0],hintPos[1]+20)

        renderHint = font.render('Click on start to start the game,press ESC/Delete key to exit anytime',True,black,white)
        hintBox = renderHint.get_rect()
        hintBox.center = hintPos
        gameDisplay.blit(renderHint,hintBox)
        hintPos=(hintPos[0],hintPos[1]-40)


        
# checking if game is over    
    if gameO:
        # thanking screen
        gameDisplay.blit(timg,(0,0))
        
        #final score showing
        font = pg.font.SysFont('calibri', 30)
        renderScore = font.render('{}{}{}'.format(' You scored: ',int(score),' '), True, blue, black)    
        scoreBox =renderScore.get_rect()
        scoreBox.center=(int(dw/2),int(dh/2)-10)
        gameDisplay.blit(renderScore,scoreBox)

        #retry box
        retryText=pg.font.SysFont('calibri', rtSize, bold = True)
        renderRetry = retryText.render('Retry',True,lgreen,red)
        retryBox = renderRetry.get_rect()
        retryBox.center = (int(dw/2),int(dh/2)+60)
        gameDisplay.blit(renderRetry,retryBox)
        pg.draw.rect(gameDisplay,green,((rbx,rby),rbSize),1)
# ittrating every object form ball list
    for ball in ballList:        
        if not gameO and start:
            ball.x += ball.movex # moving balls
            ball.y += ball.movey
            if ball.y < 2*bs + 25:
                ball.movey *= -1
                bd[1]*=-1
            if ball.x > dw - bs or ball.x < bs:
                ball.movex *= -1
                bd[0]*=-1
            if ball.y > dh:   #if ball touches base line
                if lives>1:
                    livelMusic.play() 
                    lives-=1
                    ballList.remove(ball)
                    if len(ballList)==0:
                        tball=ballspawn()
                        ballList.append(tball)
                    
                else:
                    lives=0
                    livelMusic.play()
                    gameO=True
            if board.col(ball):
                ball.movey *= -1
                bd[1]*=-1
            ball.show()
            
#levelChecher

    if score//50 > clevel and cmode:
        clevel+=1
        if clevel>3:
            for i in range(2-len(ballList)):
                ball = ballspawn()
                ballList.append(ball)
        ball = ballspawn()
        ballList.append(ball)
    if score//50 > clevel and not cmode:
        clevel+=1
        if clevel>=1:
            for i in range(clevel+1-len(ballList)):
                ball = ballspawn()
                ballList.append(ball)
    
    if not gameO and start:
        pg.draw.line(gameDisplay,black,(0,bs+25),(dw,bs+25),1)
        pg.draw.rect(gameDisplay,black,(lbpos,lbsize),1)
        if (int((lbsize[0]-6)*(lives/7))):
                   pg.draw.rect(gameDisplay,red,((lbpos[0]+3,lbpos[1]+3),(int((lbsize[0]-6)*(lives/7)),lbsize[1]-6)))
        
        font = pg.font.SysFont('calibri', 20)
        renderlvl = font.render('{}{}{}'.format('Lvl: ',int(clevel+1),'  '), True,red,white)    
        lvlBox =renderlvl.get_rect()
        lvlBox.center=(int(dw/2) + 30,20)
        gameDisplay.blit(renderlvl, lvlBox)

        
        font = pg.font.SysFont('calibri', 20)
        renderScore = font.render('{}{}{}'.format('Score: ',int(score),'  '), True,red,white)    
        scoreBox =renderScore.get_rect()
        scoreBox.topright=(dw,5)
        board.show()

        gameDisplay.blit(renderScore,scoreBox)

# speed booster

    if event.type == pg.KEYDOWN and not gameO and start:
        key=pg.key.name(event.key)
        if key == 'space':
            ball.movey *= 1.1
            ball.movex *= 1.1

#  board movement
        if key == 'left' and board.x>0:
            board.x -= board.move
        if key == 'right' and board.x<dw-80:
            board.x += board.move

    if event.type == pg.KEYUP:
        key=pg.key.name(event.key)
        if key == 'space':
            ball.movey = bd[1]*speed
            ball.movex = bd[0]*speed
        if key == 'delete' or key == 'escape':
            gameO=True
            lives = 0
            
            
# hovering and clicking on retry
    if gameO:
# checking if mouse is on retry button
        mpos = pg.mouse.get_pos()
        if mpos[0]>=rbx-10 and mpos[0]<=rbx+170:
            rbSize = (172,75)
            rbx = int(dw/2)-85
            rby = int(dh/2)+25
            rtSize = 63
            if not played:
                hoverMusic.play()
                played = True
            
            if event.type == pg.MOUSEBUTTONUP:
                clickMusic.play()
                start = False
                score = 0
                lives = 7
                clevel = 0
                ballList=[]
                ball = ballspawn()
                ballList.append(ball)
                gameO = False
        else:
            played = False
            rbSize = (162,65)
            rbx = int(dw/2)-80
            rby = int(dh/2)+30
            rtSize = 60
            
# checking if mouse is on start button
    if not start:
        mpos = pg.mouse.get_pos()
        if (mpos[0]>=ssPos[0]-150 and mpos[0]<=ssPos[0]+150) and (mpos[1]>=ssPos[1]-50 and mpos[1]<=ssPos[1]+50):
            smSize=110
            if not played:
                hoverMusic.play()
                played = True
            if event.type == pg.MOUSEBUTTONUP:
                clickMusic.play()
                start = True
                ballList=[]
                ball = ballspawn()
                ballList.append(ball)
                
        else:
            smSize=90
            played = False
# checking if mouse is on impossible button
        if cmode:
            levelInc = .0007
            scoreInc = .03
            board.move=5
            if (mpos[0]>=om2Pos[0]-80 and mpos[0]<=om2Pos[0]+80) and (mpos[1]>=om2Pos[1]-20 and mpos[1]<=om2Pos[1]+20) :
                Imode = -1
                if event.type == pg.MOUSEBUTTONUP:
                    clickMusic.play()
                    Imode = -1
                    Emode = 0
                    cmode = 0
            else:
                Imode = 0
        else:
            Imode = 0
# checking if mouse is on easy button
        if (not cmode):
            levelInc = .001
            scoreInc = .05
            board.move= 7
            if (mpos[0]>=om1Pos[0]-80 and mpos[0]<=om1Pos[0]+80) and (mpos[1]>=om1Pos[1]-20 and mpos[1]<=om1Pos[1]+20):
                Emode = -1
                if event.type == pg.MOUSEBUTTONUP:
                    clickMusic.play()
                    Imode = 0
                    Emode = -1
                    cmode = 1
            else:
                Emode = 0
            Imode = -1
            
        
           
# increasing lives and scores        
    if lives<6.9 and lives>0 and (not gameO):
        lives+=levelInc
    if lives>0 and start:
        score += scoreInc
    clock.tick(60)
    pg.display.update()


pg.quit()
