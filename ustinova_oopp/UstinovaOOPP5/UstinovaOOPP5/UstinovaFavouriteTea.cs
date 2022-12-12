using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UstinovaOOPP5
{
    [Serializable]
    class UstinovaFavouriteTea:UstinovaTea
    {
        private int personal_rate;

        public override void cread()
        {
            base.cread();
            Console.Write("Введите вашу оценку: ");
            personal_rate = int.Parse(Console.ReadLine());
        }

        public override void cwrite()
        {
            Console.WriteLine("Любимый");
            base.cwrite();
            Console.WriteLine("Ваша оценка: " + personal_rate);
        }
    }
}
