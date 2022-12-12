using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Collections;

namespace UstinovaOOPP6
{
    [Serializable]
    class UstinovaTeaCollection
    {
        public static ArrayList teaList = new ArrayList();
        //public void addTea(bool is_favourite)
        //{
        //    if (is_favourite)
        //    {
        //        UstinovaFavouriteTea favouriteTea = new UstinovaFavouriteTea();
        //        favouriteTea.cread();
        //        teaList.Add(favouriteTea);
        //    }
        //    else
        //    {
        //        UstinovaTea tea = new UstinovaTea();
        //        tea.cread();
        //        teaList.Add(tea);
        //    }
        //}
        public static void AddTea(UstinovaTea p)
        {
            teaList.Add(p);
        }
        public UstinovaTea GetElement(int cur_index)
        {
            UstinovaTea cur;
            if (teaList[cur_index].GetType() == typeof(UstinovaTea))
            {
                cur = new UstinovaTea();
                cur = (UstinovaTea)teaList[cur_index];
            }
            else
            {
                cur = new UstinovaFavouriteTea();
                cur = (UstinovaFavouriteTea)teaList[cur_index];
            }

            return cur;
        }
        public bool GetTypeP(int cur_index)
        {
            if (teaList[cur_index].GetType() == typeof(UstinovaTea))
            {
                return false;
            }
            else
                return true;
        }
        public void Delete(int index)
        {
            teaList.RemoveAt(index);
        }

    }
}
