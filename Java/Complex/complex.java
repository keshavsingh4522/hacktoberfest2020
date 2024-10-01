@SuppressWarnings("all")
class complex
{
	double img,real;

	
	complex(double re, double im)
	{
		this.real=re;
		this.img=im;
	}
	
	double modulus()
	{
		return Math.sqrt((this.real*this.real)+(this.img*this.img));
	}
	
	double argument()
	{
		return (Math.atan(this.img/this.real)*(180.0/Math.PI));
	}
	
	
	complex add(complex y)
	{
		double rez=this.real + y.real;
		double imz=this.img + y.img;
		
		return new complex(rez,imz);
	}
	
	complex conjugate()
	{		
		return new complex(this.real,this.img*(-1));
	}
	
	
	boolean equalsTo(complex y)
	{
		if(this.real==y.real&&this.img==y.img)
		return true;
		
		return false;
	}
	
	
	double compare(complex y)
	{
		return this.modulus()-y.modulus();
	}
	
	complex operator_plus(complex y) 
	{
		double rez=this.real + y.real;
		double imz=this.img + y.img;
		
		return new complex(rez,imz);
	}
	
@Override
	public String toString()
	{
		if(this.img<0)
		return this.real+" - "+Math.abs(this.img)+"i";
		
		return this.real+" + "+this.img+"i";
	}
		

}




