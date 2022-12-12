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

namespace UstinovaOOPP6
{
    public partial class Form1 : Form
    {
        UstinovaTeaCollection collection = new UstinovaTeaCollection();

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Add_From_File(StringBuilder path);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Print_To_File(StringBuilder path);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Clear();

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern int GetSize();

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern bool GetTypeP1(int index);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void GetTeaName(int index, StringBuilder str);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern int GetTeaSort(int index, StringBuilder str);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern int GetTeaPrice(int index);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern int GetTeaRate(int index);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern int GetTeaPersonalRate(int index);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void CreateTea();

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void CreateFavouriteTea();

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void SetTeaName(int index, StringBuilder str);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void SetTeaSort(int index, StringBuilder str);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void SetTeaPrice(int index, int newprice);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void SetTeaRate(int index, int newrate);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void SetTeaPersonalRate(int index, int newperrate);


        public Form1()
        {
            InitializeComponent();
            Refresh_list();
            if (UstinovaTeaCollection.teaList.Count == 0)
            {
                listBox1.SelectedIndex = -1;
            }
            else
            {
                listBox1.SelectedIndex = UstinovaTeaCollection.teaList.Count - 1;
            }
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            AddTeaForm add_f = new AddTeaForm(true, 0);
            add_f.Show();
        }

        //private void addProductToolStripMenuItem_Click(object sender, EventArgs e)
        //{
        //    Add_form add_f = new Add_form();
        //    add_f.Show();
        //    add_f.UNShow_element_notebook();
        //}

        //private void addNotebookToolStripMenuItem_Click(object sender, EventArgs e)
        //{
        //    Add_form add_f = new Add_form();
        //    add_f.Show();
        //    add_f.Show_element_notebook();
        //}

        public void Refresh_list()
        {
            listBox1.Items.Clear();

            if (UstinovaTeaCollection.teaList.Count == 0)
            {
                textBoxName.Visible = false;
                textBoxSort.Visible = false;
                textBoxPrice.Visible = false;
                textBoxRate.Visible = false;
                textBoxPerRate.Visible = false;
                labelName.Visible = false;
                labelSort.Visible = false;
                labelPrice.Visible = false;
                labelRate.Visible = false;
                labelPerRate.Visible = false;
                buttonChange.Enabled = false;
                buttonDelete.Enabled = false;
                button5.Enabled = false;
            }
            else
            {
                foreach (UstinovaTea tea in UstinovaTeaCollection.teaList)
                {
                    textBoxName.Visible = true;
                    textBoxSort.Visible = true;
                    textBoxPrice.Visible = true;
                    textBoxRate.Visible = true;
                    textBoxPerRate.Visible = true;
                    labelName.Visible = true;
                    labelSort.Visible = true;
                    labelPrice.Visible = true;
                    labelRate.Visible = true;
                    labelPerRate.Visible = true;
                    listBox1.Items.Add(tea.name);
                    buttonChange.Enabled = true;
                    buttonDelete.Enabled = true;
                    button5.Enabled = true;
                }
            }
        }

        public void Element_Product_Show()
        {
            textBoxName.Visible = true;
            textBoxSort.Visible = true;
            textBoxPrice.Visible = true;
            textBoxRate.Visible = true;
            labelName.Visible = true;
            labelSort.Visible = true;
            labelPrice.Visible = true;
            labelRate.Visible = true;
            labelPerRate.Visible = false;
            textBoxPerRate.Visible = false;
        }

        public void Element_Notebook_Show()
        {
            textBoxName.Visible = true;
            textBoxSort.Visible = true;
            textBoxPrice.Visible = true;
            textBoxRate.Visible = true;
            labelName.Visible = true;
            labelSort.Visible = true;
            labelPrice.Visible = true;
            labelRate.Visible = true;
            labelPerRate.Visible = true;
            textBoxPerRate.Visible = true;
        }

        private void Form1_Activated(object sender, EventArgs e)
        {
            Refresh_list();
            if (UstinovaTeaCollection.teaList.Count == 0)
            {
                listBox1.SelectedIndex = -1;
            }
            else
            {
                listBox1.SelectedIndex = UstinovaTeaCollection.teaList.Count - 1;
            }
        }

