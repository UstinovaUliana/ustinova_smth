using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UstinovaOOPP5
{
    class Program
    {
        static void Main(string[] args)
        {
            UstinovaTeaCollection collection = new UstinovaTeaCollection();
            int com;
            while (true)
            {
                Console.WriteLine("1.Добавить чай в коллекцию.\n2.Вывести спасок чая в коллекции.\n3.Загрузить коллекцию из файла.\n4.Сохранить коллекцию в файл.");
                Console.WriteLine("5.Очистить коллекцию.\n0.Выход.\n________________________________");

                Console.WriteLine("Введите команду: ");
                com = Convert.ToInt32(Console.ReadLine());

                switch (com)
                {
                    case 1:
                        {
                            bool is_favourite;
                            Console.WriteLine("Добавить любимый чай? (1-да, 0-нет): ");
                            is_favourite = Convert.ToInt32(Console.ReadLine()) != 0;
                            collection.addTea(is_favourite);
                            break;
                        }
                    case 2:
                        {
                            collection.cwrite();
                            break;
                        }

                    case 3:
                        {
                            collection.fread();
                            break;
                        }
                    case 4:
                        {
                            collection.fwrite();
                            break;
                        }

                    case 5:
                        {
                            collection.clearTeaList();
                            Console.WriteLine("Коллекция очищена.");
                            break;

                        }
                    case 0:
                        {
                            collection.clearTeaList();
                            return;
                        }
                    default:
                        {
                            Console.WriteLine("Нет такой команды.");
                            break;
                        }

                }
                Console.WriteLine("________________________________");
            }

        }
    }
}
