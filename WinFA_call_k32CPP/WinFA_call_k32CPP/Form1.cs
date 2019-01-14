using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
namespace WinFA_call_k32CPP
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Auto, BestFitMapping = false)]
        internal static extern bool CreateDirectory(String path, IntPtr lpSecurityAttributes);

        private void button1_Click(object sender, EventArgs e)
        {
            CreateDirectory("TestS", IntPtr.Zero);
        }
    }
}
