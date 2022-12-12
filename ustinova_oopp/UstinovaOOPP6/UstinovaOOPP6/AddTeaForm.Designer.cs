
namespace UstinovaOOPP6
{
    partial class AddTeaForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.checkBoxIsFav = new System.Windows.Forms.CheckBox();
            this.textBoxRate1 = new System.Windows.Forms.TextBox();
            this.textBoxPrice1 = new System.Windows.Forms.TextBox();
            this.textBoxSort1 = new System.Windows.Forms.TextBox();
            this.textBoxName1 = new System.Windows.Forms.TextBox();
            this.label1Rate = new System.Windows.Forms.Label();
            this.label1Price = new System.Windows.Forms.Label();
            this.label1Sort = new System.Windows.Forms.Label();
            this.label1Name = new System.Windows.Forms.Label();
            this.textBoxPerRate1 = new System.Windows.Forms.TextBox();
            this.label1PerRate = new System.Windows.Forms.Label();
            this.buttonSave = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // checkBoxIsFav
            // 
            this.checkBoxIsFav.AutoSize = true;
            this.checkBoxIsFav.Location = new System.Drawing.Point(57, 105);
            this.checkBoxIsFav.Name = "checkBoxIsFav";
            this.checkBoxIsFav.Size = new System.Drawing.Size(121, 21);
            this.checkBoxIsFav.TabIndex = 0;
            this.checkBoxIsFav.Text = "Любимый чай";
            this.checkBoxIsFav.UseVisualStyleBackColor = true;
            this.checkBoxIsFav.CheckedChanged += new System.EventHandler(this.checkBoxIsFav_CheckedChanged);
            // 
            // textBoxRate1
            // 
            this.textBoxRate1.Location = new System.Drawing.Point(435, 159);
            this.textBoxRate1.Name = "textBoxRate1";
            this.textBoxRate1.Size = new System.Drawing.Size(76, 22);
            this.textBoxRate1.TabIndex = 16;
            // 
            // textBoxPrice1
            // 
            this.textBoxPrice1.Location = new System.Drawing.Point(435, 119);
            this.textBoxPrice1.Name = "textBoxPrice1";
            this.textBoxPrice1.Size = new System.Drawing.Size(76, 22);
            this.textBoxPrice1.TabIndex = 15;
            // 
            // textBoxSort1
            // 
            this.textBoxSort1.Location = new System.Drawing.Point(435, 80);
            this.textBoxSort1.Name = "textBoxSort1";
            this.textBoxSort1.Size = new System.Drawing.Size(100, 22);
            this.textBoxSort1.TabIndex = 14;
            // 
            // textBoxName1
            // 
            this.textBoxName1.Location = new System.Drawing.Point(435, 45);
            this.textBoxName1.Name = "textBoxName1";
            this.textBoxName1.Size = new System.Drawing.Size(151, 22);
            this.textBoxName1.TabIndex = 13;
            // 
            // label1Rate
            // 
            this.label1Rate.AutoSize = true;
            this.label1Rate.Location = new System.Drawing.Point(239, 162);
            this.label1Rate.Name = "label1Rate";
            this.label1Rate.Size = new System.Drawing.Size(186, 17);
            this.label1Rate.TabIndex = 12;
            this.label1Rate.Text = "Пользовательская оценка:";
            // 
            // label1Price
            // 
            this.label1Price.AutoSize = true;
            this.label1Price.Location = new System.Drawing.Point(373, 122);
            this.label1Price.Name = "label1Price";
            this.label1Price.Size = new System.Drawing.Size(47, 17);
            this.label1Price.TabIndex = 11;
            this.label1Price.Text = "Цена:";
            // 
            // label1Sort
            // 
            this.label1Sort.AutoSize = true;
            this.label1Sort.Location = new System.Drawing.Point(374, 83);
            this.label1Sort.Name = "label1Sort";
            this.label1Sort.Size = new System.Drawing.Size(44, 17);
            this.label1Sort.TabIndex = 10;
            this.label1Sort.Text = "Сорт:";
            // 
            // label1Name
            // 
            this.label1Name.AutoSize = true;
            this.label1Name.Location = new System.Drawing.Point(343, 47);
            this.label1Name.Name = "label1Name";
            this.label1Name.Size = new System.Drawing.Size(76, 17);
            this.label1Name.TabIndex = 9;
            this.label1Name.Text = "Название:";
            // 
            // textBoxPerRate1
            // 
            this.textBoxPerRate1.Location = new System.Drawing.Point(435, 197);
            this.textBoxPerRate1.Name = "textBoxPerRate1";
            this.textBoxPerRate1.Size = new System.Drawing.Size(76, 22);
            this.textBoxPerRate1.TabIndex = 18;
            // 
            // label1PerRate
            // 
            this.label1PerRate.AutoSize = true;
            this.label1PerRate.Location = new System.Drawing.Point(324, 200);
            this.label1PerRate.Name = "label1PerRate";
            this.label1PerRate.Size = new System.Drawing.Size(99, 17);
            this.label1PerRate.TabIndex = 17;
            this.label1PerRate.Text = "Ваша оценка:";
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(294, 288);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(109, 23);
            this.buttonSave.TabIndex = 19;
            this.buttonSave.Text = "Сохранить";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // AddTeaForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(this.textBoxPerRate1);
            this.Controls.Add(this.label1PerRate);
            this.Controls.Add(this.textBoxRate1);
            this.Controls.Add(this.textBoxPrice1);
            this.Controls.Add(this.textBoxSort1);
            this.Controls.Add(this.textBoxName1);
            this.Controls.Add(this.label1Rate);
            this.Controls.Add(this.label1Price);
            this.Controls.Add(this.label1Sort);
            this.Controls.Add(this.label1Name);
            this.Controls.Add(this.checkBoxIsFav);
            this.Name = "AddTeaForm";
            this.Text = "AddTeaForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox checkBoxIsFav;
        private System.Windows.Forms.TextBox textBoxRate1;
        private System.Windows.Forms.TextBox textBoxPrice1;
        private System.Windows.Forms.TextBox textBoxSort1;
        private System.Windows.Forms.TextBox textBoxName1;
        private System.Windows.Forms.Label label1Rate;
        private System.Windows.Forms.Label label1Price;
        private System.Windows.Forms.Label label1Sort;
        private System.Windows.Forms.Label label1Name;
        private System.Windows.Forms.TextBox textBoxPerRate1;
        private System.Windows.Forms.Label label1PerRate;
        private System.Windows.Forms.Button buttonSave;
    }
}