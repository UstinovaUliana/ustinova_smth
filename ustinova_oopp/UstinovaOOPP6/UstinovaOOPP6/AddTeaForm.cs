using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UstinovaOOPP6
{
    public partial class AddTeaForm : Form
    {
        bool isnew;
        int id;
        public bool flag_edit = false;
        public AddTeaForm(bool addnew, int idit_id)
        {
            InitializeComponent();
            isnew = addnew;
            id = idit_id;
            if (isnew) checkBoxIsFav.Checked = true;
            if (!isnew)
            {
                checkBoxIsFav.Hide();
                ShowInfo(idit_id);
            }
        }

        private void checkBoxIsFav_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBoxIsFav.Checked)
            {
                label1PerRate.Visible = true;
                textBoxPerRate1.Visible = true;
            }
            else
            {
                label1PerRate.Visible = false;
                textBoxPerRate1.Visible = false;
            }
        }

        private void Add_form_Load(object sender, EventArgs e)
        {
            if (!isnew)
            {
                
                ShowInfo(id);
            }
        }

        public void ShowInfo(int idit_id)
        {
            if (UstinovaTeaCollection.teaList[idit_id].GetType() == typeof(UstinovaTea))
            {
                UstinovaTea p;
                p = UstinovaTeaCollection.teaList[idit_id] as UstinovaTea;
                textBoxName1.Text = p.name;
                textBoxSort1.Text = p.sort;
                textBoxPrice1.Text = Convert.ToString(p.price);
                textBoxRate1.Text = Convert.ToString(p.rate);
            }
            else
            {
                UstinovaFavouriteTea n;
                n = UstinovaTeaCollection.teaList[idit_id] as UstinovaFavouriteTea;
                textBoxName1.Text = n.name;
                textBoxSort1.Text = n.sort;
                textBoxPrice1.Text = Convert.ToString(n.price);
                textBoxRate1.Text = Convert.ToString(n.rate);
                textBoxPerRate1.Text = Convert.ToString(n.personal_rate);
            }
        }

        //public void Show_element_notebook()
        //{
        //    l_manufmodel.Visible = true;
        //    b_manufmodel.Visible = true;
        //    l_price.Visible = true;
        //    b_price.Visible = true;
        //}

        //public void UNShow_element_notebook()
        //{
        //    l_manufmodel.Visible = false;
        //    b_manufmodel.Visible = false;
        //    l_price.Visible = false;
        //    b_price.Visible = false;
        //}

        private void saveNew(object sender, EventArgs e)
        {
            //if (b_id.Text == "")
            //    b_id.Text = "0";
            //if (b_volume.Text == "")
            //    b_volume.Text = "0";
            //if (b_mass.Text == "")
            //    b_mass.Text = "0";
            //if (b_manufmodel.Text == "")
            //    b_manufmodel.Text = "null";
            //if (b_price.Text == "")
            //    b_price.Text = "0";
            if (checkBoxIsFav.Checked)
            {
                UstinovaFavouriteTea n = new UstinovaFavouriteTea();
                n.name = textBoxName1.Text;
                n.sort = textBoxSort1.Text;
                n.price = Convert.ToInt32(textBoxPrice1.Text);
                n.rate = Convert.ToInt32(textBoxRate1.Text);
                n.personal_rate = Convert.ToInt32(textBoxPerRate1.Text);
                UstinovaTeaCollection.AddTea(n);
            }
            else
            {
                UstinovaTea p = new UstinovaTea();
                p.name = textBoxName1.Text;
                p.sort = textBoxSort1.Text;
                p.price = Convert.ToInt32(textBoxPrice1.Text);
                p.rate = Convert.ToInt32(textBoxRate1.Text);
                UstinovaTeaCollection.AddTea(p);
            }

            Form1 form = new Form1();
            //form.Refresh_list();
            Close();
        }

        //private void but_no_Click(object sender, EventArgs e)
        //{
        //    Close();
        //}

        private void saveChanged(object sender, EventArgs e)
        {
            //if (b_id.Text == "")
            //    b_id.Text = "0";
            //if (b_volume.Text == "")
            //    b_volume.Text = "0";
            //if (b_mass.Text == "")
            //    b_mass.Text = "0";
            //if (b_manufmodel.Text == "")
            //    b_manufmodel.Text = "null";
            //if (b_price.Text == "")
            //    b_price.Text = "0";
            if (checkBoxIsFav.Checked)
            {
                UstinovaFavouriteTea n;
                n = UstinovaTeaCollection.teaList[id] as UstinovaFavouriteTea;
                n.name = textBoxName1.Text;
                n.sort = textBoxSort1.Text;
                n.price = Convert.ToInt32(textBoxPrice1.Text);
                n.rate = Convert.ToInt32(textBoxRate1.Text);
                n.personal_rate = Convert.ToInt32(textBoxPerRate1.Text);
            }
            else
            {
                UstinovaTea p;
                p = UstinovaTeaCollection.teaList[id] as UstinovaTea;
                p.name = textBoxName1.Text;
                p.sort = textBoxSort1.Text;
                p.price = Convert.ToInt32(textBoxPrice1.Text);
                p.rate = Convert.ToInt32(textBoxRate1.Text);
            }

            Close();
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            if (isnew) saveNew(sender, e);
            else saveChanged(sender, e);

        }
    }
}
