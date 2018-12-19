using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;




namespace WindowsFormsApp1
{
    

    public partial class Form1 : Form
    {
        List<member> members = new List<member>();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            buttonStart.Visible = false;
            labelPrivetscvie.Visible = false;
            labelName.Visible = labelRefgstration.Visible = textBoxName.Visible = buttonName.Visible = button1.Visible=buttonShow.Visible = true;

        }
        //
        private void label1_Click(object sender, EventArgs e)
        {

        }
        //
        private void buttonName_Click(object sender, EventArgs e)
        {


            //из текстового считать имя, написать после имени случ двух знач число
            //построчно сохр имена в текст файл при каждом клике
            string name=null;
            if (textBoxName.Text != null)
            {
                name = textBoxName.Text;
            }
            else
            {
                MessageBox.Show("Ошибка. Введите имя!");
            }
            int score = new Random().Next(100);//рандомим баллы
            member mem = new member(name, score);
            members.Add(mem);
            sortMem();
            textBoxName.Text = "";
            string path = Application.StartupPath + @"\Участники.txt";
            using (System.IO.StreamWriter file =
               new System.IO.StreamWriter(path, true))
            {

                string membr = mem.getMem();
                file.WriteLine(membr);

                
            }
        }
        public void sortMem()
        {
            member temp = null;
            for (int i = 0; i < members.Count; i++)
            {
                for (int j = 0; j < members.Count - 1; j++)
                {
                    if (members[j].score < members[j + 1].score)
                    {
                        temp = members[j + 1];
                        members[j + 1] = members[j];
                        members[j] = temp;
                    }
                }
            }
        }
        public void importMem()
        {
            string path = Application.StartupPath + @"\Участники.txt";
            StreamReader objReader = new StreamReader(path);
            string sLine = "";
            

            while (sLine != null)
            {
                sLine = objReader.ReadLine();
                if (sLine != null)
                {
                    int name1 = sLine.IndexOf("Имя:");
                    int name2 = sLine.IndexOf("Баллы:");//первое вхождение подстроки баллы
                    if (name1 != -1 && name2 != -1)
                    {
                    string name = sLine.Substring(name1 + 5, name2-6);
                    int score = Convert.ToInt32(sLine.Substring(name2 + 7));//баллы
                    member mem = new member(name, score);
                    members.Add(mem);
                    }
                }
            }
            objReader.Close();

            
        }
    

        private void buttonShow_Click(object sender, EventArgs e)
        {
            sortMem();
            string mem = "";
            for (int i = 0; i < members.Count; i++)
            {
                mem += members[i].getMem()+"\n";
            }
            MessageBox.Show(mem, "Список участников", MessageBoxButtons.OK);
           


            buttonStart.Visible = true;
            labelPrivetscvie.Visible = true;
            labelName.Visible = labelRefgstration.Visible = textBoxName.Visible = buttonName.Visible = buttonShow.Visible =button1.Visible= false;
            members = new List<member>();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            importMem();
        }
    }
}
