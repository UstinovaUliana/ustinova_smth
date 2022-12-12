using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UstinovaOOPP5
{
    [Serializable]
    class UstinovaTea
    {
        protected string name;
        protected string sort;
        protected int price;
        protected int rate;

        public virtual void cread()
        {
            Console.Write("Введите название чая: ");
            name = Console.ReadLine();
            Console.Write("Введите сорт чая: "); 
            sort = Console.ReadLine();
            Console.Write("Ввведите цену: ");
            price = int.Parse(Console.ReadLine());
            Console.Write("Введите пользовательскую оценку чая: ");
            rate = int.Parse(Console.ReadLine());
        }
        public virtual void cwrite()
        {
            Console.WriteLine("Название: " + name);
            Console.WriteLine("Сорт: " + sort);
            Console.WriteLine("Цена: " + price);
            Console.WriteLine("Пользовательская оценка: " + rate);
        }
    }
}
