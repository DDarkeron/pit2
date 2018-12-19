namespace WindowsFormsApp1
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
            this.buttonStart = new System.Windows.Forms.Button();
            this.labelPrivetscvie = new System.Windows.Forms.Label();
            this.labelRefgstration = new System.Windows.Forms.Label();
            this.labelName = new System.Windows.Forms.Label();
            this.textBoxName = new System.Windows.Forms.TextBox();
            this.buttonName = new System.Windows.Forms.Button();
            this.buttonShow = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonStart
            // 
            this.buttonStart.Location = new System.Drawing.Point(98, 247);
            this.buttonStart.Name = "buttonStart";
            this.buttonStart.Size = new System.Drawing.Size(338, 142);
            this.buttonStart.TabIndex = 0;
            this.buttonStart.Text = "Начало конкурса";
            this.buttonStart.UseVisualStyleBackColor = true;
            this.buttonStart.Click += new System.EventHandler(this.button1_Click);
            // 
            // labelPrivetscvie
            // 
            this.labelPrivetscvie.AutoSize = true;
            this.labelPrivetscvie.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.labelPrivetscvie.Font = new System.Drawing.Font("Times New Roman", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelPrivetscvie.Location = new System.Drawing.Point(23, 9);
            this.labelPrivetscvie.Name = "labelPrivetscvie";
            this.labelPrivetscvie.Size = new System.Drawing.Size(492, 42);
            this.labelPrivetscvie.TabIndex = 1;
            this.labelPrivetscvie.Text = "Добро пожаловать на конкурс!";
            // 
            // labelRefgstration
            // 
            this.labelRefgstration.AutoSize = true;
            this.labelRefgstration.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.labelRefgstration.Font = new System.Drawing.Font("Times New Roman", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelRefgstration.Location = new System.Drawing.Point(66, 9);
            this.labelRefgstration.Name = "labelRefgstration";
            this.labelRefgstration.Size = new System.Drawing.Size(407, 42);
            this.labelRefgstration.TabIndex = 2;
            this.labelRefgstration.Text = "Зарегиструйте участника";
            this.labelRefgstration.Visible = false;
            this.labelRefgstration.Click += new System.EventHandler(this.label1_Click);
            // 
            // labelName
            // 
            this.labelName.AutoSize = true;
            this.labelName.Location = new System.Drawing.Point(213, 89);
            this.labelName.Name = "labelName";
            this.labelName.Size = new System.Drawing.Size(72, 13);
            this.labelName.TabIndex = 3;
            this.labelName.Text = "Введите имя";
            this.labelName.Visible = false;
            // 
            // textBoxName
            // 
            this.textBoxName.Location = new System.Drawing.Point(197, 105);
            this.textBoxName.Name = "textBoxName";
            this.textBoxName.Size = new System.Drawing.Size(100, 20);
            this.textBoxName.TabIndex = 4;
            this.textBoxName.Visible = false;
            // 
            // buttonName
            // 
            this.buttonName.Location = new System.Drawing.Point(170, 131);
            this.buttonName.Name = "buttonName";
            this.buttonName.Size = new System.Drawing.Size(163, 23);
            this.buttonName.TabIndex = 5;
            this.buttonName.Text = "Внести участника";
            this.buttonName.UseVisualStyleBackColor = true;
            this.buttonName.Visible = false;
            this.buttonName.Click += new System.EventHandler(this.buttonName_Click);
            // 
            // buttonShow
            // 
            this.buttonShow.BackColor = System.Drawing.Color.Transparent;
            this.buttonShow.ForeColor = System.Drawing.SystemColors.ControlText;
            this.buttonShow.Location = new System.Drawing.Point(98, 247);
            this.buttonShow.Name = "buttonShow";
            this.buttonShow.Size = new System.Drawing.Size(338, 142);
            this.buttonShow.TabIndex = 6;
            this.buttonShow.Text = "Закончить конкурс";
            this.buttonShow.UseVisualStyleBackColor = false;
            this.buttonShow.Visible = false;
            this.buttonShow.Click += new System.EventHandler(this.buttonShow_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(647, 121);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 13);
            this.label1.TabIndex = 8;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 395);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(191, 23);
            this.button1.TabIndex = 9;
            this.button1.Text = "Загрузить прошлую сессию";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Visible = false;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(546, 430);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonShow);
            this.Controls.Add(this.buttonName);
            this.Controls.Add(this.textBoxName);
            this.Controls.Add(this.labelName);
            this.Controls.Add(this.labelRefgstration);
            this.Controls.Add(this.labelPrivetscvie);
            this.Controls.Add(this.buttonStart);
            this.Name = "Form1";
            this.Text = "Конкурс";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonStart;
        private System.Windows.Forms.Label labelPrivetscvie;
        private System.Windows.Forms.Label labelRefgstration;
        private System.Windows.Forms.Label labelName;
        private System.Windows.Forms.TextBox textBoxName;
        private System.Windows.Forms.Button buttonName;
        private System.Windows.Forms.Button buttonShow;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
    }
}

