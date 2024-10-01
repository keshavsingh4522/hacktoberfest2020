public Form1()  
       {  
  
           InitializeComponent();  
  
       }  
       float num1, ans;  
       int count; 
       
  private void button8_Click(object sender, EventArgs e)  
       {  
           textBox1.Text = textBox1.Text + 2;  
       }  
  
       private void button9_Click(object sender, EventArgs e)  
       {  
           textBox1.Text = textBox1.Text + 1;  
       }  
  
       private void button13_Click(object sender, EventArgs e)  
       {  
           textBox1.Text = textBox1.Text + 3;  
       }  
  
       private void button3_Click(object sender, EventArgs e)  
       {  
           textBox1.Text = textBox1.Text + 6;  
       }  
  
       private void button2_Click(object sender, EventArgs e)  
       {  
           textBox1.Text = textBox1.Text + 5;  
       }  
  
       private void button10_Click(object sender, EventArgs e)  
       {  
           textBox1.Text = textBox1.Text + 4;  
       }  
  
       private void button6_Click(object sender, EventArgs e)  
       {  
           textBox1.Text = textBox1.Text + 9;  
       }  
  
       private void button7_Click(object sender, EventArgs e)  
       {  
           textBox1.Text = textBox1.Text + 8;  
       }  
  
       private void button1_Click(object sender, EventArgs e)  
       {  
           textBox1.Text = textBox1.Text + 7;  
       }  
  
       private void button5_Click(object sender, EventArgs e)  
       {  
           textBox1.Text = textBox1.Text + 0;  
       }  
  
       private void button16_Click(object sender, EventArgs e)  
       {  
           textBox1.Text = textBox1.Text + 0 + 0;  
       }  
private void btnPlus_Click(object sender, EventArgs e)  
        {  
            num1 = float.Parse(textBox1.Text);  
            textBox1.Clear();  
            textBox1.Focus();  
            count = 2;  
             
        }  
private void btnminus_Click(object sender, EventArgs e)  
      {  
          if (textBox1.Text != "")  
          {  
              num1 = float.Parse(textBox1.Text);  
              textBox1.Clear();  
              textBox1.Focus();  
              count = 1;  
          }  
      }  
private void btnmultiply_Click(object sender, EventArgs e)  
        {  
            num1 = float.Parse(textBox1.Text);  
            textBox1.Clear();  
            textBox1.Focus();  
            count = 3;  
        }  
private void btndivide_Click(object sender, EventArgs e)  
       {  
           num1 = float.Parse(textBox1.Text);  
           textBox1.Clear();  
           textBox1.Focus();  
           count = 4;  
       }  
private void btnequal_Click(object sender, EventArgs e)  
        {  
            compute(count);  
        }  
        public void compute(int count)  
        {  
            switch (count)  
            {  
                case 1:  
                    ans = num1 - float.Parse(textBox1.Text);  
                    textBox1.Text = ans.ToString();  
                    break;  
                case 2:  
                    ans = num1 + float.Parse(textBox1.Text);  
                    textBox1.Text = ans.ToString();  
                    break;  
                case 3:  
                    ans = num1 * float.Parse(textBox1.Text);  
                    textBox1.Text = ans.ToString();  
                    break;  
                case 4:  
                    ans = num1 / float.Parse(textBox1.Text);  
                    textBox1.Text = ans.ToString();  
                    break;  
                default:  
                    break;  
            }  
        }  
private void btnC_Click(object sender, EventArgs e)  
       {  
           textBox1.Clear();  
           count = 0;   
       }  
private void button15_Click(object sender, EventArgs e)  
       {  
           int c = textBox1.TextLength;  
           int flag = 0;  
           string text = textBox1.Text;  
           for (int i = 0; i < c; i++)  
           {  
               if (text[i].ToString() == ".")  
               {  
                   flag = 1; break;  
               }  
               else  
               {  
                   flag = 0;  
               }  
           }  
           if (flag == 0)  
           {  
               textBox1.Text = textBox1.Text + ".";  
           }  
       } 
