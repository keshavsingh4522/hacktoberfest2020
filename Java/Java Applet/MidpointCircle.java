import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class MidpointCircle extends Applet{
    int X,Y, scale = 7;
    int convertX(int x) {
        return X + x * scale;
    }
    int convertY(int y) {
        return X- y * scale;
    }

    public void init() {
        setSize(900, 900);
        setBackground(new Color(255,255,255));
        addMouseWheelListener(new MouseWheelListener() {
            @Override
            public void mouseWheelMoved(MouseWheelEvent event) {
                scale += event.getWheelRotation();
                repaint();
            }
        });
    }

    public void midpointCircle(Graphics g, int xc, int yc, int r){
        int x=0;
        int y=r;
        int p = 1-r;
        
        while(x<=y){
            g.fillRect((int) (X+ (xc*scale) + ((int) x) * scale) - scale / 2, (int) (Y+ (yc*scale) - ((int) y) * scale) - scale / 2, scale, scale);
            g.fillRect((int) (X+ (xc*scale) - ((int) x) * scale) - scale / 2, (int) (Y+ (yc*scale) - ((int) y) * scale) - scale / 2, scale, scale);
            g.fillRect((int) (X+ (xc*scale) + ((int) x) * scale) - scale / 2, (int) (Y+ (yc*scale) + ((int) y) * scale) - scale / 2, scale, scale);
            g.fillRect((int) (X+ (xc*scale) - ((int) x) * scale) - scale / 2, (int) (Y+ (yc*scale) + ((int) y) * scale) - scale / 2, scale, scale);
            x+=1;
            if(p>0){
                y-=1;
                p+=(2*x-2*y-1);
            }
            else if(p<=0){
                p+=(2*x+1);
            }
        }
        

        x=r;
        y=0;
        p=1-r;
        while(x>y){
            g.fillRect((int) (X+ (xc*scale) + ((int) x) * scale) - scale / 2, (int) (Y + (yc*scale) - ((int) y) * scale) - scale / 2, scale, scale);
            g.fillRect((int) (X+ (xc*scale) - ((int) x) * scale) - scale / 2, (int) (Y + (yc*scale) - ((int) y) * scale) - scale / 2, scale, scale);
            g.fillRect((int) (X+ (xc*scale) + ((int) x) * scale) - scale / 2, (int) (Y + (yc*scale) + ((int) y) * scale) - scale / 2, scale, scale);
            g.fillRect((int) (X+ (xc*scale) - ((int) x) * scale) - scale / 2, (int) (Y + (yc*scale) + ((int) y) * scale) - scale / 2, scale, scale);
            y+=1;
            if(p<=0)
                p+=(2*y+1);
            else{
                x-=1;
                p+=(2*y-2*x+1);
            }
        }
    }

    public void paint(Graphics g){
        X = getWidth() / 2;
        Y = getHeight() / 2;

        g.setColor(Color.green);

        for (int x = scale; x <= getWidth(); x += scale) {
            g.drawLine(X + x, 0, X + x, getHeight());
            g.drawLine(X - x, 0, X - x, getHeight());
        }
        for (int y = scale; y <= getWidth(); y += scale) {
            g.drawLine(0, Y + y, getWidth(), Y + y);
            g.drawLine(0, Y- y, getWidth(), Y- y);
        }

        g.setColor(Color.red);
        g.drawLine(X, 0, X, getHeight());
        g.drawLine(0, Y, getWidth(), Y);

        g.setColor(Color.blue);
        midpointCircle(g, -22, -22, 10);

        g.setColor(Color.blue);
        midpointCircle(g, 22, -22, 10);

        g.setColor(Color.red);
        midpointCircle(g, 0, 0, 20);

        g.setColor(Color.black);
        midpointCircle(g, 0, 0, 3);

        g.setColor(Color.black);
        midpointCircle(g, -10, -10, 2);

        g.setColor(Color.black);
        midpointCircle(g, 10, -10, 2);
    }
}

/* 
<applet code="MidpointCircle" width="900" height="900"> </applet> 
*/