        private void listBox1_SelectedValueChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            //(UstinovaTeaCollection.teaList[i].GetType() == typeof(UstinovaTea)
            if (collection.GetTypeP(index))
            {
                UstinovaFavouriteTea n;
                n = collection.GetElement(index) as UstinovaFavouriteTea;
                Element_Notebook_Show();
                textBoxName.Text = n.name;
                textBoxSort.Text = n.sort; ;
                textBoxPrice.Text = Convert.ToString(n.price);
                textBoxRate.Text = Convert.ToString(n.rate);
                textBoxPerRate.Text = Convert.ToString(n.personal_rate);
            }
            else
            {
                UstinovaTea p;
                p = collection.GetElement(index) as UstinovaTea;
                Element_Product_Show();
                textBoxName.Text = p.name;
                textBoxSort.Text = p.sort; ;
                textBoxPrice.Text = Convert.ToString(p.price);
                textBoxRate.Text = Convert.ToString(p.rate);
            }
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;

            if (index >= 0)
            {
                collection.Delete(index);
                Refresh_list();

                if ((index < UstinovaTeaCollection.teaList.Count))
                    listBox1.SelectedIndex = index;
                else
                    listBox1.SelectedIndex = index - 1;
            }
        }

        public bool ch = false;

        private void buttonChange_Click(object sender, EventArgs e)
        {
            int idit_id = listBox1.SelectedIndex;
            AddTeaForm add_f = new AddTeaForm(false, idit_id);
            ch = true;
            add_f.flag_edit = true;
            
            add_f.Show();

            //if (b_price.Visible == true)
            //{
            //    add_f.Show_element_notebook();
            //}
            //else
            //{
            //    add_f.UNShow_element_notebook();
            //}
        }

        private void buttonOpenFile_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                var name_file = new StringBuilder(openFileDialog1.FileName);
                Add_From_File(name_file);
                int count = GetSize();

                for (int i = 0; i < count; i++)
                {
                    if (GetTeaPersonalRate(i)<0)
                    {
                        var str = new StringBuilder(256);
                        UstinovaTea p = new UstinovaTea();

                        var str1 = new StringBuilder(256);
                        //str.Append(p.name);
                        GetTeaName(i,str);
                        p.name = str.ToString();
                        //str.Append(p.sort);
                        GetTeaSort(i,str1);
                        p.sort = str1.ToString();
                        p.price = GetTeaPrice(i);
                        p.rate = GetTeaRate(i);
                        UstinovaTeaCollection.teaList.Add(p);
                    }
                    else
                    {
                        UstinovaFavouriteTea n = new UstinovaFavouriteTea();
                        var str = new StringBuilder(256);
                        var str1 = new StringBuilder(256);
                        //  str.Append(n.name);
                        GetTeaName(i, str);
                        // str.Append(n.sort);
                        n.name = str.ToString();
                        GetTeaSort(i, str1);
                        n.sort = str1.ToString();
                        n.price = GetTeaPrice(i);
                        n.rate = GetTeaRate(i);
                        n.personal_rate = GetTeaPersonalRate(i);
                        UstinovaTeaCollection.teaList.Add(n);
                    }
                }

                Refresh_list();
                listBox1.SelectedIndex = UstinovaTeaCollection.teaList.Count - 1;
            }
        }

        private void buttonSaveToFile_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                Clear();

                for (int i = 0; i < UstinovaTeaCollection.teaList.Count; i++)
                {
                    if (UstinovaTeaCollection.teaList[i].GetType() == typeof(UstinovaTea))
                    {
                        CreateTea();
                        UstinovaTea cur_element = UstinovaTeaCollection.teaList[i] as UstinovaTea;
                        var str = new StringBuilder();
                        var str1 = new StringBuilder();
                        str.Append(cur_element.name);
                        SetTeaName(i, str);
                        str1.Append(cur_element.sort);
                        SetTeaSort(i, str1);
                        SetTeaPrice(i, cur_element.price);
                        SetTeaRate(i, cur_element.rate);
                    }
                    else
                    {
                        CreateFavouriteTea();
                        UstinovaFavouriteTea cur_element = UstinovaTeaCollection.teaList[i] as UstinovaFavouriteTea;
                        var str = new StringBuilder();
                        var str1 = new StringBuilder();
                        str.Append(cur_element.name);
                        SetTeaName(i, str);
                        str1.Append(cur_element.sort);
                        SetTeaSort(i, str1);
                        SetTeaPrice(i, cur_element.price);
                        SetTeaRate(i, cur_element.rate);
                        SetTeaPersonalRate(i, cur_element.personal_rate);
                    }
                }

                var name_file = new StringBuilder(saveFileDialog1.FileName);
                Print_To_File(name_file);
                Clear();
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Refresh_list();
            if (UstinovaTeaCollection.teaList.Count == 0)
            {
                listBox1.SelectedIndex = -1;
            }
            else
            {
                listBox1.SelectedIndex = UstinovaTeaCollection.teaList.Count - 1;
            }

        }
    }
}
