using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.Diagnostics;

namespace 마영준_Thread를이용한자유낙하
{
    public partial class form1 : Form
    {
        // 점수 count
        int count = 0;

        Random rand = new Random();

        private Point black_p, red_p, yellow_p, blue_p;
        private int height, width;

        string sentence = "현재상태 : 점수 ";

        static object lockObject = new object();
        public form1()
        {
            InitializeComponent();
            black_p.X = 50;
            black_p.Y = 300;
            height = Height;
            width = Width;

            Thread red_t = new Thread(Red_p);
            Thread yellow_t = new Thread(Yellow_p);
            Thread blue_t = new Thread(Blue_p);
            Thread paint_form = new Thread(Paint_form);
            red_t.IsBackground = true;
            yellow_t.IsBackground = true;
            blue_t.IsBackground = true;
            paint_form.IsBackground = true;

            red_t.Start();
            yellow_t.Start();
            blue_t.Start();
            paint_form.Start();
        }

        private void Paint_form()
        {
            while (true)
            {
                Invalidate();
                Thread.Sleep(10);
            }
        }
        private void checkCount()
        {
            if (count == 5)
            {
                MessageBox.Show("게임종료");
                
                Application.Exit();
            }
        }
        private void Red_p ()
        {
            while (true)
            {
                int speed = rand.Next(10, 15);
                red_p.X = rand.Next(0, width - 40);
                red_p.Y = 0;

                    while (red_p.Y + 20 < height)
                    {
                        lock (lockObject)
                        {
                            red_p.Y += speed;
                            Thread.Sleep(50);

                            if (isClose(black_p, red_p))
                            {
                                count++;
                                label1.Text = sentence + count;
                                checkCount();
                                break;
                            }
                        }  
                }
               
            }
        }
        private void Yellow_p()
        {
            while (true)
            {
                
                int speed = rand.Next(10, 15);
                yellow_p.X = rand.Next(0, width - 40);
                yellow_p.Y = 0;

                while (yellow_p.Y + 20 < height)
                {
                    lock (lockObject)
                    {
                        yellow_p.Y += speed;
                        Thread.Sleep(50);

                        if (isClose(black_p, yellow_p))
                        {
                            count++;
                            label1.Text = sentence + count;
                            checkCount();
                            break;
                        }
                    }
                }

            }
        }
        private void Blue_p()
        {
            while (true)
            {
                int speed = rand.Next(10, 15);
                blue_p.X = rand.Next(0, width - 40);
                blue_p.Y = 0;

                while (blue_p.Y + 20 < height)
                {
                    lock (lockObject)
                    {
                        blue_p.Y += speed;
                        Thread.Sleep(50);

                        if (isClose(black_p, blue_p))
                        {
                            count++;
                            label1.Text = sentence + count;
                            checkCount();
                            break;
                        }
                    }
                }

            }
        }

        bool isClose (Point a, Point b)
        {
            double length = Math.Pow((a.X - b.X),2) + Math.Pow((a.Y - b.Y), 2);
            if (length < 1600) return true;
            else return false;
        }



        private void form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.FillEllipse(Brushes.Black, black_p.X, black_p.Y, 40, 40);
            e.Graphics.FillEllipse(Brushes.Red, red_p.X, red_p.Y, 40, 40);
            e.Graphics.FillEllipse(Brushes.Yellow, yellow_p.X, yellow_p.Y, 40, 40);
            e.Graphics.FillEllipse(Brushes.Blue, blue_p.X, blue_p.Y, 40, 40);
        }

        private void form1_KeyDown(object sender, KeyEventArgs e)
        {
            Graphics g = CreateGraphics();

            // 방향키 왼쪽
            if (e.KeyCode == Keys.Left)
            {
                black_p.X -= 10;
            }


            // 방향키 오른쪽
            if (e.KeyCode == Keys.Right)
            {
                black_p.X += 10;
            }

        }
        
    }
}
