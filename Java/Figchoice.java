import java.applet.*;
import java.awt.*;
import java.awt.Graphics;
import java.awt.event.*;
public class figchoice extends Applet implements ItemListener {
Choice ch;
int x1[]= {50,120,220,20};
int y1[]= {50,120,20,20};
int n=4;
int Selection; 
public void init()
{
ch = new Choice();
ch.addItem("Select a Shape");
ch.addItem("Rectangle");
ch.addItem("Triangle");
ch.addItem("Square");
ch.addItem("Circle");
add(ch);
ch.addItemListener(this);
}
public void itemStateChanged (ItemEvent e)
{
Selection = ch.getSelectedIndex();
repaint();
}
public void paint(Graphics g)
{
super.paint(g);
if (Selection == 1)
{ g.drawRect(50,50,100,150); }
if (Selection == 2)
{ g.drawPolygon(x1,y1,n); }
if (Selection == 3)
{ g.drawRect(50,50,100,100); }
if (Selection == 4)
{
g.drawOval(70,30,100,100);
} } }
<html><head>
</head>
<body>
<div align="center">
<applet code="figchoice.class"width="800"height="500">
</applet>
</div>
</body>
</html>
