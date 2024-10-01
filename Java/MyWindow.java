package pratice;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.swing.*;

public class MyWindow extends JFrame
{
	
public static void main(String[] args) {
		
		System.out.println("Testing......");
		MyWindow w=new MyWindow();
	}
	private JLabel heading;
	
	private JLabel clockLabel;
	
	private Font font=new Font("Times New Roman",Font.BOLD,35);
	
	MyWindow()
	{
		super.setTitle("My Clock");
		super.setSize(400,400);
		super.setLocation(300,50);
		this.creatGUI();
		this.startClock();
		super.setVisible(true);
	}
	
	public void creatGUI() 
	{
		heading=new JLabel("My Clock");
		clockLabel=new JLabel("Clock");
		heading.setFont(font);
		clockLabel.setFont(font);
		
		this.setLayout(new GridLayout(2,1));
		this.add(heading);
		this.add(clockLabel);
	}
	public void startClock() 
	{
		Timer timer=new Timer(1000,new ActionListener() 
		{
			@Override
			public void actionPerformed(ActionEvent e) {
//				String dateTime=new Date().toString();
//				String dateTime=new Date().toLocaleString();
				Date d=new Date();
				SimpleDateFormat sfd=new SimpleDateFormat("d/M/y hh:mm:ss a");
				String dateTime=sfd.format(d);
				
				clockLabel.setText(dateTime);
			}
		});
		timer.start();
		
	}
	
}
