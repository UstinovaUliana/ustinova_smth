using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

namespace UstinovaOOPP5
{
    [Serializable]
    class UstinovaTeaCollection
    {
        private List<UstinovaTea> teaList = new List<UstinovaTea>();
        public void addTea (bool is_favourite)
        {
            if (is_favourite)
            {
                UstinovaFavouriteTea favouriteTea = new UstinovaFavouriteTea();
                favouriteTea.cread();
                teaList.Add(favouriteTea);
            }
            else
            {
                UstinovaTea tea = new UstinovaTea();
                tea.cread();
                teaList.Add(tea);
            }
        }
        public void cwrite() {
            if (teaList.Count == 0)
                Console.WriteLine("Коллекция пуста.\n");
            else
            {
                foreach (UstinovaTea tea in teaList)
                {
                    Console.WriteLine("Чай");
                    tea.cwrite();
                    Console.WriteLine("\n");
                }
            }
        }
        public void clearTeaList()
        {
            teaList.Clear();
        }
        public void fwrite()
        {
            Console.WriteLine("Введите название файла: ");
            string wfileName = Console.ReadLine();
            BinaryFormatter archive= new BinaryFormatter();
            using (FileStream fout = new FileStream(wfileName, FileMode.OpenOrCreate))
            {
                archive.Serialize(fout, teaList);
            }
            Console.WriteLine("Сохранено!\n");
        }

        public void fread()
        {
            Console.WriteLine("Введите название файла: ");
            string rfileName = Console.ReadLine();
            BinaryFormatter archive = new BinaryFormatter();
            using (FileStream fin = new FileStream(rfileName, FileMode.Open))
            {
                teaList = archive.Deserialize(fin) as List<UstinovaTea>;
            }
            Console.WriteLine("Загружено!\n");
        }
    }
}
