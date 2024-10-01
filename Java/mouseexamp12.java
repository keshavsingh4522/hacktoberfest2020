import java.awt.*;
import java.awt.event.*;
public class mousexamp12 extends Frame implements MouseListener
{
mousexamp12()
{
addMouseListener(this);
setSize(400,400);
setLayout(null);
setVisible(true);
}
public void mouseClicked(MouseEvent e)
{
Graphics g=getGraphics();
g.setColor(Color.blue);
g.fillOval(e.getX(),e.getY(),30,30);
}
public void mouseEntered(MouseEvent e)
{}
public void mouseExited(MouseEvent e)
{}
public void mousePressed(MouseEvent e)
{}
public void mouseReleased(MouseEvent e){
}
public static void main(String args[])
{
new mousexamp12();
}}
