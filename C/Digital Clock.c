using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace DigitalClock_1._0 {
    public partial class Form1: Form {
        bool formatAm_PM;
        public Form1() {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e) {
            timer1.Start();
        }
        private void timer1_Tick(object sender, EventArgs e) {
            if (formatAm_PM == true) {
                lbl24Time.Text = DateTime.Now.ToString("hh:mm");
            } else {
                lbl24Time.Text = DateTime.Now.ToString("HH:mm");
            }
            lblsec.Text = DateTime.Now.ToString("ss");
            lblMonth.Text = DateTime.Now.ToString("MMM dd yyyy");
            lblDay.Text = DateTime.Now.ToString("dddd");
        }
        private void btnClose_Click(object sender, EventArgs e) {
            this.Close();
        }
        private void btnChangeformat_Click(object sender, EventArgs e) {
            if (btnChangeformat.Text == "12H") {
                formatAm_PM = true;
                btnChangeformat.Text = "24H";
            } else {
                formatAm_PM = false;
                btnChangeformat.Text = "12H";
            }
        }
    }
}
