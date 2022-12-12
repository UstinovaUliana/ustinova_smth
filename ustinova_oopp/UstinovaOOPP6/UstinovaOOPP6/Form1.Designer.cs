
namespace UstinovaOOPP6
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.labelName = new System.Windows.Forms.Label();
            this.labelSort = new System.Windows.Forms.Label();
            this.labelPrice = new System.Windows.Forms.Label();
            this.labelRate = new System.Windows.Forms.Label();
            this.textBoxName = new System.Windows.Forms.TextBox();
            this.textBoxSort = new System.Windows.Forms.TextBox();
            this.textBoxPrice = new System.Windows.Forms.TextBox();
            this.textBoxRate = new System.Windows.Forms.TextBox();
            this.buttonChange = new System.Windows.Forms.Button();
            this.buttonDelete = new System.Windows.Forms.Button();
            this.buttonAdd = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.textBoxPerRate = new System.Windows.Forms.TextBox();
            this.labelPerRate = new System.Windows.Forms.Label();
            this.buttonOpenFile = new System.Windows.Forms.Button();
            this.buttonSaveToFile = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 16;
            this.listBox1.Location = new System.Drawing.Point(12, 44);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(200, 388);
            this.listBox1.TabIndex = 0;
            this.listBox1.SelectedValueChanged += new System.EventHandler(this.listBox1_SelectedValueChanged);
            // 
            // labelName
            // 
            this.labelName.AutoSize = true;
            this.labelName.Location = new System.Drawing.Point(400, 91);
            this.labelName.Name = "labelName";
            this.labelName.Size = new System.Drawing.Size(76, 17);
            this.labelName.TabIndex = 1;
            this.labelName.Text = "Название:";
            // 
            // labelSort
            // 
            this.labelSort.AutoSize = true;
            this.labelSort.Location = new System.Drawing.Point(431, 127);
            this.labelSort.Name = "labelSort";
            this.labelSort.Size = new System.Drawing.Size(44, 17);
            this.labelSort.TabIndex = 2;
            this.labelSort.Text = "Сорт:";
            // 
            // labelPrice
            // 
            this.labelPrice.AutoSize = true;
            this.labelPrice.Location = new System.Drawing.Point(430, 166);
            this.labelPrice.Name = "labelPrice";
            this.labelPrice.Size = new System.Drawing.Size(47, 17);
            this.labelPrice.TabIndex = 3;
            this.labelPrice.Text = "Цена:";
            // 
            // labelRate
            // 
            this.labelRate.AutoSize = true;
            this.labelRate.Location = new System.Drawing.Point(296, 206);
            this.labelRate.Name = "labelRate";
            this.labelRate.Size = new System.Drawing.Size(186, 17);
            this.labelRate.TabIndex = 4;
            this.labelRate.Text = "Пользовательская оценка:";
            // 
            // textBoxName
            // 
            this.textBoxName.Cursor = System.Windows.Forms.Cursors.No;
            this.textBoxName.Location = new System.Drawing.Point(492, 89);
            this.textBoxName.Name = "textBoxName";
            this.textBoxName.ReadOnly = true;
            this.textBoxName.Size = new System.Drawing.Size(151, 22);
            this.textBoxName.TabIndex = 5;
            // 
            // textBoxSort
            // 
            this.textBoxSort.Cursor = System.Windows.Forms.Cursors.No;
            this.textBoxSort.Location = new System.Drawing.Point(492, 124);
            this.textBoxSort.Name = "textBoxSort";
            this.textBoxSort.ReadOnly = true;
            this.textBoxSort.Size = new System.Drawing.Size(100, 22);
            this.textBoxSort.TabIndex = 6;
            // 
            // textBoxPrice
            // 
            this.textBoxPrice.Cursor = System.Windows.Forms.Cursors.No;
            this.textBoxPrice.Location = new System.Drawing.Point(492, 163);
            this.textBoxPrice.Name = "textBoxPrice";
            this.textBoxPrice.ReadOnly = true;
            this.textBoxPrice.Size = new System.Drawing.Size(76, 22);
            this.textBoxPrice.TabIndex = 7;
            // 
            // textBoxRate
            // 
            this.textBoxRate.Cursor = System.Windows.Forms.Cursors.No;
            this.textBoxRate.Location = new System.Drawing.Point(492, 203);
            this.textBoxRate.Name = "textBoxRate";
            this.textBoxRate.ReadOnly = true;
            this.textBoxRate.Size = new System.Drawing.Size(76, 22);
            this.textBoxRate.TabIndex = 8;
            // 
            // buttonChange
            // 
            this.buttonChange.Location = new System.Drawing.Point(310, 326);
            this.buttonChange.Name = "buttonChange";
            this.buttonChange.Size = new System.Drawing.Size(94, 30);
            this.buttonChange.TabIndex = 9;
            this.buttonChange.Text = "Изменить";
            this.buttonChange.UseVisualStyleBackColor = true;
            this.buttonChange.Click += new System.EventHandler(this.buttonChange_Click);
            // 
            // buttonDelete
            // 
            this.buttonDelete.Location = new System.Drawing.Point(460, 326);
            this.buttonDelete.Name = "buttonDelete";
            this.buttonDelete.Size = new System.Drawing.Size(91, 30);
            this.buttonDelete.TabIndex = 10;
            this.buttonDelete.Text = "Удалить";
            this.buttonDelete.UseVisualStyleBackColor = true;
            this.buttonDelete.Click += new System.EventHandler(this.buttonDelete_Click);
            // 
            // buttonAdd
            // 
            this.buttonAdd.Location = new System.Drawing.Point(584, 326);
            this.buttonAdd.Name = "buttonAdd";
            this.buttonAdd.Size = new System.Drawing.Size(122, 30);
            this.buttonAdd.TabIndex = 11;
            this.buttonAdd.Text = "Добавить чай";
            this.buttonAdd.UseVisualStyleBackColor = true;
            this.buttonAdd.Click += new System.EventHandler(this.buttonAdd_Click);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(466, 396);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(75, 23);
            this.button5.TabIndex = 13;
            this.button5.Text = "ОК";
            this.button5.UseVisualStyleBackColor = true;
            // 
            // textBoxPerRate
            // 
            this.textBoxPerRate.Cursor = System.Windows.Forms.Cursors.No;
            this.textBoxPerRate.Location = new System.Drawing.Point(492, 241);
            this.textBoxPerRate.Name = "textBoxPerRate";
            this.textBoxPerRate.ReadOnly = true;
            this.textBoxPerRate.Size = new System.Drawing.Size(76, 22);
            this.textBoxPerRate.TabIndex = 15;
            // 
            // labelPerRate
            // 
            this.labelPerRate.AutoSize = true;
            this.labelPerRate.Location = new System.Drawing.Point(381, 244);
            this.labelPerRate.Name = "labelPerRate";
            this.labelPerRate.Size = new System.Drawing.Size(99, 17);
            this.labelPerRate.TabIndex = 14;
            this.labelPerRate.Text = "Ваша оценка:";
            // 
            // buttonOpenFile
            // 
            this.buttonOpenFile.Location = new System.Drawing.Point(345, 44);
            this.buttonOpenFile.Name = "buttonOpenFile";
            this.buttonOpenFile.Size = new System.Drawing.Size(132, 23);
            this.buttonOpenFile.TabIndex = 16;
            this.buttonOpenFile.Text = "Открыть файл";
            this.buttonOpenFile.UseVisualStyleBackColor = true;
            this.buttonOpenFile.Click += new System.EventHandler(this.buttonOpenFile_Click);
            // 
            // buttonSaveToFile
            // 
            this.buttonSaveToFile.Location = new System.Drawing.Point(558, 44);
            this.buttonSaveToFile.Name = "buttonSaveToFile";
            this.buttonSaveToFile.Size = new System.Drawing.Size(148, 23);
            this.buttonSaveToFile.TabIndex = 17;
            this.buttonSaveToFile.Text = "Сохранить в файл";
            this.buttonSaveToFile.UseVisualStyleBackColor = true;
            this.buttonSaveToFile.Click += new System.EventHandler(this.buttonSaveToFile_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonSaveToFile);
            this.Controls.Add(this.buttonOpenFile);
            this.Controls.Add(this.textBoxPerRate);
            this.Controls.Add(this.labelPerRate);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.buttonAdd);
            this.Controls.Add(this.buttonDelete);
            this.Controls.Add(this.buttonChange);
            this.Controls.Add(this.textBoxRate);
            this.Controls.Add(this.textBoxPrice);
            this.Controls.Add(this.textBoxSort);
            this.Controls.Add(this.textBoxName);
            this.Controls.Add(this.labelRate);
            this.Controls.Add(this.labelPrice);
            this.Controls.Add(this.labelSort);
            this.Controls.Add(this.labelName);
            this.Controls.Add(this.listBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Activated += new System.EventHandler(this.Form1_Activated);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Label labelName;
        private System.Windows.Forms.Label labelSort;
        private System.Windows.Forms.Label labelPrice;
        private System.Windows.Forms.Label labelRate;
        private System.Windows.Forms.TextBox textBoxName;
        private System.Windows.Forms.TextBox textBoxSort;
        private System.Windows.Forms.TextBox textBoxPrice;
        private System.Windows.Forms.TextBox textBoxRate;
        private System.Windows.Forms.Button buttonChange;
        private System.Windows.Forms.Button buttonDelete;
        private System.Windows.Forms.Button buttonAdd;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.TextBox textBoxPerRate;
        private System.Windows.Forms.Label labelPerRate;
        private System.Windows.Forms.Button buttonOpenFile;
        private System.Windows.Forms.Button buttonSaveToFile;
    }
}

