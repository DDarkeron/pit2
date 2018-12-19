using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    class member
    {
        public string name;
        public int score;

        public member(string name,int score)
        {
            this.name = name;
            this.score = score;
        }
        public string getMem()
        {
            return "Имя: "+name + " Баллы: " + score.ToString();
        }
    }
}
